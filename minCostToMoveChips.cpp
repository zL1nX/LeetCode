/*
数轴上放置了一些筹码，每个筹码的位置存在数组 chips 当中。

你可以对 任何筹码 执行下面两种操作之一（不限操作次数，0 次也可以）：

将第 i 个筹码向左或者右移动 2 个单位，代价为 0。
将第 i 个筹码向左或者右移动 1 个单位，代价为 1。
最开始的时候，同一位置上也可能放着两个或者更多的筹码。

返回将所有筹码移动到同一位置（任意位置）上所需要的最小代价。

 

示例 1：

输入：chips = [1,2,3]
输出：1
解释：第二个筹码移动到位置三的代价是 1，第一个筹码移动到位置三的代价是 0，总代价为 1。
示例 2：

输入：chips = [2,2,2,3,3]
输出：2
解释：第四和第五个筹码移动到位置二的代价都是 1，所以最小总代价为 2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-to-move-chips-to-the-same-position
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

int minCostToMoveChips(vector<int>& position) 
{
    int odd = 0, even = 0;
    for(int i = 0; i < position.size(); i ++)
    {
        if(position[i] % 2)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    return min(odd, even);
}

// 奇数位置移到奇数位置无代价，偶数位数移到偶数位置无代价，奇数位置移到偶数位置的代价为1
// 因此把所有奇数移到一个奇数上，所有偶数移到一个偶数上，同时比较有多少个奇数和多少个偶数
// 因此把少的那方移到多的那方上就是总的最小代价
// 因此统计少的那方的个数 * 1就是最终的结果