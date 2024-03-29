/*
给你 k 枚相同的鸡蛋，并可以使用一栋从第 1 层到第 n 层共有 n 层楼的建筑。

已知存在楼层 f ，满足 0 <= f <= n ，任何从 高于 f 的楼层落下的鸡蛋都会碎，从 f 楼层或比它低的楼层落下的鸡蛋都不会破。

每次操作，你可以取一枚没有碎的鸡蛋并把它从任一楼层 x 扔下（满足 1 <= x <= n）。如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中 重复使用 这枚鸡蛋。

请你计算并返回要确定 f 确切的值 的 最小操作次数 是多少？

 
示例 1：

输入：k = 1, n = 2
输出：2
解释：
鸡蛋从 1 楼掉落。如果它碎了，肯定能得出 f = 0 。 
否则，鸡蛋从 2 楼掉落。如果它碎了，肯定能得出 f = 1 。 
如果它没碎，那么肯定能得出 f = 2 。 
因此，在最坏的情况下我们需要移动 2 次以确定 f 是多少。 
示例 2：

输入：k = 2, n = 6
输出：3
示例 3：

输入：k = 3, n = 14
输出：4
 

提示：

1 <= k <= 100
1 <= n <= 104
通过次数70,953提交次数234,638

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/super-egg-drop
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int superEggDrop(int k, int n) 
{
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0)); //
    int m = 0;
    while (dp[k][m] < n)
    {
        m++;
        for(int c = 1; c <= k; c++)
        {
            dp[c][m] = dp[c][m - 1] + dp[c - 1][m - 1] + 1;
        }
    }
    return m;
}


// 887-鸡蛋掉落

// 首先这个题就很奇怪: 为了确认f去扔鸡蛋的最坏情况下的最小尝试次数; 最坏指的是:

// 鸡蛋破碎发生在搜索穷尽之时, 一个直观的dp定义就是, dp[k][n] = m, 表示当前手里有k个鸡蛋, 要测试n层楼, 此时的结果为m次

// 此时的状态转移就需要用类似于二分的方法去上下查找, 然后取max的min (因为是最坏情况下的最小值)

// 但是这里用了一种非常诡谲的dp定义, 即dp[k][m] = n, m表示最终的结果, 而我们的状态转移也是帮我们找到一个索引m使得dp[k][m] 等于最终的N

// 这大大简化了状态转移的过程, 但思维还是很奇怪的