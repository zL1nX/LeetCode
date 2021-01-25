/*#include <stdio.h>
#include <stdlib.h>
void Print(int* nums,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
}
void reverse(int* nums,int index,int length)
{
    int i,temp;
    for(i=0;i<=(length+1-1)/2;i++)
    {
        temp = nums[index+i];
        nums[index+i] = nums[index+length-i];
        nums[index+length-i] = temp;
    }
    //Print(nums,index+length+1);
}
void nextPermutation(int* nums, int numsSize)
{
    int min = 1000000,i,j,flag_num,chosen,index,temp;
    for(i= numsSize-1 ;i>=0;i--)
    {
        //printf("i:%d\n",i);
        if(i==0)
        {
            reverse(nums,0,numsSize-1);
        }
        if(i>0 && nums[i] > nums[i-1])
        {
            //printf("find %d %d\n",i,nums[i-1]);
            flag_num = nums[i-1];
            index = i-1;
            for(j = index;j<=numsSize-1;j++)
            {
                if(nums[j] > flag_num && nums[j] <= min)
                    min = nums[j],chosen = j;
            }
            //printf("min:%d\n",min);
            temp = nums[index];
            nums[index] = nums[chosen];
            nums[chosen] = temp;
            //Print(nums,numsSize);
            reverse(nums,index+1,numsSize-2-index);
            break;
        }

    }
    //Print(nums,numsSize);
}
int main()
{
    int i,n;
    scanf("%d",&n);
    int nums[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
    }
    nextPermutation(nums,n);
    return 0;
}*/
