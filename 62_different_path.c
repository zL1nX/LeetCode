/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int uniquePaths(int m, int n)
{
    int dp[n][m],i,j;
    memset(dp,0,sizeof(dp));
    for(i=0;i<n;i++)
        dp[i][0] = 1;
    for(i=0;i<m;i++)
        dp[0][i] = 1;
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
    return dp[n-1][m-1];
}
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int res = uniquePaths(m,n);
    printf("%d\n",res);
    return 0;
}*/
