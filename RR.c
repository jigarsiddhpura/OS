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
    int burstTimeCopy[10], i, j, timeQuantum, processId, highestArrivalTime = 0, count = 0, time = 0, ctr = 0, n, ganLen = 1, index = 0;
    int ganntTime[100] = {1};
    int ganntProcess[100] = {-1};
    double wat = 0, tt = 0, end, turnAroundTime[10], waiting_t[10], completionTime[10];

    // int burstTime[10] = {4, 5, 2, 1, 6, 3};
    // int arrivalTime[10] = {0, 1, 2, 3, 4, 6};
    // int allProcessId[10] = {1, 2, 3, 4, 5, 6};
    // n = 6;

    int allProcessId[10],arrivalTime[10],burstTime[10];
    printf("Enter number of processess: ");
    scanf("%d", &n);
    printf("enter process id's: ");
    for (i = 0; i < n; i++)
        scanf("%d", &allProcessId[i]);
    printf("enter arrival time: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arrivalTime[i]);
    printf("enter burst time: ");
    for (i = 0; i < n; i++)
        scanf("%d", &burstTime[i]);

    for (int i = 0; i < n; i++)
    {
        burstTimeCopy[i] = burstTime[i];
    }
    timeQuantum = 2;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", burstTime[i]);
    }

    // initialising
    enque(arrivalTime[0]);
    ganntTime[0] = arrivalTime[0];

    while (count != n)
    {
        processId = queue[front];

        for (i = 0; i < n; i++)
        {
            if (arrivalTime[i] == processId)
            {
                index = i;
            }
        }

        ganntProcess[ctr] = allProcessId[index];

        if (burstTime[index] <= timeQuantum)
        {
            time += burstTime[index];
            burstTime[index] = 0;
            count++;
            for (i = 0; i < n; i++)
            {
                if (i > index && arrivalTime[i] <= time && burstTime[i] != 0 && arrivalTime[i] > highestArrivalTime)
                {
                    enque(arrivalTime[i]);
                    highestArrivalTime = arrivalTime[i];
                }
            }
            int p = deque();
            ganLen--;
            completionTime[index] = time;
            // printf("ct = %lf ",completionTime[processId]);
            turnAroundTime[index] = completionTime[index] - arrivalTime[index];
            waiting_t[index] = turnAroundTime[index] - burstTimeCopy[index];

            wat = wat + waiting_t[index];
            tt = tt + turnAroundTime[index];
        }
        else
        {
            burstTime[index] -= timeQuantum;
            time += timeQuantum;
            for (i = 0; i < n; i++)
            {
                if (i > index && arrivalTime[i] <= time && burstTime[i] != 0 && arrivalTime[i] > highestArrivalTime)
                {
                    enque(arrivalTime[i]);
                    highestArrivalTime = arrivalTime[i];
                }
            }
            int p = deque();
            enque(p);
        }
        ganntTime[ctr + 1] = time;
        ctr++;
    }

    //  Printing Gantt Chart , Table & avg

    printf("\nGantt Chart\n\n");
    for (int i = 0; i < ctr; i++)
    {
        printf("     P%d\t", ganntProcess[i]);
    }
    printf("\n");
    for (int i = 0; i < ctr + 1; i++)
    {
        printf("%d\t ", ganntTime[i]);
    }
    printf("\n\n");

    printf("processId Arrival Time\tBurst Time  Completion Time  Turn Around Time\t  Waiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("  %d\t    %d\t\t   %d\t\t%lf\t%lf\t    %lf\n", allProcessId[i], arrivalTime[i], burstTimeCopy[i], completionTime[i], turnAroundTime[i], waiting_t[i]);
    }

    printf("\n\nAverage waiting time = %lf\n", wat / n);
    printf("Average Turnaround time = %lf\n\n", tt / n);
}