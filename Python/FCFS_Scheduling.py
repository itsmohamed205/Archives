def get_positive_integer(prompt):
    while True:
        try:
            value = int(input(prompt))
            if value < 0:
                raise ValueError("The value must be a non-negative integer.")
            return value
        except ValueError as e:
            print(e)

def get_process_data(num_processes):
    processes = []
    for i in range(num_processes):
        print(f"\nEnter details for process {i + 1}:")
        arrival_time = get_positive_integer("Arrival Time: ")
        burst_time = get_positive_integer("Burst Time: ")
        processes.append((i + 1, arrival_time, burst_time))
    return processes

def calculate_times(processes):
    num_processes = len(processes)
    processes.sort(key=lambda x: x[1])

    waiting_time = [0] * num_processes
    turnaround_time = [0] * num_processes
    response_time = [0] * num_processes

    current_time = 0
    for i in range(num_processes):
        pid, arrival_time, burst_time = processes[i]
        if current_time < arrival_time:
            current_time = arrival_time
        response_time[i] = current_time - arrival_time
        waiting_time[i] = current_time - arrival_time
        current_time += burst_time
        turnaround_time[i] = current_time - arrival_time

    return waiting_time, turnaround_time, response_time

def calculate_averages(times):
    num_processes = len(times[0])
    avg_waiting_time = sum(times[0]) / num_processes
    avg_turnaround_time = sum(times[1]) / num_processes
    avg_response_time = sum(times[2]) / num_processes
    return avg_waiting_time, avg_turnaround_time, avg_response_time

def display_results(processes, times, averages):
    print("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tResponse Time")
    for i in range(len(processes)):
        pid, arrival_time, burst_time = processes[i]
        print(f"{pid}\t{arrival_time}\t\t{burst_time}\t\t{times[0][i]}\t\t{times[1][i]}\t\t{times[2][i]}")

    print("\nAverage Waiting Time:", averages[0])
    print("Average Turnaround Time:", averages[1])
    print("Average Response Time:", averages[2])

def main():
    num_processes = get_positive_integer("Enter the number of processes: ")
    processes = get_process_data(num_processes)
    times = calculate_times(processes)
    averages = calculate_averages(times)
    display_results(processes, times, averages)

if __name__ == "__main__":
    main()