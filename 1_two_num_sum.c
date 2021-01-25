/*#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numSize, int target)
{
    int i,j;
    int *res=malloc(2*sizeof(int));
    for(i=0;i<numSize;i++)
    {
        res[0] = i;
        for(j=i+1;j<numSize;j++)
        {
            if(nums[i]+nums[j] == target)
            {
                res[1] = j;
                return res;
            }
        }
    }
    res[0]=i;
    res[1]=j;
    return res;
}
int* twoSum(int* nums, int numSize, int target)
{
    int i;
    int counts[10000]={0};
    int m[10000];
    int *res=malloc(2*sizeof(int));
    for(i=0;i<numSize;i++)
    {
        counts[nums[i]]++;
        m[nums[i]] = i;
    }
    for(i=0;i<numSize;i++)
    {
        int temp = target-nums[i];
        if (counts[temp] && m[temp] != i)
        {
            res[0] = i;
            res[1] = m[temp];
            return res;
        }
    }

}
int main()
{
    int numSize,i,target;
    int *result;
    scanf("%d",&numSize);
    int nums[numSize];
    for(i=0;i<numSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    scanf("%d",&target);
    result = twoSum(nums,numSize,target);
    printf("%d %d\n",*result,*result+1);
    free(result);
    return 0;
}
*/
