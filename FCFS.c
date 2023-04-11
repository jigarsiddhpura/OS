#include <stdio.h>
#include <stdlib.h>

double mean(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return (double)sum / (double)n;
}

int main()
{
    // int pid[] = {1, 2, 3, 4, 5};
    // int arrTime[] = {0, 1, 2, 3, 4};
    // int burstTime[] = {4, 3, 1, 2, 5};
    // int n = sizeof(arrTime) / sizeof(arrTime[0]);

    int i,n, pid[10],arrTime[10],burstTime[10];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("enter process id's: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pid[i]);
    printf("enter arrival time: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arrTime[i]);
    printf("enter burst time: ");
    for (i = 0; i < n; i++)
        scanf("%d", &burstTime[i]);

    int ganttC[n + 1], ct[n];
    ganttC[0] = 0;
    int dict[n][2];
    int compTime = burstTime[0];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        dict[i][0] = arrTime[i];
        dict[i][1] = burstTime[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (dict[i][0] > dict[j][0])
            {
                int temp1 = dict[i][0];
                int temp2 = dict[i][1];
                dict[i][0] = dict[j][0];
                dict[i][1] = dict[j][1];
                dict[j][0] = temp1;
                dict[j][1] = temp2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        ganttC[i + 1] = sum + dict[i][1];
        sum += dict[i][1];
    }

    int turnAroundTime[n];
    for (int i = 0; i < n; i++)
    {
        turnAroundTime[i] = ganttC[i + 1] - arrTime[i];
    }

    int weightingTime[n];
    for (int i = 0; i < n; i++)
    {
        weightingTime[i] = turnAroundTime[i] - burstTime[i];
    }

    double avgWT = mean(weightingTime, n);
    double avgTAT = mean(turnAroundTime, n);

    for (int i = 0; i < n; i++)
    {
        ct[i] = turnAroundTime[i] + arrTime[i];
    }

    //  Printing Gantt Chart , Table & avg

    printf("processId Arrival Time\tBurst Time  Completion Time  Turn Around Time\t  Waiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("  %d\t    %d\t\t   %d\t\t%d\t\t%d\t\t\t%d\n", pid[i], arrTime[i], burstTime[i], ct[i], turnAroundTime[i], weightingTime[i]);
    }

    printf("\n\nAverage waiting time = %lf\n", avgWT);
    printf("Average Turnaround time = %lf\n\n", avgTAT);
    return 0;
}
