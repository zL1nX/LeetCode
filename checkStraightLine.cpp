/*
在一个 XY 坐标系中有一些点，我们用数组 coordinates 来分别记录它们的坐标，其中 coordinates[i] = [x, y] 表示横坐标为 x、纵坐标为 y 的点。

请你来判断，这些点是否在该坐标系中属于同一条直线上，是则返回 true，否则请返回 false。

 

示例 1：



输入：coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
输出：true
示例 2：



输入：coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
输出：false
 

提示：

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates 中不含重复的点

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-it-is-a-straight-line
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <math.h>
using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) 
{
    double ax = coordinates[0][0], ay = coordinates[0][1];
    double bx = coordinates[1][0], by = coordinates[1][1];
    double k1 = (coordinates[1][1] - by)/(coordinates[1][0] - bx);
    for(int i = 2; i < coordinates.size(); i++)
    {
        int cx = coordinates[i][0], cy = coordinates[i][1];
        double k1 = (cy - by) * (bx - ax), k2 = (by - ay) * (cx - bx); // 由于double的精度问题，因此转换成乘法；同时，题目中点的顺序并不是有序的，因此实际上这是判定三点共线的问题
        if(abs(k1) != abs(k2))
        {
            return false;
        }
    }
    return true;
}