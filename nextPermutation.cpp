/*

实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

// solution: https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) 
{
    if(nums.size() == 1)
    {
        return;
    }

    int i = nums.size() - 2, j = nums.size() - 1, k = nums.size() - 1;
    for(;i >= 0 && nums[i] >= nums[j];i--,j--){}
    if(i >= 0)
    {
        for(;nums[i] >= nums[k];k--){}
        swap(nums[i], nums[k]);
    }
    for(i = j, j = nums.size() - 1;i < j;i++, j--)
    {
        swap(nums[i], nums[j]);
    }
}

/*

void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end()); // STL功能和题目描述一致
  }

*/