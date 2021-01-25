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
            if(sum == 0)//���ˣ������i��Ӧ��Ԫ�ػ���û����������Ԫ��
            {
                top++;
                res[top] = (int*)malloc(sizeof(int)*3);
                res[top][0] = nums[i];res[top][1] = nums[begin];res[top][2] = nums[end];
                begin++;end--;//��ʼ���в�����û������Ԫ�ط���Ҫ���׼������--��ȥ�ظ�Ԫ��
                while(begin<end && nums[begin] == nums[begin-1]) begin++;//һ����������ȵģ��Ź����ˣ��ͺ���
                while(begin<end && nums[end] == nums[end+1]) end--;
            }
            else if(sum > 0)//��ʱ�ӵ��е�࣬��Ҫ���ػ�һ��
                end--;
            else //��ʱ�ӵĲ�̫������Ҫ�����ӵ�
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
