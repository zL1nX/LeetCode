/*
给定平面上 n 对 互不相同 的点 points ，其中 points[i] = [xi, yi] 。回旋镖 是由点 (i, j, k) 表示的元组 ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。

返回平面上所有回旋镖的数量。

 
示例 1：

输入：points = [[0,0],[1,0],[2,0]]
输出：2
解释：两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
示例 2：

输入：points = [[1,1],[2,2],[3,3]]
输出：2
示例 3：

输入：points = [[1,1]]
输出：0
 

提示：

n == points.length
1 <= n <= 500
points[i].length == 2
-104 <= xi, yi <= 104
所有点都 互不相同
通过次数24,829提交次数40,009

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-boomerangs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <math.h>
#include <unordered_map>
using namespace std;

int numberOfBoomerangs(vector<vector<int>>& points) 
{
    int res = 0;
    for(int i = 0; i < points.size(); i++) 
    {
        vector<int> point = points[i];
        unordered_map<double, int> rec;
        for(int j = 0; j < points.size(); j++) // 注意要把每个点都能遍历到
        {
            if(i == j) continue;
            double distance = sqrt(pow((point[0] - points[j][0]), 2) + pow((point[1] - points[j][1]), 2));
            rec[distance]++;
        }
        for(auto dat : rec)
        {
            int cnt = dat.second;
            res += cnt * (cnt - 1); // 注意是A(n, 2)
        }
    }
    return res;
}

// 依次考察每个点和其他所有点的距离，用哈希表存储每个距离对应的点的数量

// 最终由于只需要两个点即可，因此可以直接按照A(n,2)进行计算

// 注意回旋镖的数量和顺序有关，所以是A(n,2)而非C(n,2)，同时注意到要把每个点都遍历到