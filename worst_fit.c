
#include <stdio.h>
void main()
{
    int bsize[15], psize[15], bno, pno, allocation[15], i, j;
    printf("Enter no of Memory Blocks : ");
    scanf("%d", &bno);
    printf("Enter size of each Memory Block : \n");
    for (int i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);
    printf("Enter no of Processes : ");
    scanf("%d", &pno);
    printf("Enter size of each Process : \n");
    for (int i = 0; i < pno; i++)
        scanf("%d", &psize[i]);
    for (int i = 0; i < pno; i++)
        allocation[i] = -1;
    for (int i = 0; i < pno; i++)
    {
        int indexPlaced = -1;
        for (int j = 0; j < bno; j++)
        {
            if (bsize[j] >= psize[i])
            {
                if (indexPlaced == -1)
                    indexPlaced = j;
                else if (bsize[j] > bsize[indexPlaced])
                    indexPlaced = j;
            }
        }
        if (indexPlaced != -1)
        {
            allocation[i] = indexPlaced;
            bsize[indexPlaced] -= psize[i];
        }
    }
    printf("\nProcess No.\tMemory Size\t\tBlock No.\t\tProcess Size");
    for (int i = 0; i < pno; i++)
    {
        if (bsize[allocation[i]] == -1)
            printf("\n%d\t\tNone\t\t\t", i + 1);
        else
            printf("\n%d\t\t%d\t\t\t", i + 1, bsize[allocation[i]]);
        if (allocation[i] != -1)
            printf("%d\t\t\t%d", allocation[i] + 1, psize[i]);
        else
            printf("Not allocated\t\t%d", psize[i]);
    }
}