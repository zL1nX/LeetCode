/*#include <stdio.h>
#include <stdlib.h>
void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sortColors(int* nums, int numsSize)
{
    int start = 0,end = numsSize,cur=-1,i;
    while(start < end)
    {

        if(nums[start] < 1)
        {
            cur++;
            swap(&nums[start],&nums[cur]);
            start++;
        }
        else if(nums[start] > 1)
        {
            end--;
            swap(&nums[start],&nums[end]);
        }
        else
            start++;
        printf("%d %d %d ",start,end,cur);
        for(i=0;i<numsSize;i++)
            printf("%d ",nums[i]);
        printf("\n");
    }
}

int main()
{
    int num,i;
    scanf("%d",&num);
    int *n = (int*)malloc(sizeof(int)*(num+1));
    for(i=0;i<num;i++)
        scanf("%d",&n[i]);
    sortColors(n,num);
    for(i=0;i<num;i++)
        printf("%d ",n[i]);
    printf("\n");
    return 0;
}*/
