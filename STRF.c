#include <stdio.h>
int main()
{
    int x[10], i, j, smallest, count = 0, time, ctr = 1, n, pid[10], a[10], b[10];
    int gp[100] = {1};
    int gid[100] = {1};
    double wat = 0, tt = 0, end, tat[10], wt[10], ct[10];

    // gid = gantt ids, gp = gantt processes

    printf("enter the number of Processes:\n");
    scanf("%d", &n);
    // n = 4;
    printf("enter process id's\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pid[i]);
    // int pid[10] = {1, 2, 3, 4};
    printf("enter arrival time\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    // int a[10] = {0, 15, 30, 45};
    printf("enter burst time\n");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);
    // int b[10] = {20, 25, 10, 15};
    for (i = 0; i < n; i++)
        x[i] = b[i];

    b[9] = 9999;
    int processPrev = 0;
    int gannLen = 0;
    for (time = 0; count != n; time++)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (a[i] <= time && b[i] < b[smallest] && b[i] > 0)
            {
                smallest = i;
            }
        }
        // printf("%d %d | ",smallest,processPrev);

        // initialising gid[] & gp[]

        gid[0] = 1;
        gp[0] = a[0];

        // main code for gantt chart

        if (smallest != processPrev)
        {
            // printf("%d - %d |",smallest+1,time);
            gid[ctr] = smallest + 1;
            gp[ctr] = time;
            ctr++;
        }
        processPrev = smallest;
        b[smallest]--;

        //

        if (b[smallest] == 0)
        {
            count++;
            end = time + 1;
            wat = wat + end - a[smallest] - x[smallest];
            tt = tt + end - a[smallest];

            tat[smallest] = end - a[smallest];
            wt[smallest] = end - a[smallest] - x[smallest];

            // calculating gantt chart's final completion time

            if (count == n)
            {
                gp[ctr] = time + 1;
                ctr++;
            }
        }
    }

    // Calculating completion time

    for (int i = 0; i < n; i++)
    {
        ct[i] = tat[i] + a[i];
    }

    // Printing Gantt Chart , Table & avg

    printf("Gantt Chart\n\n");
    for (int i = 0; i < ctr - 1; i++)
    {
        printf("     P%d\t", gid[i]);
    }
    printf("\n");
    for (int i = 0; i < ctr; i++)
    {
        printf("%d\t ", gp[i]);
    }
    printf("\n\n");

    printf("Process\tArrival Time\tBurst Time  Completion Time  Turn Around Time\t      Waiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("  %d\t    %d\t\t   %d\t\t%lf\t%lf\t\t%lf\n", pid[i], a[i], x[i], ct[i], tat[i], wt[i]);
    }

    printf("\n\nAverage waiting time = %lf\n", wat / n);
    printf("Average Turnaround time = %lf\n\n", tt / n);

    return 0;
}