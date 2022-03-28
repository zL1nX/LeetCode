/*
给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。

 

示例 1：

输入：n = 5
输出：true
解释：5 的二进制表示是：101
示例 2：

输入：n = 7
输出：false
解释：7 的二进制表示是：111.
示例 3：

输入：n = 11
输出：false
解释：11 的二进制表示是：1011.
 

提示：

1 <= n <= 231 - 1
通过次数37,095提交次数59,134

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-number-with-alternating-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

bool hasAlternatingBits(int n) 
{
    int last = n & 1;
    n >>= 1;
    while(n)
    {
        int cur = n & 1;
        if(cur == last)
        {
            return false;
        }
        last = cur;
        n >>= 1;
    }
    return true;
}

// 模拟实现即可