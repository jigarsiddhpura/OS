#include <stdio.h>
int main()
{
    int burstCopy[10], i, j, smallest, count = 0, time, ctr = 1, n, processId[10], arrivalTime[10], burstTime[10];
    int ganntTime[100] = {1};
    int ganntProcess[100] = {1};
    double wat = 0, tt = 0, end, turnAroundTime[10], waitingTime[10], completionTime[10];

    printf("enter the number of Processes: ");
    scanf("%d", &n);
    // n = 4;
    printf("enter process id's: ");
    for (i = 0; i < n; i++)
        scanf("%d", &processId[i]);
    // int processId[10] = {1, 2, 3, 4};
    printf("enter arrival time: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arrivalTime[i]);
    // int arrivalTime[10] = {0, 15, 30, 45};
    printf("enter burst time: ");
    for (i = 0; i < n; i++)
        scanf("%d", &burstTime[i]);
    // int burstTime[10] = {20, 25, 10, 15};
    for (i = 0; i < n; i++)
        burstCopy[i] = burstTime[i];

    burstTime[9] = 9999;
    int processPrev = 0;
    int gannLen = 0;

    for (time = 0; count != n; time++)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (arrivalTime[i] <= time && burstTime[i] < burstTime[smallest] && burstTime[i] > 0)
            {
                smallest = i;
            }
        }

        // initialising ganntProcess[] & ganntTime[]

        ganntProcess[0] = 1;
        ganntTime[0] = arrivalTime[0];

        // main code for gantt chart

        if (smallest != processPrev)
        {
            ganntProcess[ctr] = smallest + 1;
            ganntTime[ctr] = time;
            ctr++;
        }

        processPrev = smallest;
        burstTime[smallest]--;

        //

        if (burstTime[smallest] == 0)
        {
            count++;
            end = time + 1;

            completionTime[smallest] = end; 
            turnAroundTime[smallest] = end - arrivalTime[smallest];
            waitingTime[smallest] = turnAroundTime[smallest] - burstCopy[smallest];
            
            wat +=  waitingTime[smallest];
            tt +=  turnAroundTime[smallest];

            // calculating gantt chart's final completion time

            if (count == n)
            {
                ganntTime[ctr] = time + 1;
                ctr++;
            }
        }
    }

    // Printing Gantt Chart , Table & avg

    printf("Gantt Chart\n\n");
    for (int i = 0; i < ctr - 1; i++)
    {
        printf("     P%d\t", ganntProcess[i]);
    }
    printf("\n");
    for (int i = 0; i < ctr; i++)
    {
        printf("%d\t ", ganntTime[i]);
    }
    printf("\n\n");

    printf("Process\tArrival Time\tBurst Time  Completion Time  Turn Around Time\t      Waiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("  %d\t    %d\t\t   %d\t\t%lf\t%lf\t\t%lf\n", processId[i], arrivalTime[i], burstCopy[i], completionTime[i], turnAroundTime[i], waitingTime[i]);
    }

    printf("\n\nAverage waiting time = %lf\n", wat / n);
    printf("Average Turnaround time = %lf\n\n", tt / n);

    return 0;
}