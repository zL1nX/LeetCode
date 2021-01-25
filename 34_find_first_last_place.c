/*#include <stdio.h>
#include <stdlib.h>
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int *place=malloc(sizeof(int)*2);
    if(numsSize == 0)
    {
        *returnSize = 2;
        place[0] = -1;place[1] = -1;
        return place;
    }
    int left = 0,right = numsSize - 1;
    while(left<=right)
    {
        int mid = (left + right) / 2;
        if(target == nums[mid])//find the element
        {
            //printf("mid:%d\n",mid);
            int start=mid,end = mid;
            while(start>=0 && nums[start-1] == target)start--;
            while(end <= numsSize-1 && nums[end+1] == target)end++;
            *returnSize = 2;
            printf("%d %d\n",start,end);
            place[0] = start;place[1] = end;
            return place;
        }
        else if(target < nums[mid])
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }

    }
    *returnSize = 2;
    place[0] = -1;place[1] = -1;
    return place;
}
int main()
{
    int num,i,*place,*returnSize,target;
    scanf("%d %d",&num,&target);
    int nums[num];
    for(i=0;i<num;i++)
        scanf("%d",&nums[i]);
    returnSize = (int*)malloc(sizeof(int));
    *returnSize = 0;
    place = searchRange(nums,num,target,returnSize);
    for(i=0;i<*returnSize;i++)
        printf("%d ",*(place+i));
    printf("\n");
    return 0;
}*/
