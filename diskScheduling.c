#include <stdio.h>
#include <stdlib.h>

void printTrackMovements(int track_no[], int n)
{
    int time = 0;
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            printf("->%d", track_no[i]);
            time += abs(track_no[i] - track_no[i - 1]);
        }
        else
        {
            printf("%d", track_no[i]);
        }
    }
    printf("\nTotal number of track movements : %d", time);
    printf("\nAverage seek time : %d\n\n", time / n);
}

void fcfs(int sortedQ[], int trackCount, int h, int n)
{
    int th = 0, tm[100], j = 0;
    tm[j++] = h;
    for (int i = 0; i < n; i++)
    {
        tm[j++] = sortedQ[i];
    }
    printTrackMovements(tm, j);
}

int allVisited(int arr[], int n)
{
    int visited = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            visited += 1;
        }
    }

    if (visited == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void SSTF(int sortedQ[], int trackCount, int head, int n, int visited[])
{
    int j = 0, trackMovements[100], indexOfNearestTrack;
    trackMovements[j++] = head;
    while (allVisited(visited, n) == 0)
    {
        int min = 999999999, NearestTrack;
        for (int i = 0; i < n; i++)
        {
            if (abs((sortedQ[i]) - head) < min && visited[i] == 0)
            {
                min = abs((sortedQ[i]) - head);
                indexOfNearestTrack = i;
                NearestTrack = sortedQ[i];
            }
        }
        head = NearestTrack;
        visited[indexOfNearestTrack] = 1;
        trackMovements[j++] = NearestTrack;
    }

    printTrackMovements(trackMovements, j);
}

void SCAN(int sortedQ[], int trackCount, int h, int n)
{
    int tm[200], j = 0, tb[200], b = 0;
    tm[j++] = h;
    for (int i = 0; i < n; i++)
    {
        if (sortedQ[i] >= h)
        {
            tm[j++] = sortedQ[i];
        }
        else
        {
            tb[b++] = sortedQ[i];
        }
    }
    tm[j++] = trackCount - 1;
    for (int i = b - 1; i >= 0; i--)
    {
        tm[j++] = tb[i];
    }
    printTrackMovements(tm, j);
}

void CSCAN(int sortedQ[], int trackCount, int h, int n)
{
    int tm[200], j = 0, tb[200], b = 0;
    tm[j++] = h;
    for (int i = 0; i < n; i++)
    {
        if (sortedQ[i] >= h)
        {
            tm[j++] = sortedQ[i];
        }
        else
        {
            tb[b++] = sortedQ[i];
        }
    }
    tm[j++] = trackCount - 1;
    tm[j++] = 0;
    for (int i = 0; i < b; i++)
    {
        tm[j++] = tb[i];
    }
    printTrackMovements(tm, j);
}

void LOOK(int sortedQ[], int trackCount, int h, int n)
{
    int tm[200], j = 0, tb[200], b = 0;
    tm[j++] = h;
    for (int i = 0; i < n; i++)
    {
        if (sortedQ[i] >= h)
        {
            tm[j++] = sortedQ[i];
        }
        else
        {
            tb[b++] = sortedQ[i];
        }
    }
    for (int i = b - 1; i >= 0; i--)
    {
        tm[j++] = tb[i];
    }
    printTrackMovements(tm, j);
}

int *sort(int queue[], int qsize)
{
    int t;
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
    return queue;
}

void main()
{
    int queue[] = {82, 170, 43, 140, 24, 16, 190};
    int qsize = sizeof(queue) / sizeof(queue[0]);
    int visited[100] = {0};

    int trackCount = 200;
    int head = 50, t;
    printf("Request : ");

    printf("FCFS : ");
    fcfs(queue, trackCount, head, qsize);

    int *sortedQueue = sort(queue,qsize);

    printf("SSTF : ");
    SSTF(sortedQueue, trackCount, head, qsize, visited);

    printf("SCAN : ");
    SCAN(sortedQueue, trackCount, head, qsize);

    printf("CSCAN :");
    CSCAN(sortedQueue, trackCount, head, qsize);

    printf("LOOK :");
    LOOK(sortedQueue, trackCount, head, qsize);
}