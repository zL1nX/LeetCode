/*
给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

示例:

输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
通过次数28,739提交次数72,121

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/russian-doll-envelopes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <vector>
using namespace std;

int maxEnvelopes(vector<vector<int>>& envelopes) 
{
    if(envelopes.empty())
    {
        return 0;
    }
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), [](vector<int>& e1, vector<int>& e2){
        return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
    }); // 这里对高度降序排序是因为防止在找递增子序列时，找到宽度一样的，这样每种宽度就只能出一个信封了
    // 这个降序排序很强
    vector<int> inc(n, 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(envelopes[j][1] < envelopes[i][1])
            {
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }
    // 这里就是求最长递增子序列，其实打印一下vector内容就知道，每个元素都是其能形成的最长子序列的个数

    return *max_element(inc.begin(), inc.end());
}
// 感觉这题精髓还是在于排序+dp，我好菜