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
        while(left<right && current_num<=nums[right]) right--;//�������Ԫ�ش��ڵ�ǰ��׼ֵʱ��right--��ֱ������ָ����ͷ�����ҵ��˱Ȼ�׼ֵС��Ԫ�أ�
        if(left<right) nums[left] = nums[right];//�ҵ��˻�׼ֵ�������С��Ԫ�أ��Ͱ����ŵ�ǰ��
        while(left<right && current_num>=nums[left]) left++;//��ǰ���Ԫ��С�ڻ�׼ֵʱ��left++��ֱ���ҵ��������Ԫ��
        if(left<right) nums[right] = nums[left];//�ҵ��˻�׼ֵǰ��������Ԫ�أ��Ͱ����ŵ�����
        nums[left] = current_num;//��Ϊ�Ǻ󿼲��left�����Դ�ʱ��left��Ϊ��׼ֵӦ���ڵ�λ�ã����԰�currentnum����leftָ���λ��
        quickSort(nums,first,left-1);
        quickSort(nums,left+1,end);//����׼ֵ���λ���⣬����λ�õݹ�Ľ������򣬵�����λ�ö��źú��������о��ź���
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
