/*
我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。

（这里，平面上两点之间的距离是欧几里德距离。）

你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。

 

示例 1：

输入：points = [[1,3],[-2,2]], K = 1
输出：[[-2,2]]
解释： 
(1, 3) 和原点之间的距离为 sqrt(10)，
(-2, 2) 和原点之间的距离为 sqrt(8)，
由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
示例 2：

输入：points = [[3,3],[5,-1],[-2,4]], K = 2
输出：[[3,3],[-2,4]]
（答案 [[-2,4],[3,3]] 也会被接受。）

*/
#include <vector>
#include <unordered_map>
using namespace std;

bool comp(pair<int, int> a, pair<int , int> b)
{
    return a.second > b.second;
}

int get_dis(vector<int> point)
{
    return point[0] * point[0] + point[1] * point[1];
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
{
    vector<pair<int, int>> dis;
    vector<vector<int>> res;
    for(int i = 0; i < points.size(); i ++)
    {
        dis.push_back(pair<int, int>(i, get_dis(points[i])));
    }
    sort(dis.begin(), dis.end(), comp);
    for(int i = 0;i < K; i++)
    {
        res.push_back(points[dis[i].first]);
    }
    return res;
}

/*

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] * u[0] + u[1] * u[1] < v[0] * v[0] + v[1] * v[1];
        });
        return {points.begin(), points.begin() + K};
    }
};

*/