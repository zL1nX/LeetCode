/*#include <stdio.h>
#include <stdlib.h>
int climbStairs(int n)
{
    if(n==0)
        return 1;
    int dp[n+1],i;
    for(i=0;i<=n;i++)
    {
        if(i<=3)
            dp[i] = i;
        else
            dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n;
    scanf("%d",&n);
    int res = climbStairs(n);
    printf("%d\n",res);
    return 0;
}*/
