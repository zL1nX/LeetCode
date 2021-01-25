/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* minWindow(char* s, char* t)
{
    //printf("%s %s\n",s,t);
    int len1 = strlen(s),len2 = strlen(t);
    int slow = 0,fast = 0;
    int i,first,count = 0,min = len1,indexi,indexj;
    int table[256],flag[256];
    char *res = (char*)malloc(sizeof(char)*len1);
    for(i=0;i<len2;i++)
    {
        table[t[i]] = 1;
        flag[t[i]] = 1;
    }
    printf("here1\n");
    while(fast < len1)
    {
        for(i=fast;i<len1;i++)
        {
            if(table[s[i]]==0)
            {
                first = i;
                break;
            }
        }
        printf("i:%d\n",i);
        if(table[s[fast]] == 1)//如果当前字母是t中的字母
        {
            if(flag[s[fast]])
            {
                flag[s[fast++]] = 0;
                count++;
            }//而且之前没碰到过
                //就标记下表示碰到了
            if(count == len2)
            {
                count = 0;
                if(min < (fast - slow))
                    min = (fast-slow);indexi = slow;indexj = fast;
                slow = fast = first;
            }

        }
        else
            fast++;
    }
    int k = 0;
    for(i=indexi;i<=indexj;i++)
        res[k++]=s[i];
    return res;
}
int main()
{
    char *s = (char*)malloc(sizeof(char)*10000);
    char *t = (char*)malloc(sizeof(char)*10000);
    scanf("%s",s);
    scanf("%s",t);
    char *res = minWindow(s,t);
    printf("%s\n",res);
    return 0;
}*/
