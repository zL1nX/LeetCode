/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** letterCombinations(char* digits, int* returnSize)
{
    int i,j,col=0,segment_size,segment_num,size=1,current_digits,current_digits_length;
    char phone_number[10][5] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    //������˰����˼��Ǹ��մ�����ֱ�ӷ���
    int len = strlen(digits);
    if(len == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    //��Ŀ���ַ�������Ӧ�Ľ���ߴ���м���
    for(i=0;i<len;i++)
    {
        if(digits[i] == '7' || digits[i] == '9')
            size*=4;
        else
            size*=3;
    }
    *returnSize = size;

    //���н��ָ��ռ�������븳ֵ
    char** res = (char**)malloc(sizeof(char*) * size);
    for(i=0;i<size;i++)
    {
        res[i] = (char*)malloc(sizeof(char)* (len+1));
        res[i][len] = '\0';
    }
    segment_size = size;
    //��ʼ���ַ�����ÿ�����ֽ��б����������ķ�ʽ���ǰ�����䣬�ο��ڴ�ֶ�ģʽ
    for(i=0;i<len;i++)
    {

        current_digits = digits[i];
        current_digits_length = strlen(phone_number[(int)(current_digits-'0')]);
        //ȡ�õ�ǰҪ�����ַ����Լ��ַ���������ĸ�ĳ��ȣ�Ȼ���ÿһ�е�ĳһ�п�ʼ�������
        segment_size = segment_size / current_digits_length;
        for(j=0;j<size;j++)
        {

            segment_num = j/segment_size % current_digits_length;
            res[j][col] = phone_number[(int)(digits[i]-'0')][segment_num];
        }
        col++;//�����һ��֮���ٽ�����һ�е����
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
