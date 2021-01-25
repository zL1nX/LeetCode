/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char *s)
{
    printf("here1.5!\n");
    int k,i,len,m=-1,left;
    printf("here1.5!\n");
    int dp[1001][1001] = { {0,}, };
    //memset(dp,0,sizeof(dp));
    printf("here2!\n");
    len = strlen(s);
    if (len <= 1)
        return s;

    for(i=0;i<len;i++)
    {
        dp[i][i] = 1;
        dp[i][i-1] = 1;//k=2时，为了统一逻辑，同样这么写表示嵌套，实际意义是倒数第二个等于第二个
    }
    for(k=2;k<=len;k++)
    {
        for(i=0;i<len-k+1;i++)
        {
            if(s[i] == s[k+i-1] && dp[i+1][k+2-i])
            {
                dp[i][k+i-1] = 1;
                if(m < k)
                {
                    m = k;
                    left = i;
                    //right = k-1+i;
                }
            }
        }
    }
    printf("here3!\n");
    char *res = (char*)malloc(sizeof(char)*m);
    for(i=0;i<m;i++)
        res[i] = s[left++];
    res[i] = '\0';
    printf("here4!\n");
    return res;
}

char* test(char *s)
{
    printf("in!");
    printf("%s\n",s);
    //char *p = s;
    printf("here1.5!\n");
    int k,i,len,m=-1,left;
    printf("here1.5!\n");
    int dp[1001][1001] = { {0,}, };
    //memset(dp,0,sizeof(dp));
    printf("here2!\n");
    len = strlen(s);
    if (len <= 1)
        return s;

    for(i=0;i<len;i++)
    {
        dp[i][i] = 1;
        dp[i][i-1] = 1;//k=2时，为了统一逻辑，同样这么写表示嵌套，实际意义是倒数第二个等于第二个
    }
    for(k=2;k<=len;k++)
    {
        for(i=0;i<len-k+1;i++)
        {
            if(s[i] == s[k+i-1] && dp[i+1][k+2-i])
            {
                dp[i][k+i-1] = 1;
                if(m < k)
                {
                    m = k;
                    left = i;
                    //right = k-1+i;
                }
            }
        }
    }
    printf("here3!\n");
    char *res = (char*)malloc(sizeof(char)*m);
    for(i=0;i<m;i++)
        res[i] = s[left++];
    res[i] = '\0';
    printf("here4!\n");
    return res;
    //return p;
}

int main()
{
    char *s = (char*)malloc(sizeof(char)*1000);
    char *t = "acabcac";
    //char *res;
    //scanf("%s",s);
    printf("%s\n",t);
    printf("here1!\n");
    //char* r = longestPalindrome(t);
    char *flag = test(t);
    //printf("%d\n",flag);
    printf("%s\n",flag);
    return 0;
}*/
