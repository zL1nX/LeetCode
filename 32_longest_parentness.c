/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Print1(char* s)
{
    printf("str: ");
    printf("%s\n",s);
}
void Print2(int s[])
{
    int i;
    printf("place: ");
    for(i=0;i<(sizeof(s)/sizeof(int));i++)
        printf("%d ",s[i]);
    printf("\n");
}
int longestValidParentheses(char* s)
{
    int len = strlen(s);
    if(len == 0) return 0;
    int max = 0,i,top=0,l;
    char str[len];
    int place[len];
    for(i=0;i<len;i++)
    {
        if(top == 0)
        {
            str[top] = s[i];
            place[top] = i;
            top++;

        }

        else if(s[i] == '(')//如果是左括号就进栈
        {
            str[top] = '(';
            place[top] = i;//记录下当前左括号的位置
            top++;
            //Print1(str);
            //Print2(place);
        }
        else//如果碰到了右括号
        {

            if(str[top-1] == '(')//考察此时栈顶是什么元素，如果是左括号，弹栈
            {
                top--;//此时top指向了要配对的左括号
                if(top == 0) l = i+1;//弹栈后，如果此时top到栈底，说明存的那些个左括号全部配对，当前的右括号的位置就是
                else l = i-place[top-1];//此时top指向了左括号后面的那个元素的位置，假设要是在本括号配对前已经有括号配对了，那么此时的place[top-1]还是在最开始没被配对的元素位置
                max = max<l?l:max;
                //Print1(str);
                //Print2(place);
            }
            else//如果栈顶是右括号
            {
                str[top] = ')';//那就继续把右括号入栈，并存储相应的位置
                place[top] = i;
                top++;
                //Print1(str);
                //Print2(place);
            }
        }
    }
    return max;
}
int main()
{
    int len;
    char s[100000];
    scanf("%s",s);
    len = longestValidParentheses(s);
    printf("%d\n",len);
    return 0;
}*/
