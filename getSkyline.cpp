/*
城市的天际线是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。给你所有建筑物的位置和高度，请返回由这些建筑物形成的 天际线 。

每个建筑物的几何信息由数组 buildings 表示，其中三元组 buildings[i] = [lefti, righti, heighti] 表示：

lefti 是第 i 座建筑物左边缘的 x 坐标。
righti 是第 i 座建筑物右边缘的 x 坐标。
heighti 是第 i 座建筑物的高度。
天际线 应该表示为由 “关键点” 组成的列表，格式 [[x1,y1],[x2,y2],...] ，并按 x 坐标 进行 排序 。关键点是水平线段的左端点。列表中最后一个点是最右侧建筑物的终点，y 坐标始终为 0 ，仅用于标记天际线的终点。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。

注意：输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 是不正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]

 

示例 1：


输入：buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
输出：[[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
解释：
图 A 显示输入的所有建筑物的位置和高度，
图 B 显示由这些建筑物形成的天际线。图 B 中的红点表示输出列表中的关键点。
示例 2：

输入：buildings = [[0,2,3],[2,5,3]]
输出：[[0,3],[5,0]]
 

提示：

1 <= buildings.length <= 104
0 <= lefti < righti <= 231 - 1
1 <= heighti <= 231 - 1
buildings 按 lefti 非递减排序

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-skyline-problem
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
{
    auto comp = [](const pair<int, int>&a, const pair<int, int>&b)->bool
    {
        return a.second < b.second;
    };

    vector<int> boundaries;
    for(auto& building : buildings)
    {
        boundaries.emplace_back(building[0]); // left
        boundaries.emplace_back(building[1]); // right
    }
    sort(boundaries.begin(), boundaries.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> que(comp); // 大顶堆

    vector<vector<int>> res;
    int idx = 0, n = buildings.size();
    for(auto& boundary : boundaries)
    {
        while(idx < n && buildings[idx][0] <= boundary) // 被哪些建筑所包含
        {
            que.emplace(buildings[idx][1], buildings[idx][2]); // 右边界和高度
            idx++;

        }
        while(!que.empty() && que.top().first <= boundary) // 看哪些建筑的右边界，即哪些建筑不被这个boundary包含
        {
            que.pop();
        }
        int maxn = que.empty() ? 0 : que.top().second; // 此时这个队首元素就为满足元素的最大值
        if(res.size() == 0 || maxn != res.back()[1]) // 高度相同的点无效
        {
            res.push_back({boundary, maxn}); // 最后的maxn就是优先队列中的最大值
            // 以每个boundary为考察单位，看有哪些建筑包含这个boundary，并考察它们的最高
        }
    }
    return res;
}

// 淦 完了肯定还会见面