/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>*/
/*int find_first(char* lword,char* sword,int l,int s)
{
    //int* index = (int*)malloc(sizeof(int)*2);
    int i,j;
    for(i=0;i<l;i++)
    {
        if(lword[i] == sword[0])
            break;
    }
    int first = i,count=0;
    for(i=first;i<first+s;i++)
    {
        for(j=0;j<s;j++)
        {
            if(lword[i]!=sword[j])
                count++;
        }
    }
    return count;
}
int minDistance(char* word1, char* word2)
{
    printf("%s %s\n",word1,word2);
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int count = abs(len1-len2);
    int res;
    if(len1 < len2)
        res = find_first(word2,word1,len2,len1);
    else
        res = find_first(word1,word2,len1,len2);
    return count+res;

}*/
/*int min_three(int a,int b,int c)
{
    int min = a > b ? b : a;
    return min > c ? c : min;
}
int minDistance(char* word1, char* word2)
{
    int i,j;
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int **dp = (int**)malloc(sizeof(int*)*(len1+1));
    for(i=0;i<=len1;i++)
    {
        dp[i] = (int*)malloc(sizeof(int)*(len2+1));
        dp[i][0] = i;
    }
    for(i=0;i<=len2;i++)
    {
        dp[0][i] = i;
    }
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            if(word1[i-1] == word2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min_three(dp[i][j-1]+1,dp[i-1][j]+1,dp[i-1][j-1]+1);
            }
        }
    }
    return dp[len1][len2];
}
int main()
{
    char word1[10000],word2[10000];
    scanf("%s",word1);
    scanf("%s",word2);
    int res = minDistance(word1,word2);
    printf("%d\n",res);
    return 0;
}*/
