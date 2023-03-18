#include <stdio.h>
#include <stdlib.h>

int rear = -1, front = -1,queue[100],max=20;

void enque(int val){
    if(rear == max-1){
        printf("Queue is full ");
        exit;
    }
    else if(front==-1){
        front = 0;
    }
    rear ++;
    queue[rear] = val;
    
}

int deque(){
    int val = queue[front];
    printf("deque = %d, ",val+1);
    if(front == -1){
        printf("Queue underflow ");
        exit;
    }
    else if(front == rear ) {
        front = rear = -1;
    }
    else{
        front++ ;
    }
    return val;
}
int main()
{
    int x[10], i, j,tq,processId, highest = 0, count = 0, time = 0, ctr = 1, n,ganLen = 1,index=0;
    int gp[100] = {1};
    int gid[100] = {1};
    double wat = 0, tt = 0, end, tat[10], wt[10], ct[10];

    int b[10] = {4,5,2,1,6,3};
    int a[10] = {0,1,2,3,4,6};
    int pid[10] = {1, 2, 3, 4,5,6};
    for (i = 0; i < n; i++)
        x[i] = b[i];
    n = 6;
    tq = 2;
    
    // initialising 
    enque(a[0]);
    gid[0] = 1;
    gp[0] = a[0];

    while (count!=n)
    {
        gid[ctr] = queue[front];
        processId = queue[front];

        if(b[processId]<=tq){
            printf("in if\n");
            time = time + b[processId];
            b[processId] = 0;
            count++;
            printf("count = %d\n",count);
            for ( i = 0; i < n; i++)
            {
                if(a[i]>processId && a[i]<=time && b[i]!=0 && a[i]>highest){
                    enque(a[i]);
                    // enque(pid[i]);
                    // index = pid[i] - 1;
                    highest = a[i];
                    // ganLen++;
                }
            }
            int p = deque();
            ganLen--;
            ct[processId] = time;
            tat[processId] = ct[processId] - a[processId];
            wt[processId] = tat[processId] - x[processId];

            wat = wat + wt[processId];
            tt = tt + tat[processId];
        }
        else{
            printf("in else\n");
            b[processId] = b[processId] - tq;
            time = time + tq;
            for ( i = 0; i < n; i++)
            {
                if(a[i]>processId && a[i]<=time && b[i]!=0 && a[i]>highest){
                    enque(a[i]);
                    // enque(pid[i]);
                    // index = pid[i] - 1;
                    highest = a[i];
                    // ganLen++;
                }
            }
            int p = deque();
            enque(p);
        }
            //  processId + 1 = Process no.
    printf("%d %d time = %d\n",processId+1,b[processId],time);
    // printf("%d %d time = %d\n",processId,b[processId-1],time);
    for (int i = front; i <= rear; i++)
    {
        printf("P%d\t", queue[i]+1);
        // printf("P%d\t", queue[i]);
    }
    printf("\n");
    }


    //  Printing Gantt Chart , Table & avg

    // printf("Gantt Chart\n\n");
    // for (int i = 0; i < ctr - 1; i++)
    // {
    //     printf("     P%d\t", gid[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < ctr; i++)
    // {
    //     printf("%d\t ", gp[i]);
    // }
    // printf("\n\n");

    // printf("processId\tArrival Time\tBurst Time  Completion Time  Turn Around Time\t      Waiting Time\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("  %d\t    %d\t\t   %d\t\t%lf\t%lf\t\t%lf\n", pid[i], a[i], x[i], ct[i], tat[i], wt[i]);
    // }

    // printf("\n\nAverage waiting time = %lf\n", wat / n);
    // printf("Average Turnaround time = %lf\n\n", tt / n);



}