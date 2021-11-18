/*
和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。

现在，给你一个整数数组 nums ，请你在所有可能的子序列中找到最长的和谐子序列的长度。

数组的子序列是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。

 

示例 1：

输入：nums = [1,3,2,2,5,2,3,7]
输出：5
解释：最长的和谐子序列是 [3,2,2,2,3]
示例 2：

输入：nums = [1,2,3,4]
输出：2
示例 3：

输入：nums = [1,1,1,1]
输出：0
 

提示：

1 <= nums.length <= 2 * 104
-109 <= nums[i] <= 109
通过次数34,747提交次数65,228

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-harmonious-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

int findLHS(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());
    int left = 0, right = 0, res = 0; // 双指针
    while(right < nums.size())
    {
        while(nums[right] - nums[left] > 1) // 此时right太大，left要前移，否则不是和谐数组
        {
            left++;
        }
        if(nums[right] - nums[left] ==  1) // 恰好为一组和谐数组
        {
            res = max(res, right - left + 1); // 比下长度
        }
        right++;
    }
    return res;
}

// 这题没让返回子序列，只是看长度，而一个子序列中，也无所谓最大最小值的位置

// 既然如此，排序后再处理的结果和原结果其实是等价的，因为排序其实就相当于把子序列里的那些值给揪出来放到前面

// 那这样，就可以扫描排序后的数组，对于那些满足和谐数组定义的，就记录它们的长度，然后选一个最大值

// 这他妈是简单？