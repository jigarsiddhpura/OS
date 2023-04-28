
#include <stdio.h>
void main()
{
    int bsize[15], psize[15], bno, pno, flags[15], allocation[15], i, j;
    for (i = 0; i < 15; i++)
    {
        flags[i] = 0;
        allocation[i] = -1;
    }
    printf("enter no of Memory Blocks : ");
    scanf("%d", &bno);
    printf("enter size of each Memory Block : \n");
    for (i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);
    printf("enter no of Processes : ");
    scanf("%d", &pno);
    printf("enter size of each Process : \n");
    for (i = 0; i < pno; i++)
        scanf("%d", &psize[i]);
    for (i = 0; i < pno; i++)
    {
        int indexPlaced = -1;
        for (j = 0; j < bno; j++)
        {
            if (bsize[j] >= psize[i] && flags[j] == 0)
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
            flags[indexPlaced] = 1;
        }
    }
    printf("\nProcess No.\tMemory Size\t\tBlock No.\t\tProcess Size");
    for (i = 0; i < pno; i++)
    {
        printf("\n%d\t\t%d\t\t\t", i + 1, bsize[allocation[i]]);
        if (allocation[i] != -1)
            printf("%d\t\t\t%d", allocation[i] + 1, psize[i]);
        else
            printf("Not allocated");
    }
}