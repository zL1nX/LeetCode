/*
给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。

示例:
输入: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
输出: 2
解释: 
这五个点如下图所示。组成的橙色三角形是最大的，面积为2。


注意:

3 <= points.length <= 50.
不存在重复的点。
 -50 <= points[i][j] <= 50.
结果误差值在 10^-6 以内都认为是正确答案。
通过次数16,025提交次数24,615

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/largest-triangle-area
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <vector>
#include <math.h>
using namespace std;

double triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)); // 行列式展开 别忘了x2系数的正负
}


double largestTriangleArea(vector<vector<int>>& points) 
{
    int n = points.size();
    double res = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                double cur = triangle(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]);
                res = max(res, cur);
            }
        }
    }
    return res;
}

// 麻了 暴力其实就行, 所以核心就在于已知三点坐标如何求三角形面积

// 然后发现就是行列式展开