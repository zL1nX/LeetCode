/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
inline int min(int a,int b)
{
    return a < b ? a : b;
}
int minPathSum(int** grid, int gridRowSize, int gridColSize)
{
    int dp[gridRowSize][gridColSize],i,j;
    memset(dp,0,sizeof(dp));
    dp[0][0] = grid[0][0];
    int sum = 0;
    for(i=0;i<gridRowSize;i++)
    {
        sum += grid[i][0];
        dp[i][0] = sum;
    }
    sum = 0;
    for(i=0;i<gridColSize;i++)
    {
        sum += grid[0][i];
        dp[0][i] = sum;
    }
    for(i=1;i<gridRowSize;i++)
    {
        for(j=1;j<gridColSize;j++)
            dp[i][j] = grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
    }
    return dp[gridRowSize-1][gridColSize-1];
}
int main()
{
    int m,n,i,j;
    scanf("%d %d",&m,&n);
    int **num = (int**)malloc(sizeof(int)*m);
    for(i=0;i<m;i++)
        num[i] = (int*)malloc(sizeof(int)*n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&num[i][j]);
    }
    int sum = minPathSum(num,m,n);
    printf("%d\n",sum);
    return 0;
}*/
