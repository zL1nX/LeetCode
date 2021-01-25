/*#include <stdio.h>
#include <stdlib.h>
void rotate(int** matrix, int matrixRowSize, int matrixColSize)
{
    if(matrixRowSize != matrixColSize)
    {
        return;
    }
    printf("in!\n");
    int i,j,first,last;
    for(i=0;i<matrixRowSize/2;i++)
    {
        first = i;last = matrixColSize-1-i;
        for(j=first;j<last;j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[matrixColSize-j-1][i];//列不变行变
            matrix[matrixColSize-j-1][i] = matrix[matrixRowSize-i-1][matrixColSize-j-1];//行不变列变
            matrix[matrixRowSize-i-1][matrixColSize-j-1] = matrix[j][matrixRowSize-i-1];//列不变行变
            matrix[j][matrixRowSize-i-1] = temp;
        }
    }
    printf("here!\n");
}
int main()
{
    int row,column,i,j;
    scanf("%d %d",&row,&column);
    int **nums=(int**)malloc(sizeof(int*)*row);
    for(i=0;i<row;i++)
    {
        nums[i]=(int*)malloc(sizeof(int)*column);
        for(j=0;j<column;j++)
            scanf("%d",&nums[i][j]);
    }
    rotate(nums,row,column);
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
            printf("%d ",nums[i][j]);
        printf("\n");
    }
    return 0;
}*/
