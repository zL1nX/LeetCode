/*
给你一个点数组 points 和一个表示角度的整数 angle ，你的位置是 location ，其中 location = [posx, posy] 且 points[i] = [xi, yi] 都表示 X-Y 平面上的整数坐标。

最开始，你面向东方进行观测。你 不能 进行移动改变位置，但可以通过 自转 调整观测角度。换句话说，posx 和 posy 不能改变。你的视野范围的角度用 angle 表示， 这决定了你观测任意方向时可以多宽。设 d 为你逆时针自转旋转的度数，那么你的视野就是角度范围 [d - angle/2, d + angle/2] 所指示的那片区域。

对于每个点，如果由该点、你的位置以及从你的位置直接向东的方向形成的角度 位于你的视野中 ，那么你就可以看到它。

同一个坐标上可以有多个点。你所在的位置也可能存在一些点，但不管你的怎么旋转，总是可以看到这些点。同时，点不会阻碍你看到其他点。

返回你能看到的点的最大数目。

 

示例 1：



输入：points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
输出：3
解释：阴影区域代表你的视野。在你的视野中，所有的点都清晰可见，尽管 [2,2] 和 [3,3]在同一条直线上，你仍然可以看到 [3,3] 。
示例 2：

输入：points = [[2,1],[2,2],[3,4],[1,1]], angle = 90, location = [1,1]
输出：4
解释：在你的视野中，所有的点都清晰可见，包括你所在位置的那个点。
示例 3：



输入：points = [[1,0],[2,1]], angle = 13, location = [1,1]
输出：1
解释：如图所示，你只能看到两点之一。
 

提示：

1 <= points.length <= 105
points[i].length == 2
location.length == 2
0 <= angle < 360
0 <= posx, posy, xi, yi <= 100
通过次数3,968提交次数11,318

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-visible-points
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <math.h>
using namespace std;

int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) 
{
    vector<double> polar;
    int sameLoc = 0;
    for(vector<int>& point : points)
    {
        if(point[0] == location[0] && point[1] == location[1])
        {
            sameLoc ++;
            continue;
        }
        double pcord = atan2(point[1] - location[1], point[0] - location[0]);
        polar.push_back(pcord);
    }
    sort(polar.begin(), polar.end());
    int p = polar.size();
    for(int i = 0; i < p; i++)
    {
        polar.push_back(polar[i] + 2 * M_PI);
    }
    int maxCnt = 0;
    double degree = angle * M_PI / 180;
    for(int i = 0; i < p; i++)
    {
        auto loc = upper_bound(polar.begin() + i, polar.end(), polar[i] + degree);
        int cnt = loc - polar.begin() - i;
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt + sameLoc;

}

// 这道题真实开了眼了

// 在抽象上其实就是一个「范围内有多少点」的问题，而且可视化也很容易，但编程上实现就比较难了

// 首先面临的问题就是，极坐标转换，即把所有点都转换成以自己位置为原点的极坐标系中的极角坐标

// 转换后的做法就是，依次遍历每个点（排序后的，从小到大），然后以这个点为下界，转angle这么大的角度，即上界为这个点的极坐标 + angle，这段范围内有多少点

// 这一步就可以直接用二分查找

// 对每个点都这么遍历查找一次后，找出以谁为下界具有最多覆盖的点即可

// 但转换后还要注意，atan2的值域是-180到180，即所有点转换后的值必然在这个区间内，那么如果dpi + angle超过了这个上界该咋办呢

// dpi + angle超就超了呗，我们让点的值也一块超了，即每个点都加上360度，这样一来转了一圈，让点的值也变大了，就不会漏掉点了

// 最后这个+2pi还是有点问题