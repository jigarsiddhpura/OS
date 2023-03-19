\tBurst Time  Completion Time  Turn Around Time\t      Waiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("  %d\t    %d\t\t   %d\t\t%lf\t%lf\t\t%lf\n", pid[i], a[i], x[i], ct[i], tat[i], wt[i]);
    }

    printf("\n\nAverage waiting time = %lf\n", wat / n);
    printf("Average Turnaround time = %lf\n\n", tt / n);