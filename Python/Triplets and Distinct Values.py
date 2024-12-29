import sys  # Import the sys module to access command-line arguments

showValues = False  # Flag to determine whether to show values or not
inputArray = []  # Initialize an empty list to store input values


def distinct_values(array, showValues, chunk_size=100000):
    seen = set()  # Create an empty set to store unique values
    count = 0  # Initialize a counter for distinct values

    # Process the array in chunks
    for start in range(0, len(array), chunk_size):
        end = min(start + chunk_size, len(array))
        chunk = array[start:end]

        for value in chunk:  # Iterate over each value in the chunk
            if value not in seen:  # Check if the value is not already in the set
                seen.add(value)  # Add the value to the set
                count += 1  # Increment the counter for distinct values
                if showValues:  # If showValues flag is True
                    print(value, end="\t")  # Print the value followed by a tab
                if count % 8 == 0: print("\n")  # For aesthetic reasons
    print()  # Print a newline character
    return count  # Return the count of distinct values


def checkTriples(arr, showValues, start=0, end=None):
    if end is None:  # If end is not provided, set it to the length of the array
        end = len(arr)
    count = 0  # Initialize a counter for valid triplets

    for i in range(start, end):  # Iterate over the array from start to end
        for j in range(i + 1, end):  # Iterate over the array from i+1 to end
            for k in range(
                j + 1, end
            ):  # Iterate over the array from j+1 to end
                # Ensure that the same number isn't used twice
                if arr[i] != arr[j] and arr[j] != arr[k] and arr[i] != arr[k]:
                    # Check if the triplet is valid
                    if (
                        arr[i] + arr[j] > arr[k]
                        and arr[i] + arr[k] > arr[j]
                        and arr[j] + arr[k] > arr[i]
                    ):
                        count += 1  # Increment the counter for valid triplets
                        if showValues:  # If showValues flag is True
                            print(
                                f"({arr[i]}, {arr[j]}, {arr[k]})", end="\t"
                            )  # Print the triplet followed by a tab
                            if count % 3 == 0: print("\n") # For aestehtic reasons
    return count  # Return the count of valid triplets


# ONLY USED BY THE TRIPLETS FUNCTION
def insertionSort(array):
    for i in range(
        1, len(array)
    ):  # Iterate over the array starting from the second element
        key = array[i]  # Store the current element as the key
        j = i - 1  # Initialize j to the index before i
        while (
            j >= 0 and array[j] > key
        ):  # Shift elements of the array that are greater than the key
            array[j + 1] = array[
                j
            ]  # Move the element one position to the right
            j -= 1  # Decrement j
        array[j + 1] = key  # Place the key in its correct position


if __name__ == "__main__":
    # Checking for the -i and -c flags and their functions
    for i in range(len(sys.argv)):  # Iterate over the command-line arguments
        if sys.argv[i] == "-i":  # If the -i flag is found
            showValues = True  # Set the showValues flag to True
        elif sys.argv[i] == "-a":  # If the -a flag is found
            inputString = (
                sys.argv[i + 1] if i + 1 < len(sys.argv) else ""
            )  # Get the input string
            inputArray = inputString.split(
                ","
            )  # Split the input string into a list of values
            inputArray = [
                int(x) for x in inputArray if x.strip().isdigit()
            ]  # Convert the list to integers
if len(inputArray) == 0:  # If no input values are provided
        print(
        "Please provide a list of integers as command-line arguments, use -a flag"
        )  # Print a message indicating no input values
        sys.exit(1)  # Exit the program
    # Choice of the user to choose which function to use: 1- Triples 2- Distinct Values
choice = int(
        input(
            "Choose which function you willing to use:\n1- Triples\n2- Distinct Values\nInput: "
        )
    )  # Get the user's choice
if choice == 1:  # If the user chooses Triples
        confirm = input(
            "Do you want a custom start and end index? (y/n): "
        )  # Ask if the user wants custom indices
        if confirm.lower() == "y":  # If the user confirms
            start = int(input("Enter the start index: "))  # Get the start index
            end = int(input("Enter the end index: "))  # Get the end index
        else:
            start = 0  # Default start index
            end = None  # Default end index

    # Print the array after being sorted
insertionSort(inputArray)  # Sort the input array
print("Full Array: [", end="")  # Print the opening bracket
print(", ".join(map(str, inputArray)), end="]\n")  # Print the sorted array

if choice == 1 and (
        start != 0 and end is not None
    ):  # If the user chose Triples and custom indices are not provided
        print(
            "Custom array index: [", end=""
        )  # Print the opening bracket for the custom array
        print(
            ", ".join(map(str, inputArray[start:end])), end="]\n"
        )  # Print the custom array
print("--------------------------------")  # Print a separator

if choice == 1:  # If the user chose Triples
        insertionSort(inputArray)  # Sort the input array
        output = checkTriples(
            inputArray, showValues, start, end
        )  # Get the number of valid triplets
else:  # If the user chose Distinct Values
        output = distinct_values(
            inputArray, showValues
        )  # Get the number of distinct values

if output < 1:  # If no valid triplets or distinct values are found
        print(
            f"No {'triples' if choice == 1 else 'distinct values'} found"
        )  # Print a message indicating no results
else:  # If valid triplets or distinct values are found
        print(
            f"\n- The number of {'triples' if choice == 1 else 'distinct values'} found: {output}"
        )  # Print the number of results
