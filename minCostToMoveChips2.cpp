/*
有 n 个筹码。第 i 个筹码的位置是 position[i] 。

我们需要把所有筹码移到同一个位置。在一步中，我们可以将第 i 个筹码的位置从 position[i] 改变为:

position[i] + 2 或 position[i] - 2 ，此时 cost = 0
position[i] + 1 或 position[i] - 1 ，此时 cost = 1
返回将所有筹码移动到同一位置上所需要的 最小代价 。

 

示例 1：



输入：position = [1,2,3]
输出：1
解释：第一步:将位置3的筹码移动到位置1，成本为0。
第二步:将位置2的筹码移动到位置1，成本= 1。
总成本是1。
示例 2：



输入：position = [2,2,2,3,3]
输出：2
解释：我们可以把位置3的两个筹码移到位置2。每一步的成本为1。总成本= 2。
示例 3:

输入：position = [1,1000000000]
输出：1
 

提示：

1 <= chips.length <= 100
1 <= chips[i] <= 10^9
通过次数50,652提交次数67,838

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-cost-to-move-chips-to-the-same-position
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

int minCostToMoveChips(vector<int>& position) 
{
    int even = 0, odd = 0;
    for(int i = 0; i < position.size(); i++)
    {
        if(position[i] % 2 == 0) even ++;
        else odd++;
    }
    return min(odd, even);
}

// 1217-玩筹码

// 不要局限与单纯的奇偶性, 而是要看整个的偶和整个的奇偶

// 只要相隔两个就是没开销, 所以奇数移到奇数 偶数移到偶数都没代价

// 所以就是看奇偶的个数谁小了, 因为可以先相当于把所有的奇数移到一个奇数上, 所有的偶数移到一个偶数上

// 最后谁移到谁那就是看谁的个数少了