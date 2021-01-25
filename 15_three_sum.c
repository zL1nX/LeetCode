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
int** threeSum(int* nums,int numsSize,int* returnSize)
{
    int i,top = -1,begin,end;
    int sum;
    int** res = (int**)malloc(sizeof(int*)*(numsSize*(numsSize-1)*(numsSize-2))/6);
    if(numsSize < 3)
    {
        *returnSize = 0;
        return res;
    }
    quickSort(nums,0,numsSize-1);
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]>0)
            break;
        if(i>0 && nums[i] == nums[i-1])
            continue;

        begin = i+1;
        end = numsSize - 1;
        while(begin<end)
        {
            sum = nums[i]+nums[begin]+nums[end];
            if(sum == 0)//够了，看这个i对应的元素还有没有其他的三元组
            {
                top++;
                res[top] = (int*)malloc(sizeof(int)*3);
                res[top][0] = nums[i];res[top][1] = nums[begin];res[top][2] = nums[end];
                begin++;end--;//开始进行查找有没有其他元素符合要求的准备工作--略去重复元素
                while(begin<end && nums[begin] == nums[begin-1]) begin++;//一旦发现有相等的（排过序了）就忽略
                while(begin<end && nums[end] == nums[end+1]) end--;
            }
            else if(sum > 0)//此时加的有点多，需要往回缓一缓
                end--;
            else //此时加的不太够，需要往后多加点
                begin++;
        }
    }
    *returnSize = top + 1;
    return res;
}*/
/*int** threeSum(int* nums, int numsSize)
{
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if ((nums[i] + nums[j] - nums[k] == 0) && k!=i && k!=j)
            {
                res[m++]={nums[i],nums[j],nums[k]};
                k++
            }
        }
    }
}*/
/*int main()
{
    int n,i,j;
    scanf("%d",&n);
    int num[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    quickSort(num,0,n-1);
    for(i=0;i<n;i++)
        printf("%d\n",num[i]);
    int** p = (int**)malloc(sizeof(int*)*(long)(n*(n-1)*(n-2))/6);
    int* returnSize = (int*)malloc(sizeof(int*));
    p = threeSum(num,n,returnSize);
    for(i=0;i<*returnSize;i++)
    {
        for(j=0;j<3;j++)
            printf("%d %d\n",i,j),printf("%d ",*(*(p+i)+j));
        printf("\n");
    }
    //res = threeSum(num,n)
    return 0;
}*/
