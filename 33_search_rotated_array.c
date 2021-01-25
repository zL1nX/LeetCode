/*#include <stdio.h>
#include <stdlib.h>
int search(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    while(left<=right)
    {
        int mid = (left+right) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] >= nums[left])
        {
            if(target < nums[mid] && target >= nums[left])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if(target <= nums[right] && target > nums[mid])
                left = mid + 1 ;
            else
                right = mid - 1;
        }
    }
    return -1;

}
int main()
{
    int num,target,i,index;
    scanf("%d %d",&num,&target);
    int nums[num];
    for(i=0;i<num;i++)
        scanf("%d",&nums[i]);
    index = search(nums,num,target);
    printf("%d\n",index);
    return 0;
}*/
