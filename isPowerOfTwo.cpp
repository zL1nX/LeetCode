/*
给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。

如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。

 

示例 1：

输入：n = 1
输出：true
解释：20 = 1
示例 2：

输入：n = 16
输出：true
解释：24 = 16
示例 3：

输入：n = 3
输出：false
示例 4：

输入：n = 4
输出：true
示例 5：

输入：n = 5
输出：false
 

提示：

-231 <= n <= 231 - 1
 

进阶：你能够不使用循环/递归解决此问题吗？

通过次数119,125提交次数240,485

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-two
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;


bool isPowerOfTwo(int n) 
{
    int appeared = 0;
    for(int k = 31; k >= 0; k --)
    {
        appeared += (n >> k) & 1;
    }
    return n >= 0 && appeared == 1;
    
}

// 2的幂只会有1个1，其余位全部是0

// 只要对每个位遍历确保最后只有1个1就好

// 但同时，要记得2的幂大于0（流汗黄豆），所以也得确保大于0