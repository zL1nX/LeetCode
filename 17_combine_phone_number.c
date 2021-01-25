/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** letterCombinations(char* digits, int* returnSize)
{
    int i,j,col=0,segment_size,segment_num,size=1,current_digits,current_digits_length;
    char phone_number[10][5] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    //如果搞了半天人家是个空串，就直接返回
    int len = strlen(digits);
    if(len == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    //对目标字符串所对应的结果尺寸进行计算
    for(i=0;i<len;i++)
    {
        if(digits[i] == '7' || digits[i] == '9')
            size*=4;
        else
            size*=3;
    }
    *returnSize = size;

    //进行结果指针空间的申请与赋值
    char** res = (char**)malloc(sizeof(char*) * size);
    for(i=0;i<size;i++)
    {
        res[i] = (char*)malloc(sizeof(char)* (len+1));
        res[i][len] = '\0';
    }
    segment_size = size;
    //开始对字符串的每个数字进行遍历，遍历的方式就是按列填充，参考内存分段模式
    for(i=0;i<len;i++)
    {

        current_digits = digits[i];
        current_digits_length = strlen(phone_number[(int)(current_digits-'0')]);
        //取得当前要填充的字符，以及字符按键上字母的长度，然后对每一行的某一列开始遍历填充
        segment_size = segment_size / current_digits_length;
        for(j=0;j<size;j++)
        {

            segment_num = j/segment_size % current_digits_length;
            res[j][col] = phone_number[(int)(digits[i]-'0')][segment_num];
        }
        col++;//填充完一列之后再进行下一列的填充
    }
    return res;
}
int main()
{
    int i;
    char digits[10000];
    int* returnSize = (int*)malloc(sizeof(int));
    scanf("%s",digits);
    printf("%s\n",digits);
    char** res = letterCombinations(digits,returnSize);

    printf("%d\n",*returnSize);
    if(res)
    {
        for(i=0;i<*returnSize;i++)
            printf("%s\n",res[i]);
    }
    return 0;
}*/
