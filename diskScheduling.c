#include <stdio.h>
#include <stdlib.h>
void printtm(int t[], int n)
{
    int tm = 0;
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            printf("->%d", t[i]);
            tm = tm + abs(t[i] - t[i - 1]);
        }
        else
        {
            printf("%d", t[i]);
        }
    }
    printf("\nTotal number of track movements : %d", tm);
    printf("\nAverage seek time : %d\n\n", tm/n);
}
void fcfs(int q[], int tn, int h, int n)
{
    int th = 0, tm[100], j = 0;
    tm[j++] = h;
    for (int i = 0; i < n; i++)
    {
        tm[j++] = q[i];
    }
    printtm(tm, j);
}


int allvist(int a[], int n)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==1){c=c+1;}
    }

    if(c==n){return 1;}
    else{return 0;}
}
void sstf(int q[], int tn, int h, int n, int vis[])
{
    int j=0, res[100],pos;
    // printf("%d->",h);
    res[j++]=h;
    while(allvist(vis,n)==0)
    {
        int min = 999999999,temp;
        for(int i=0;i<n;i++)
        {
            if(abs((q[i])-h)<min && vis[i]==0)
            {
                min = abs((q[i])-h);
                // printf("(min : %d)",min);
                pos=i;
                temp=q[i];
            }
        }
        h=temp;
        vis[pos]=1;
        res[j++]=temp;
        // printf(" %d ",res[j-1]);
    }
    
    printtm(res,j);
}
void scan(int q[], int tn, int h, int n)
{
    int tm[200], j = 0, tb[200], b = 0;
    tm[j++] = h;
    for (int i = 0; i < n; i++)
    {
        if (q[i] >= h)
        {
            tm[j++] = q[i];
        }
        else
        {
            tb[b++] = q[i];
        }
    }
    tm[j++] = tn - 1;
    for (int i = b - 1; i >= 0; i--)
    {
        tm[j++] = tb[i];
    }
    printtm(tm, j);
}
void look(int q[], int tn, int h, int n)
{
    int tm[200], j = 0, tb[200], b = 0;
    tm[j++] = h;
    for (int i = 0; i < n; i++)
    {
        if (q[i] >= h)
        {
            tm[j++] = q[i];
        }
        else
        {
            tb[b++] = q[i];
        }
    }
    for (int i = b - 1; i >= 0; i--)
    {
        tm[j++] = tb[i];
    }
    printtm(tm, j);
}
void cscan(int q[], int tn, int h, int n)
{
    int tm[200], j = 0, tb[200], b = 0;
    tm[j++] = h;
    for (int i = 0; i < n; i++)
    {
        if (q[i] >= h)
        {
            tm[j++] = q[i];
        }
        else
        {
            tb[b++] = q[i];
        }
    }
    tm[j++] = tn - 1;
    tm[j++] = 0;
    for (int i = 0; i < b; i++)
    {
        tm[j++] = tb[i];
    }
    printtm(tm, j);
}
void main()
{
    int queue[] = {82,170,43,140,24,16,190};
    int qsize = sizeof(queue) / sizeof(queue[0]);
    int vis[100];
    for (int i=0;i<qsize;i++){vis[i]=0;}
    // printf("%d",vis[qsize+1]);
    int trackno = 200;
    int head = 50, t;
    printf("Request : ");
    for(int i =0;i<qsize;i++){printf("%d, ",queue[i]);}
    printf("\nHead : %d\nTotal Tracks : %d \nScheduling algorithms -> \n",head,trackno);
    printf("FCFS : ");
    fcfs(queue, trackno, head, qsize);
    for (int i = 0; i < qsize - 1; i++)
    {
        for (int j = 0; j < qsize - 1; j++)
        {
            if (queue[j] > queue[j + 1])
            {
                t = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = t;
            }
        }
    }
    printf("SSTF : ");
    sstf(queue, trackno, head, qsize, vis);
    printf("SCAN : ");
    scan(queue, trackno, head, qsize);
    printf("CSCAN :");
    cscan(queue, trackno, head, qsize);
    printf("LOOK :");
    look(queue, trackno, head, qsize);
}