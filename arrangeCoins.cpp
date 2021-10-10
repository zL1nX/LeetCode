/*
你总共有 n 枚硬币，并计划将它们按阶梯状排列。对于一个由 k 行组成的阶梯，其第 i 行必须正好有 i 枚硬币。阶梯的最后一行 可能 是不完整的。

给你一个数字 n ，计算并返回可形成 完整阶梯行 的总行数。

 

示例 1：


输入：n = 5
输出：2
解释：因为第三行不完整，所以返回 2 。
示例 2：


输入：n = 8
输出：3
解释：因为第四行不完整，所以返回 3 。
 

提示：

1 <= n <= 231 - 1
通过次数52,883提交次数120,888

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/arranging-coins
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

int arrangeCoins(int n) 
{
    long long sum = 0, level = 0, k = 1;
    while(sum <= n)
    {
        level++;
        sum += k++;
    }
    return level - 1;
}

// 直接写就好，当然也可以去解那个二元一次方程的根，也是一个意思，只不过懒得推了
