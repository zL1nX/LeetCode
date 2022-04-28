/*
给你一个整数数组 nums，将 nums 中的的所有偶数元素移动到数组的前面，后跟所有奇数元素。

返回满足此条件的 任一数组 作为答案。

 

示例 1：

输入：nums = [3,1,2,4]
输出：[2,4,3,1]
解释：[4,2,3,1]、[2,4,1,3] 和 [4,2,1,3] 也会被视作正确答案。
示例 2：

输入：nums = [0]
输出：[0]
 

提示：

1 <= nums.length <= 5000
0 <= nums[i] <= 5000
通过次数73,549提交次数104,224

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-array-by-parity
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) 
{
    int left = 0, right = nums.size() - 1;
    while(left < right)
    {
        if(nums[left] % 2 == 1 && nums[right] % 2 == 0)
        {
            swap(nums[left], nums[right]);
        }
        else if(nums[left] % 2 == 0 && nums[right] % 2 == 0)
        {
            left++;
        }
        else if(nums[left] % 2 == 1 && nums[right] % 2 == 1)
        {
            right--;
        }
        else
        {
            left++;
            right--;
        }
    }
    return nums;
}

// 脑筋急转弯 + 有点排序那味了