/*
你正在参加一个多角色游戏，每个角色都有两个主要属性：攻击 和 防御 。给你一个二维整数数组 properties ，其中 properties[i] = [attacki, defensei] 表示游戏中第 i 个角色的属性。

如果存在一个其他角色的攻击和防御等级 都严格高于 该角色的攻击和防御等级，则认为该角色为 弱角色 。更正式地，如果认为角色 i 弱于 存在的另一个角色 j ，那么 attackj > attacki 且 defensej > defensei 。

返回 弱角色 的数量。

 

示例 1：

输入：properties = [[5,5],[6,3],[3,6]]
输出：0
解释：不存在攻击和防御都严格高于其他角色的角色。
示例 2：

输入：properties = [[2,2],[3,3]]
输出：1
解释：第一个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
示例 3：

输入：properties = [[1,5],[10,4],[4,3]]
输出：1
解释：第三个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
 

提示：

2 <= properties.length <= 105
properties[i].length == 2
1 <= attacki, defensei <= 105
通过次数7,304提交次数24,690

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-number-of-weak-characters-in-the-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int numberOfWeakCharacters(vector<vector<int>>& properties) 
{
    sort(properties.begin(), properties.end(), [&](vector<int>& a, vector<int>& b){
        return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
    });
    int cnt = 0, maxdef = INT_MIN;
    for(int i = 0; i < properties.size(); i++)
    {
        if(maxdef > properties[i][1])
        {
            cnt++;
        }
        else
        {
            maxdef = properties[i][1];
        }
    }
    return cnt;
}

// 先按攻击力降序排序，再按防御力升序排序

// 由此， 在正向遍历每个properties时，当前角色的攻击的攻击力一定是比刚才遍历的角色攻击力小的

// 而又因为防御力是升序排序的，因此可以维护一个maxdef，即最大防御值，在遍历时，如果当前角色的def小于maxdef，同时他的攻击力一定是小于maxdef对应角色的攻击力的

// 因为攻击力是降序排序的。所以当前角色一定是一个弱角色

// 那么就可以进行计数，之后如果碰见def更大的，那么就去更新maxdef，因为在攻击力降序排序的条件下，我们只需要操心def的大小即可，只要找到def更小的就行

// 这种二维排序的还挺有意思