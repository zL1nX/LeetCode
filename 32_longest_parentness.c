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

        else if(s[i] == '(')//����������žͽ�ջ
        {
            str[top] = '(';
            place[top] = i;//��¼�µ�ǰ�����ŵ�λ��
            top++;
            //Print1(str);
            //Print2(place);
        }
        else//���������������
        {

            if(str[top-1] == '(')//�����ʱջ����ʲôԪ�أ�����������ţ���ջ
            {
                top--;//��ʱtopָ����Ҫ��Ե�������
                if(top == 0) l = i+1;//��ջ�������ʱtop��ջ�ף�˵�������Щ��������ȫ����ԣ���ǰ�������ŵ�λ�þ���
                else l = i-place[top-1];//��ʱtopָ���������ź�����Ǹ�Ԫ�ص�λ�ã�����Ҫ���ڱ��������ǰ�Ѿ�����������ˣ���ô��ʱ��place[top-1]�������ʼû����Ե�Ԫ��λ��
                max = max<l?l:max;
                //Print1(str);
                //Print2(place);
            }
            else//���ջ����������
            {
                str[top] = ')';//�Ǿͼ�������������ջ�����洢��Ӧ��λ��
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
