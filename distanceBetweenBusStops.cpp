/*
环形公交路线上有 n 个站，按次序从 0 到 n - 1 进行编号。我们已知每一对相邻公交站之间的距离，distance[i] 表示编号为 i 的车站和编号为 (i + 1) % n 的车站之间的距离。

环线上的公交车都可以按顺时针和逆时针的方向行驶。

返回乘客从出发点 start 到目的地 destination 之间的最短距离。

 

示例 1：



输入：distance = [1,2,3,4], start = 0, destination = 1
输出：1
解释：公交站 0 和 1 之间的距离是 1 或 9，最小值是 1。
 

示例 2：



输入：distance = [1,2,3,4], start = 0, destination = 2
输出：3
解释：公交站 0 和 2 之间的距离是 3 或 7，最小值是 3。
 

示例 3：



输入：distance = [1,2,3,4], start = 0, destination = 3
输出：4
解释：公交站 0 和 3 之间的距离是 6 或 4，最小值是 4。
 

提示：

1 <= n <= 10^4
distance.length == n
0 <= start, destination < n
0 <= distance[i] <= 10^4
通过次数20,613提交次数34,254

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/distance-between-bus-stops
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;


int distanceBetweenBusStops(vector<int>& distance, int start, int destination) 
{
    int n = distance.size();
    int accm1 = 0, accm2 = 0;
    for(int i = start; i != destination; i = (i + 1) % n) accm1 += distance[i];
    for(int i = destination; i != start; i = (i + 1) % n) accm2 += distance[i];
    return min(accm1, accm2);
}

// emm反正就是走一圈, 看哪个半圈路程短, 别想太复杂了, 直接模拟