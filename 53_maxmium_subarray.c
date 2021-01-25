/*#include <stdio.h>
#include <stdlib.h>
int maxSubArray(int* nums, int numsSize)
{
    if(numsSize<=0)
        return 0;
    int max = nums[0],sum = 0;
    int i;
    for(i=0;i<numsSize;i++)
    {
        sum += nums[i];
        max = max > sum ? max : sum;
        if(sum < 0)
            sum = 0;
    }
    return max;
}
int main()
{
    int num,i;
    scanf("%d",&num);
    int n[num];
    for(i=0;i<num;i++)
        scanf("%d",&n[i]);
    int sum = maxSubArray(n,num);
    printf("%d\n",sum);
    return 0;
}*/
