/*#include <stdio.h>
#include <stdlib.h>
void quickSort(int* nums,int first,int end)
{
    int left = first;
    int right = end;
    int current_num = nums[first];
    if(first>=end) return;
    while(left<right)
    {
        while(left<right && current_num<=nums[right]) right--;//当后面的元素大于当前基准值时，right--，直到两个指针碰头或者找到了比基准值小的元素；
        if(left<right) nums[left] = nums[right];//找到了基准值后面比它小的元素，就把它放到前面
        while(left<right && current_num>=nums[left]) left++;//当前面的元素小于基准值时，left++，直到找到比它大的元素
        if(left<right) nums[right] = nums[left];//找到了基准值前面比它大的元素，就把它放到后面
        nums[left] = current_num;//因为是后考察的left，所以此时的left即为基准值应该在的位置，所以把currentnum赋给left指向的位置
        quickSort(nums,first,left-1);
        quickSort(nums,left+1,end);//除基准值这个位置外，其余位置递归的进行排序，当所有位置都排好后，整个序列就排好了
    }
}

int threeSumCloset(int* nums,int numsSize,int target)
{
    int i,begin,end,sum,m=1000000,res;
    //printf("%d\n",numsSize);
    if(numsSize<3)
        return 0;
    quickSort(nums,0,numsSize-1);
    for(i=0;i<numsSize;i++)
    {
        if(i>0 && nums[i] == nums[i-1])
            continue;
        begin = i+1;
        end = numsSize - 1;
        //printf("%d %d\n",begin,end);
        while(begin<end)
        {
            sum = nums[i] + nums[begin] + nums[end];
            //printf("%d %d %d %d\n",i,begin,end,sum);
            if(sum > target)
                end--;
            else if(sum < target)
                begin++;
            else
                return sum;
            if(abs(target-sum) < m)
            {
                m = abs(target-sum);
                res = sum;
                //("m:%d res:%d\n",m,res);
            }

            while(begin<end && nums[begin] == nums[begin-1]) begin++;
            while(begin<end && nums[end] == nums[end + 1]) end--;
        }
    }
    return res;

}

int main()
{
    int i,n,target,sum;
    scanf("%d %d",&n,&target);
    int num[n];
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    sum = threeSumCloset(num,n,target);
    printf("%d\n",sum);
    return 0;
}*/
