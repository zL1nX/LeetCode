/*
给定2D空间中四个点的坐标 p1, p2, p3 和 p4，如果这四个点构成一个正方形，则返回 true 。

点的坐标 pi 表示为 [xi, yi] 。输入 不是 按任何顺序给出的。

一个 有效的正方形 有四条等边和四个等角(90度角)。

 

示例 1:

输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
输出: True
示例 2:

输入：p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
输出：false
示例 3:

输入：p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
输出：true
 

提示:

p1.length == p2.length == p3.length == p4.length == 2
-104 <= xi, yi <= 104


来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/valid-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int distance(vector<int>& a, vector<int>& b)
{
    int p = abs(a[0] - b[0]), q = abs(a[1] - b[1]);
    return p * p + q * q;
}


bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) 
{
    vector<vector<int>> points = {p1, p2, p3, p4};
    vector<int> dist;
    for(int i = 0; i < 4; i++)
    {
        for(int j = i + 1; j < 4; j++)
        {
            int d = distance(points[i], points[j]);
            if(d == 0) return false;
            dist.push_back(d);
        }
    }
    sort(dist.begin(), dist.end());
    for(int i = 0; i < 3; i++)
    {
        if(dist[i + 1] != dist[i])
        {
            return false;
        }
    }
    return (dist[4] == dist[5]) && dist[4] == (2 * dist[3]);

}

// 不想枚举, 所以就写的稍微啰嗦了点, 直接根据定义判断: 四边相等且对角线相等