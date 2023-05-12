#include <stdio.h>
#include <stdbool.h>

// Define a struct to represent a process
typedef struct
{
    int process_id;      // unique identifier for the process
    int arrival_time;    // time at which the process arrives
    int burst_time;      // time required by the process to complete
    int completion_time; // time at which the process completes
    bool completed;      // flag to indicate if the process has completed
} process_t;

// Function to find the index of the shortest job
int find_shortest_job(process_t processes[], int num_processes, int current_time)
{
    int i;
    int shortest_job_index = -1;      // initialize to invalid index
    int shortest_job_burst_time = -1; // initialize to invalid burst time

    // Iterate through all processes
    for (i = 0; i < num_processes; i++)
    {
        // If the process has arrived and not completed, and its burst time is shorter than the current shortest job
        if (processes[i].arrival_time <= current_time && !processes[i].completed && (shortest_job_burst_time == -1 || processes[i].burst_time < shortest_job_burst_time))
        {
            // Set the shortest job index and burst time to this process
            shortest_job_index = i;
            shortest_job_burst_time = processes[i].burst_time;
        }
    }

    return shortest_job_index;
}

// Function to perform the SJF scheduling algorithm
void sjf_scheduler(process_t processes[], int num_processes)
{
    int current_time = processes[0].arrival_time; // ⭐⭐⭐
    int i;

    // Iterate until all processes have completed
    while (true)
    {
        // Find the index of the shortest job
        int shortest_job_index = find_shortest_job(processes, num_processes, current_time);

        // If no job was found, break out of the loop
        if (shortest_job_index == -1)
        {
            break;
        }

        // Set the completion time for the process
        processes[shortest_job_index].completion_time = current_time + processes[shortest_job_index].burst_time;
        // Mark the process as completed
        processes[shortest_job_index].completed = true;

        // Update the current time to be the completion time of the process
        current_time = processes[shortest_job_index].completion_time;
    }
}

int main()
{
    int i, num_processes;

    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    // Declare an array of processes
    process_t processes[num_processes];

    // Get the arrival time and burst time for each process
    for (i = 0; i < num_processes; i++)
    {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].process_id = i + 1;
        processes[i].completed = false;
    }

    // Perform the SJF scheduling algorithm
    sjf_scheduler(processes, num_processes);

    // Print the completion time for each process
    printf("\nCompletion times:\n");
    for (i = 0; i < num_processes; i++)
    {
        printf("Process %d: %d\n", processes[i].process_id, processes[i].completion_time);
    }

    return 0;
}
