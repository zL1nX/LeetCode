/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>*/
/*void generate(int n,int* returnSize,int l,int r,char** res,char* line,int index)
{
    if(l>0)
    {
        line[index] = '(';
        generate(n,returnSize,l-1,r,res,line,index+1);
    }
    if(r>0 && l<r)
    {
        line[index] = ')';
        generate(n,returnSize,l,r-1,res,line,index+1);
    }
    if(l == 0 && r == 0)
    {
        printf("here1\n");
        line[index] = '\0';
        printf("round:%d\n",*returnSize);
        res[*returnSize] = (char*)malloc(sizeof(char)*index);
        printf("here2\n");
        strcpy(res[*returnSize],line);
        *returnSize += 1;
        return;
    }
}
char** generateParenthesis(int n, int* returnSize)
{
    char** res = (char**)malloc(sizeof(char*)*100000);
    char* line = (char*)malloc(sizeof(char)*(2*n+1));
    *returnSize = 0;
    int l=n,r = n;
    generate(n,returnSize,l,r,res,line,0);
    return res;

}*/

/*static char** generateParenthesis(int n, int* returnSize)
{
    int left, right, cap = 5000, count = 0;
    char *stack = malloc(2 * n + 1);
    char **parentheses = malloc(cap * sizeof(char *));

    char *p = stack;
    left = right = 0;
    stack[2 * n] = '\0';


    while (p != stack || count == 0)
    {
        if (left == n && right == n)
        {
            printf("in:%s\n",stack);
            parentheses[count] = malloc(2 * n + 1);
            strcpy(parentheses[count], stack);
            count++;


            while (--p != stack)
            {

                if (*p == '(')
                {
                    printf("%d\n",p);

                    if (--left > right)
                    {
                        *p++ = ')';
                        right++;
                        printf("p:%d br:%s\n",p,stack);
                        break;
                    }
                }
                else
                {
                    right--;
                }
            }
        }
        else
        {

            while (left < n)
            {
                *p++ = '(';
                left++;
                printf("p:%d out:%s\n",p,stack);
            }
            while (right < n)
            {
                *p++ = ')';
                right++;
                printf("p:%d out:%s\n",p,stack);
            }

        }
    }

    *returnSize = count;
    return parentheses;
}
int main()
{
    int *returnSize = (int*)malloc(sizeof(int));
    int i,num;
    scanf("%d",&num);
    char** combination = generateParenthesis(num,returnSize);
    for(i=0;i<*returnSize;i++)
        printf("%s\n",combination[i]);
    return 0;
}*/
