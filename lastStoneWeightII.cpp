/*
有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

 

示例 1：

输入：stones = [2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
示例 2：

输入：stones = [31,26,33,21,40]
输出：5
示例 3：

输入：stones = [1,2]
输出：1
 

提示：

1 <= stones.length <= 30
1 <= stones[i] <= 100


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/last-stone-weight-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

int lastStoneWeightII(vector<int>& stones) 
{
    int n = stones.size(), sum = 0;
    for(int stone : stones)
    {
        sum += stone;
    }
    //目标是要凑出一半的重量
    vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1, false));
    dp[0][0] = true;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= sum / 2; j ++)
        {
            if(j < stones[i - 1]) // 不选
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - stones[i - 1]]; // 要是能选的话，得同时考虑两边，类似于max
                // 这种bool型dp的转移还是第一次见
            }
        }
    }
    for(int j = sum / 2; j >= 0; j--)
    {
        if(dp[n][j]) // 只要为true，就是目前较优的情况
        {
            return sum - 2 * j;
        } 
    }
}

// 淦 有一种好像能写的错觉

// 转化成背包确实有点强，但这和昨天那题是一样的；归根结底实际上就是考察选哪些石头能逼近 sum / 2这个重量的

// 那么就定义 dp为前i个石头里是否能组成的重量j

// 之后的操作就是考察石头究竟选还是不选

// 最后返回时，也是从高到低逐个考察，如果为true了那就直接返回；最好的情况就是j = sum / 2，此时就是0

// 这也太强了