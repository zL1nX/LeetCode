/*
给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点。求最多有多少个点在同一条直线上。

 

示例 1：


输入：points = [[1,1],[2,2],[3,3]]
输出：3
示例 2：


输入：points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
输出：4
 

提示：

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
points 中的所有点 互不相同
通过次数30,822提交次数106,208

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-points-on-a-line
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>

using namespace std;

int maxPoints(vector<vector<int>>& points) 
{
    int n = points.size();
    if(n < 3) // 不够3个点时显然就是n本身
    {
        return n;
    }
    int maxn = 2;
    for(int i = 0; i < n; i++)
    {
        unordered_map<double, int> k; //用哈希表来存储斜率
        for(int j = i + 1; j < n; j++)
        {
            long long deltax = points[j][0] - points[i][0];
            long long deltay = points[j][1] - points[i][1];
            double g = deltax ? deltay * 1.0 / deltax : INT_MAX * 1.0; // 若dx为0，则设置为最大值
            if(k.count(g))
            {
                k[g] ++;
            }
            else
            {
                k[g] = 2; //一种斜率至少对应了两个点
            }
            maxn = max(k[g], maxn);            
        }
    }
    return maxn;
}

// 朴素解法就是，对于每两个点算出的一个斜率，遍历剩余的点计算下斜率是否相等，若相等则记录；
// 但在遍历过程中，有很多计算都是多余的，完全可以用哈希表来记忆以及存储下，完了再比；不一定非得遍历的时候就都比完
// 这题感觉很像面试会考的题
// 有一个点在于希望规避精度损失，但double感觉能提供足够的精度空间了
