#include <stdio.h>

// Define a struct to represent a process
typedef struct {
    int process_id;     // unique identifier for the process
    int arrival_time;   // time at which the process arrives
    int burst_time;     // time required by the process to complete
    int completion_time;// time at which the process completes
} process_t;

// Function to perform the FCFS scheduling algorithm
void fcfs_scheduler(process_t processes[], int num_processes) {
    int current_time = 0;   // current time
    int i;

    // Iterate through all processes
    for (i = 0; i < num_processes; i++) {
        // If the process has not yet arrived, wait for it
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        // Set the completion time for the process
        processes[i].completion_time = current_time + processes[i].burst_time;

        // Update the current time to be the completion time of the process
        current_time = processes[i].completion_time;
    }
}

int main() {
    int i, num_processes;

    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    // Declare an array of processes
    process_t processes[num_processes];

    // Get the arrival time and burst time for each process
    for (i = 0; i < num_processes; i++) {
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].process_id = i+1;
    }

    // Perform the FCFS scheduling algorithm
    fcfs_scheduler(processes, num_processes);

    // Print the completion time for each process
    printf("\nCompletion times:\n");
    for (i = 0; i < num_processes; i++) {
        printf("Process %d: %d\n", processes[i].process_id, processes[i].completion_time);
    }

    return 0;
}
