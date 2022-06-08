/*
给定一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点，如果这些点构成一个 回旋镖 则返回 true 。

回旋镖 定义为一组三个点，这些点 各不相同 且 不在一条直线上 。

 

示例 1：

输入：points = [[1,1],[2,3],[3,2]]
输出：true
示例 2：

输入：points = [[1,1],[2,2],[3,3]]
输出：false
 

提示：

points.length == 3
points[i].length == 2
0 <= xi, yi <= 100
通过次数15,845提交次数34,017

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/valid-boomerang
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <math.h>
using namespace std;

double getDistance(vector<int>& a, vector<int>& b)
{

}

bool isBoomerang(vector<vector<int>>& points) 
{
    vector<int> a = points[0], b = points[1], c = points[2];
    return (a[0]-b[0]) * (a[1] - c[1]) != (a[0]-c[0]) * (a[1] - b[1]);
}

// 按照定义不就是直接判断斜率即可

// 如果有点在一条直线上, 式子两边均为0了同样是true

// 保险的方法还是直接算三角形面积, 就是直接用三个坐标算的方法