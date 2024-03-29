/*
电子游戏“辐射4”中，任务 “通向自由” 要求玩家到达名为 “Freedom Trail Ring” 的金属表盘，并使用表盘拼写特定关键词才能开门。

给定一个字符串 ring ，表示刻在外环上的编码；给定另一个字符串 key ，表示需要拼写的关键词。您需要算出能够拼写关键词中所有字符的最少步数。

最初，ring 的第一个字符与 12:00 方向对齐。您需要顺时针或逆时针旋转 ring 以使 key 的一个字符在 12:00 方向对齐，然后按下中心按钮，以此逐个拼写完 key 中的所有字符。

旋转 ring 拼出 key 字符 key[i] 的阶段中：

您可以将 ring 顺时针或逆时针旋转 一个位置 ，计为1步。旋转的最终目的是将字符串 ring 的一个字符与 12:00 方向对齐，并且这个字符必须等于字符 key[i] 。
如果字符 key[i] 已经对齐到12:00方向，您需要按下中心按钮进行拼写，这也将算作 1 步。按完之后，您可以开始拼写 key 的下一个字符（下一阶段）, 直至完成所有拼写。
 

示例 1：



 
输入: ring = "godding", key = "gd"
输出: 4
解释:
 对于 key 的第一个字符 'g'，已经在正确的位置, 我们只需要1步来拼写这个字符。 
 对于 key 的第二个字符 'd'，我们需要逆时针旋转 ring "godding" 2步使它变成 "ddinggo"。
 当然, 我们还需要1步进行拼写。
 因此最终的输出是 4。
示例 2:

输入: ring = "godding", key = "godding"
输出: 13
 

提示：

1 <= ring.length, key.length <= 100
ring 和 key 只包含小写英文字母
保证 字符串 key 一定可以由字符串  ring 旋转拼出
通过次数24,065提交次数47,415

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/freedom-trail
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

unordered_map<char, vector<char>> keyIndex;
vector<vector<int>> memo;

int findRotateSteps(string ring, string key) 
{
    int m = ring.size(), n = key.size();
    memo.resize(m, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
    {
        keyIndex[ring[i]].push_back(i); // 直接存储每个key所在的index, 方便在拨动时直接定位要拨的key和当前ring
    }
    return dp(ring, 0, key, 0);
}

int dp(string& ring, int i, string& key, int j)
{
    if(j == key.size())
    {
        return 0;
    }
    if(memo[i][j] != 0)
    {
        return memo[i][j];
    }
    int res = INT_MAX, m = ring.size();
    for(int c : keyIndex[key[j]])
    {
        int dist = abs(c - i);
        dist = min(dist, m - dist); // 顺时针和逆时针两种路径
        res = min(res, dist + 1 + dp(ring, c, key, j + 1)); // 需要从上一个地方拨到k这个位置, 这样当前k才能拨到i那个地方
    }
    memo[i][j] = res;
    return res;
}

// 514-自由之路

// dp的这个操作确实比较难想, 但归根到底还是明确状态是什么, 选择时最差也可以直接暴力

// 