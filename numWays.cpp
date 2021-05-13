/*
有一个长度为 arrLen 的数组，开始有一个指针在索引 0 处。

每一步操作中，你可以将指针向左或向右移动 1 步，或者停在原地（指针不能被移动到数组范围外）。

给你两个整数 steps 和 arrLen ，请你计算并返回：在恰好执行 steps 次操作以后，指针仍然指向索引 0 处的方案数。

由于答案可能会很大，请返回方案数 模 10^9 + 7 后的结果。

 

示例 1：

输入：steps = 3, arrLen = 2
输出：4
解释：3 步后，总共有 4 种不同的方法可以停在索引 0 处。
向右，向左，不动
不动，向右，向左
向右，不动，向左
不动，不动，不动
示例  2：

输入：steps = 2, arrLen = 4
输出：2
解释：2 步后，总共有 2 种不同的方法可以停在索引 0 处。
向右，向左
不动，不动
示例 3：

输入：steps = 4, arrLen = 2
输出：8
 

提示：

1 <= steps <= 500
1 <= arrLen <= 10^6
通过次数7,314提交次数15,634

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <math.h>
using namespace std;

int numWays(int steps, int arrLen) 
{
    int border = min(arrLen - 1, steps);
    long long modulus = pow(10, 9) + 7;
    vector<vector<int>> dp(steps + 1, vector<int>(border + 1)); // 多一个1，含义更明确
    dp[0][0] = 1; // 必然存在一个保持不动的方案
    for(int j = 1; j <= border; j++)
    {
        dp[0][j] = 0; // 除了j=0外，都不存在别的方案
    }

    for(int i = 1; i <= steps; i++)
    {
        for(int j = 0; j <= border; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(j - 1 >= 0) // 边界判断，记得取模
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % modulus;
            }
            if(j + 1 <= border) // 这种写法挺简练而且可靠的
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % modulus;
            }
        }
    }
    return dp[steps][0];
}

// dp[i][j] 表示i步之后，到达下标j的方案数

// 之后的状态转移方程就相对容易了

// 需要注意：边界条件dp[0][0] = 1 以及 dp[0][j] = 0; 以及在转移过程中下标的值

// 难度适中，要熟悉dp可以很快写出来（我不熟悉