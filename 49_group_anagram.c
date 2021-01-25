/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct word_hash{
    char *word;
    int num;
    int indexes[10];
};
int compare(const void *a,const void *b)
{
    return *(char*)a - *(char*)b;
}
inline int bkdrhash(char* s,size_t size)
{
    int seed = 31;
    unsigned long hash = 0;
    while(*s != '\0')
    {
        hash = hash*seed + *s++;
    }
    return hash%size;
}

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize)
{
    int i,j,count = 0;
    int hash_size = strsSize;
    struct word_hash *ht = calloc(hash_size,sizeof(*ht));
    char **words = malloc(sizeof(char*)*strsSize);
    for(i=0;i<strsSize;i++)
    {
        int len = strlen(strs[i]);
        words[i] = malloc(len+1);
        strcpy(words[i],strs[i]);
        qsort(strs[i],len,sizeof(char),compare);
        int hash = bkdrhash(words[i],hash_size);
        for(j = hash;ht[j].num > 0 && strcmp(ht[j].word,words[i]);j = (++j)%hash_size)
        {}//�ҵ���ȵ�Ԫ�أ�Ȼ��洢
        if(ht[j].num == 0)//�״�����
        {
            ht[j].word = words[i];
            count++;
        }
        ht[j].indexes[ht[j].num++] = i;//����ȵ�Ԫ�أ�ֱ���������ϼ�һ��Ȼ����ϣ��
    }

    int k = 0;
    //struct hlist_node *p;
    char ***lists = malloc(count * sizeof(char**));
    *columnSizes = malloc(count*sizeof(int));
    for(i=0;i<hash_size;i++)
    {
        if(ht[i].num > 0)
        {
            (*columnSizes)[k] = ht[i].num;
            lists[k] = malloc(ht[i].num * sizeof(char*));
            for(j=0;j<ht[i].num;j++)
            {
                int index = ht[i].indexes[j];
                lists[k][j] = strs[index];
            }
            k++;
        }
    }
    *returnSize = count;
    return lists;

}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    char **s = malloc(sizeof(char*)*10000);
    int **columnSize=malloc(sizeof(int*)*10000),*returnSize=0;
    for(i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    char ***res = groupAnagrams(s,n,columnSize,returnSize);
    for(i=0;i<*returnSize;i++)
    {
        for(j=0;j<columnSize[i][j];j++)
            printf("%s",res[i][j]);
        printf("\n");
    }
    return 0;
}*/
