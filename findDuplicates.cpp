/*
给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次 。请你找出所有出现 两次 的整数，并以数组形式返回。

你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。

 

示例 1：

输入：nums = [4,3,2,7,8,2,3,1]
输出：[2,3]
示例 2：

输入：nums = [1,1,2]
输出：[1]
示例 3：

输入：nums = [1]
输出：[]
 

提示：

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
nums 中的每个元素出现 一次 或 两次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-duplicates-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;


vector<int> findDuplicates(vector<int>& nums) 
{
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        while(nums[i] != nums[nums[i] - 1]) //这里是while而不是if, 因为要保证一直去换, 而不是只换一次就完事了
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    vector<int> res;
    for(int i = 0; i < n; i++) 
    {
        if(nums[i] != i + 1)
        {
            res.push_back(nums[i]);
        }
    }
    return res;
}


// 重点在于元素大小的范围是1,n的, 那么就是说, 如果没有重复元素的话, 应该每个元素恰好就能放到第i个位置上面去

// 因此, 就要两遍遍历, 第一遍去放置元素, 第二遍去判断哪些位置上的元素不对劲

// 第一遍放置的时候就是, 某个元素为i, 那么其位置就是第i个, 那么就把当前第i个位置上的元素和某个元素交换下位置

// 但注意的是, 一次交换完之后,因为我们遍历是按照元素而不是位置去遍历的, 因此还要关心把这个元素交换走了之后, 新的元素是不是也得换下

// 那么就需要用while而非if, 一直去交换