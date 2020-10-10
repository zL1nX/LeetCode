/*

给你一个整数数组 nums，请你返回其中位数为 偶数 的数字的个数。

 

示例 1：

输入：nums = [12,345,2,6,7896]
输出：2
解释：
12 是 2 位数字（位数为偶数） 
345 是 3 位数字（位数为奇数）  
2 是 1 位数字（位数为奇数） 
6 是 1 位数字 位数为奇数） 
7896 是 4 位数字（位数为偶数）  
因此只有 12 和 7896 是位数为偶数的数字
示例 2：

输入：nums = [555,901,482,1771]
输出：1 
解释： 
只有 1771 是位数为偶数的数字。
 

提示：

1 <= nums.length <= 500
1 <= nums[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-numbers-with-even-number-of-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>
using namespace std;

int findNumbers(vector<int>& nums) 
{
    int cnt = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        string s = to_string(nums[i]);
        cnt += s.length() % 2 == 0 ? 1 : 0;
    }
    return cnt;
}

/*
int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int num: nums) {
            if ((int)(log10(num) + 1) % 2 == 0) {
                ++ans;
            }
        }
        return ans;
    }

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/find-numbers-with-even-number-of-digits/solution/tong-ji-wei-shu-wei-ou-shu-de-shu-zi-by-leetcode-s/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/