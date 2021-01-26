/*
给你一个由一些多米诺骨牌组成的列表 dominoes。

如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。

形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a==c 且 b==d，或是 a==d 且 b==c。

在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。

 

示例：

输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
输出：1
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;

// 诚然，可以直接双层遍历写循环，但估计会超时

// 因此有两种思想来表示等价：找到一对后直接计算组合数，或者将每个骨牌表示成唯一的数字

int numEquivDominoPairs(vector<vector<int>>& dominoes) 
{
    unordered_map<int, int> sums;
    int cnt = 0;
    for(int i = 0; i < dominoes.size(); i++)
    {
        sort(dominoes[i].begin(), dominoes[i].end());
        int t = dominoes[i][0] * 10 + dominoes[i][1];
        sums[t]++;
    }
    for(auto it : sums)
    {
        cnt += (it.second - 1) * it.second / 2;
    }
    return cnt;
}