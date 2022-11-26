/*
给你一个正整数组成的数组 nums ，返回 nums 中一个 升序 子数组的最大可能元素和。

子数组是数组中的一个连续数字序列。

已知子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，若对所有 i（l <= i < r），numsi < numsi+1 都成立，则称这一子数组为 升序 子数组。注意，大小为 1 的子数组也视作 升序 子数组。

 

示例 1：

输入：nums = [10,20,30,5,10,50]
输出：65
解释：[5,10,50] 是元素和最大的升序子数组，最大元素和为 65 。
示例 2：

输入：nums = [10,20,30,40,50]
输出：150
解释：[10,20,30,40,50] 是元素和最大的升序子数组，最大元素和为 150 。 
示例 3：

输入：nums = [12,17,15,13,10,11,12]
输出：33
解释：[10,11,12] 是元素和最大的升序子数组，最大元素和为 33 。 
示例 4：

输入：nums = [100,10,1]
输出：100
 

提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100
通过次数18,858提交次数27,347

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-ascending-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <iostream>
using namespace std;

int maxAscendingSum(vector<int>& nums) 
{
    int curr = 0, p = curr + 1, res = nums[curr], n = nums.size();
    while(curr < n && p < n)
    {
        int accm = nums[curr];
        while(p < n && nums[p] > nums[p - 1])
        {
            accm += nums[p];
            p++;
        }
        res = max(accm, res);
        if(p < n)
        {
            curr = p; p = curr + 1;
        }
    }
    return res;
}

/*
class Solution {
    public int maxAscendingSum(int[] nums) {
        int n = nums.length, ans = nums[0];
        for (int i = 1, cur = nums[0]; i < n; i++) {
            if (nums[i] > nums[i - 1]) cur += nums[i];
            else cur = nums[i];
            ans = Math.max(ans, cur);
        }
        return ans;
    }
}

作者：AC_OIer
链接：https://leetcode.cn/problems/maximum-ascending-subarray-sum/solution/by-ac_oier-2q6o/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

int main()
{
    vector<int> nums = {10,20,30,5,10,50};
    cout << maxAscendingSum(nums) << endl;
}

// 1800. 最大升序子数组和