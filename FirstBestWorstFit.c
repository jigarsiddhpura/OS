#include <stdio.h>

int bsize[20], flag[20]={0};

int findMax(int arr[], int flag[])
{
    int max = -1;
    int index = -1;
    for (int i = 0; i < 20; i++)
    {
        if (arr[i] > max && flag[i] == 0)
        {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

void main()
{
    int i, j, bno, pno, psize[20], allocation[20]={-1}, allocationType;
    printf("Enter the no. of blocks: ");
    scanf("%d", &bno);
    printf("Enter the size of each memory block: \n");
    for (int i = 0; i < bno; i++)
    {
        scanf("%d", &bsize[i]);
    }
    printf("Enter the no. of processes: ");
    scanf("%d", &pno);
    printf("Enter the size of each process: \n");
    for (int i = 0; i < pno; i++)
    {
        scanf("%d", &psize[i]);
    }
    printf("Enter 0 for First Fit, 1 for Best Fit, 2 for Worst Fit: \n");
    scanf("%d", &allocationType);

    switch (allocationType)
    {

    case 0:
        // first fit
        for (int i = 0; i < pno; i++)
        {
            for (int j = 0; j < bno; j++)
            {
                if (bsize[j] >= psize[i] && flag[j] == 0)
                {
                    allocation[j] = i; // ???????????
                    flag[j] = 1;
                    break;
                }
            }
        }
        break;

    case 1:
        // Best fit
        for (i = 0; i < pno; i++)
        {
            int indexPlaced = -1;
            for (j = 0; j < bno; j++)
            {
                if (bsize[j] >= psize[i] && flag[j] == 0)
                {
                    if (indexPlaced == -1)
                        indexPlaced = j;
                    else if (bsize[j] < bsize[indexPlaced])
                        indexPlaced = j;
                }
            }
            if (indexPlaced != -1)
            {
                allocation[i] = indexPlaced;
                flag[indexPlaced] = 1;
            }
        }
        break;

    case 2:
        // worst fit
        for (int i = 0; i < pno; i++)
        {
            int indexPlaced = -1;
            int indexOfMax = findMax(bsize, flag);
            if (indexOfMax != -1)
            {
                indexPlaced = indexOfMax;
                allocation[i] = indexPlaced;
                flag[indexPlaced] = 1;
            }
        }
        break;

    default:
        break;
    }

    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("allocation[%d] = %d\n", i, allocation[i]);
    }

    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("flag[%d] = %d\n", i, flag[i]);
    }

    printf("\nProcess No.\tMemory Size\t\tBlock No.\t\tProcess Size");
    switch (allocationType)
    {
    case 0:
        for (i = 0; i < pno; i++)
        {
            printf("\n%d\t\t%d\t\t\t", i + 1, bsize[allocation[i]]);
            if (allocation[i] != -1)
                printf("%d\t\t\t%d", allocation[i] + 1, psize[i]);
            else
                printf("Not allocated");
        }
        break;

    case 1:
        for (i = 0; i < pno; i++)
        {
            printf("\n%d\t\t%d\t\t\t", i + 1, bsize[allocation[i]]);
            if (allocation[i] != -1)
                printf("%d\t\t\t%d", allocation[i] + 1, psize[i]);
            else
                printf("Not allocated");
        }
        break;

    case 2:
        for (i = 0; i < pno; i++)
        {
            printf("\n%d\t\t%d\t\t", i + 1, bsize[allocation[i]]);
            printf("%d\t\t\t%d", allocation[i] + 1, psize[i]);
        }
        break;

    default:
        break;
    }
}