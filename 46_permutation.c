#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}*/
/*void num_generate(int* nums,int numsSize,int** res,int start,int* returnSize)
{
    printf("len:%d\n",start);
    if(start == numsSize)
    {
        res[*returnSize] = (int*)malloc(sizeof(int)*numsSize);
        memcpy(res[*returnSize],nums,numsSize*sizeof(int));
        (*returnSize)++;
        printf("size:%d\n",*returnSize);
        return;
    }
    else
    {
        int i;
        for(i=start;i<numsSize;i++)
        {
            //printf("len:%d\n",len);
            //swap(nums+start,nums+i);
            //num_generate(nums,numsSize,res,start+1,returnSize);
            //swap(nums+start,nums+i);
        }
    }
}*/
/*void num_generate(int* nums,int numsSize,int** res,int* flags,int* stack,int start,int* returnSize)
{
    printf("len:%d\n",start);
    if(start == numsSize)
    {
        res[*returnSize] = (int*)malloc(sizeof(int)*numsSize);
        memcpy(res[*returnSize],stack,numsSize*sizeof(int));
        (*returnSize)++;
        printf("size:%d\n",*returnSize);
        return;
    }
    else
    {
        int i;
        for(i=0;i<numsSize;i++)
        {
            if(flags[i] == 0)
            {
                stack[start] = nums[i];
                flags[i] = 1;
                num_generate(nums,numsSize,res,flags,stack,start+1,returnSize);
                flags[i] = 0;
            }
            //printf("len:%d\n",len);
            //swap(nums+start,nums+i);
            //num_generate(nums,numsSize,res,start+1,returnSize);
            //swap(nums+start,nums+i);
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize)
{
    printf("in:%d\n",numsSize);
    if(numsSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    int i;
    int flags[numsSize];
    memset(flags,0,sizeof(flags));
    int **res = (int**)malloc(sizeof(int*)*100000);
    int *stack = (int*)malloc(sizeof(int)*numsSize);
    printf("here1\n");
    num_generate(nums,numsSize,res,flags,stack,0,returnSize);
    return res;
}
int main()
{
    int num,i,j;
    int *returnSize = (int*)malloc(sizeof(int));
    int **res;
    scanf("%d",&num);
    int nums[num];
    for(i=0;i<num;i++)
        scanf("%d",&nums[i]);
    *returnSize = 0;
    res = permute(nums,num,returnSize);
    for(i=0;i<*returnSize;i++)
    {
        for(j=0;j<num;j++)
            printf("%d ",res[i][j]);
        printf("\n");
    }
    return 0;
}*/
