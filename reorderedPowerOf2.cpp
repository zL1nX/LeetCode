/*
给定正整数 N ，我们按任何顺序（包括原始顺序）将数字重新排序，注意其前导数字不能为零。

如果我们可以通过上述方式得到 2 的幂，返回 true；否则，返回 false。

 

示例 1：

输入：1
输出：true
示例 2：

输入：10
输出：false
示例 3：

输入：16
输出：true
示例 4：

输入：24
输出：false
示例 5：

输入：46
输出：true
 

提示：

1 <= N <= 10^9
通过次数9,991提交次数16,576

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reordered-power-of-2
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>

using namespace std;

vector<int> visited;

bool isPowerOfTwo(int n)
{
    return (n & (n - 1)) == 0;
}

bool backtrack(string& nums, int idx, int num)
{
    if(idx == nums.size())
    {
        return isPowerOfTwo(num);
    }
    for(int i = 0; i < nums.size(); i++) // 每次都从头遍历，即重新选一位出来加到已有的nums上
    {
        // 这条件就是，对于相同的连续的几个数字，确保前面的没选过，自己才能被选；以及自己确实也没被选过，以及不能有前导0
        if((i > 0 && nums[i - 1] == nums[i] && visited[i - 1] == 0) || visited[i] || (num == 0 && nums[i] == '0'))
        {
            continue;
        }
        visited[i] = 1; // 先标记
        if(backtrack(nums, idx + 1, num * 10 + (nums[i] - '0'))) // 已选数字的累加
        {
            return true;
        }
        visited[i] = 0; // 再取消，实现递归的回溯
    }
    return false;
}

bool reorderedPowerOf2(int n) 
{
    string nums = to_string(n);
    visited.resize(nums.size());
    sort(nums.begin(), nums.end()); // 排序，保证相同数字都相邻
    return backtrack(nums, 0, 0);
}