/*
给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi] 表示一个坐标轴平行的矩形。这个矩形的左下顶点是 (xi, yi) ，右上顶点是 (ai, bi) 。

如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；否则，返回 false 。

 
示例 1：


输入：rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
输出：true
解释：5 个矩形一起可以精确地覆盖一个矩形区域。 
示例 2：


输入：rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
输出：false
解释：两个矩形之间有间隔，无法覆盖成一个矩形。
示例 3：


输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
输出：false
解释：因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。
 

提示：

1 <= rectangles.length <= 2 * 104
rectangles[i].length == 4
-105 <= xi, yi, ai, bi <= 105
通过次数
27.9K
提交次数
60.5K
通过率
46.1%
*/

#include <vector>
#include <set>

using namespace std;

bool isRectangleCover(vector<vector<int>>& rectangles) 
{
    int X1 = INT_MAX, Y1 = INT_MAX, X2 = INT_MIN, Y2 = INT_MIN;
    long long area = 0;
    set<pair<int, int>> points;

    for(vector<int>& rec : rectangles)
    {
        int x1 = rec[0], y1 = rec[1], x2 = rec[2], y2 = rec[3];
        X1 = min(X1, x1); Y1 = min(Y1, y1);
        X2 = max(X2, x2); Y2 = max(Y2, y2);
        area += (long long)(x2 - x1) * (y2 - y1); // 这里和下面的面积都需要注意下整数溢出的情况

        pair<int, int> p1(x1, y1), p2(x1, y2), p3(x2, y2), p4(x2, y1);
        for(auto p : {p1, p2, p3, p4})
        {
            if(points.count(p))
            {
                points.erase(p);
            }
            else
            {
                points.insert(p);
            }
        }
    }

    long long whole_area = (long long)(X2 - X1) * (Y2 - Y1);
    if(whole_area != area)
    {
        return false; // 即使等于, 也没法说明是完美矩形
    }

    if(points.size() != 4)
    {
        return false; // 最后重叠下来得恰好是4个顶点
    }

    pair<int, int> P1(X1, Y1), P2(X1, Y2), P3(X2, Y2), P4(X2, Y1);
    for(auto P : {P1, P2, P3, P4})
    {
        if(!points.count(P))
        {
            return false; // 剩下的这四个顶点, 还得刚好是理论上的四个边界顶点
        }
    }

    return true;
}

// 391-完美矩形