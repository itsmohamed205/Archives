from flask import Flask, render_template, request, send_file, redirect, url_for
import pandas as pd
import os
from io import BytesIO
import requests
from google.oauth2 import service_account
from googleapiclient.discovery import build

app = Flask(__name__)
UPLOAD_FOLDER = 'uploads'
os.makedirs(UPLOAD_FOLDER, exist_ok=True)

# Load credentials from the JSON file
SERVICE_ACCOUNT_FILE = 'token.json'
SCOPES = ['https://www.googleapis.com/auth/spreadsheets.readonly']
credentials = service_account.Credentials.from_service_account_file(
    SERVICE_ACCOUNT_FILE, scopes=SCOPES)

def fetch_google_sheet(spreadsheet_id, range_name):
    """
    Fetches data from a Google Spreadsheet and returns a pandas DataFrame.
    """
    service = build('sheets', 'v4', credentials=credentials)
    sheet = service.spreadsheets()
    result = sheet.values().get(spreadsheetId=spreadsheet_id, range=range_name).execute()
    values = result.get('values', [])
    print("Fetched data:", values)

    # Check if the data has the expected structure
    if not values:
        raise ValueError("No data found in the specified range.")
    if len(values) < 2:
        raise ValueError("Insufficient data: Expected at least one header row and one data row.")
    return pd.DataFrame(values[1:], columns=values[0])
    

def filter_and_remove_matches(df_online, df_local, column_name):
    """
    Compares two fields between a local file and an online Google Spreadsheet.
    If a match is found, removes it from the local sheet and returns the modified DataFrame.
    """
    print("Online DataFrame:")
    print(df_online)
    print("Local DataFrame:")
    print(df_local)

    online_set = set(df_online[column_name].dropna().astype(str).str.strip())
    local_set = set(df_local[column_name].dropna().astype(str).str.strip())
    
    print("Online Set:", online_set)
    print("Local Set:", local_set)

    df_local_filtered = df_local[~df_local[column_name].astype(str).str.strip().isin(online_set)]
    
    print("Filtered Local DataFrame:")
    print(df_local_filtered)

    return df_local_filtered

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        try:
            local_file = request.files['local_file']
            google_sheet_url = request.form['google_sheet_url']
            column_name = request.form['column_name']

            local_file_path = os.path.join(UPLOAD_FOLDER, local_file.filename)
            local_file.save(local_file_path)
            df_local = pd.read_excel(local_file_path)

            # Extract spreadsheet ID and range from the URL
            spreadsheet_id = google_sheet_url.split('/d/')[1].split('/')[0]
            range_name = 'Sheet1'  # Adjust as needed

            df_online = fetch_google_sheet(spreadsheet_id, range_name)

            # Filter and remove matches
            df_local_filtered = filter_and_remove_matches(df_online, df_local, column_name)

            # Save the modified local file
            modified_local_path = os.path.join(UPLOAD_FOLDER, 'modified_local.xlsx')
            df_local_filtered.to_excel(modified_local_path, index=False)

            return render_template("index.html", success=True, 
                                   modified_local_download=url_for('download_file', filename='modified_local.xlsx'))
        except Exception as e:
            return render_template("index.html", error=str(e))
    return render_template("index.html")

@app.route('/download/<filename>')
def download_file(filename):
    return send_file(os.path.join(UPLOAD_FOLDER, filename))

if __name__ == "__main__":
    app.run(debug=True)
