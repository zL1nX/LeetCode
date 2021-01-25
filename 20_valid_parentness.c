/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
bool isValid(char* s) {
    int i,j,top=0;
    int len = strlen(s),score[3]={ 0 };
    char stack[10000];
    int first;
    if(len == 0)
        return true;
    if(len == 1)
        return false;
    for(i=0;i<len;i++)
    {
        switch(s[i])
        {
            case '(':
                stack[++top] = s[i];
                score[0]++;
                break;
            case '[':
                stack[++top] = s[i];
                score[1]++;
                break;
            case '{':
                stack[++top] = s[i];
                score[2]++;
                break;
            case ')':
                first = stack[top];
                score[0]--;
                if((s[i]-first)!= 1 || score[0]<0)
                    return false;
                top--;
                break;
            case ']':
                first = stack[top];
                score[1]--;
                if((s[i]-first)!= 2 || score[1]<0)
                    return false;
                top--;
                break;
            case '}':
                first = stack[top];
                score[2]--;
                if((s[i]-first)!= 2 || score[2]<0)
                    return false;
                top--;
                break;
        }
    }
    if(top >0 )
        return false;
    return true;
}
int main()
{
    char s[1000];
    scanf("%s",s);
    bool flag = isValid(s);
    printf(flag ? "yes\n" : "no\n");
    return 0;
}*/
