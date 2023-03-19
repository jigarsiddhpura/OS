#include <stdio.h>
#include <stdlib.h>

int rear = -1, front = -1, queue[100], max = 20;

void enque(int val)
{
    if (rear == max - 1)
    {
        printf("Queue is full ");
        exit;
    }
    else if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = val;
}

int deque()
{
    int val = queue[front];
    // printf("deque = %d, ",val+1);
    if (front == -1)
    {
        printf("Queue underflow ");
        exit;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    return val;
}
int main()
{
    int x[10], i, j, tq, processId, highest = 0, count = 0, time = 0, ctr = 0, n, ganLen = 1, index = 0;
    int gp[100] = {1};
    int gid[100] = {-1};
    double wat = 0, tt = 0, end, tat[10], wt[10], ct[10];

    int b[10] = {4, 5, 2, 1, 6, 3};
    int a[10] = {0, 1, 2, 3, 4, 6};
    int pid[10] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < n; i++){
        x[i] = b[i];
    }
    n = 6;
    tq = 2;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }


    // initialising
    enque(a[0]);
    gp[0] = a[0];
    while (count != n)
    {
        processId = queue[front];

        for (i = 0; i < n; i++)
        {
            if (a[i] == processId)
            {
                index = i;
            }
        }

        gid[ctr] = pid[index];

        if (b[index] <= tq)
        {
            time = time + b[index];
            b[index] = 0;
            count++;
            for (i = 0; i < n; i++)
            {
                if (a[i] > index && a[i] <= time && b[i] != 0 && a[i] > highest)
                {
                    enque(a[i]);
                    highest = a[i];
                }
            }
            int p = deque();
            ganLen--;
            ct[index] = time;
            // printf("ct = %lf ",ct[processId]);
            tat[index] = ct[index] - a[index];
            wt[index] = tat[index] - x[index];

            wat = wat + wt[index];
            tt = tt + tat[index];
        }
        else
        {
            b[index] = b[index] - tq;
            time = time + tq;
            for (i = 0; i < n; i++)
            {
                if (a[i] > index && a[i] <= time && b[i] != 0 && a[i] > highest)
                {
                    enque(a[i]);
                    highest = a[i];
                }
            }
            int p = deque();
            enque(p);
        }
        gp[ctr+1] = time;
        ctr++;
    }


    //  Printing Gantt Chart , Table & avg

    printf("\nGantt Chart\n\n");
    for (int i = 0; i < ctr; i++)
    {
        printf("     P%d\t", gid[i]);
    }
    printf("\n");
    for (int i = 0; i < ctr+1; i++)
    {
        printf("%d\t ", gp[i]);
    }
    printf("\n\n");

    printf("processId Arrival Time\tBurst Time  Completion Time  Turn Around Time\t  Waiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("  %d\t    %d\t\t   %d\t\t%lf\t%lf\t    %lf\n", pid[i], a[i], x[i], ct[i], tat[i], wt[i]);
    }

    printf("\n\nAverage waiting time = %lf\n", wat / n);
    printf("Average Turnaround time = %lf\n\n", tt / n);
}