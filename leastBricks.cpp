/*
你的面前有一堵矩形的、由 n 行砖块组成的砖墙。这些砖块高度相同（也就是一个单位高）但是宽度不同。每一行砖块的宽度之和应该相等。

你现在要画一条 自顶向下 的、穿过 最少 砖块的垂线。如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。你不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的。

给你一个二维数组 wall ，该数组包含这堵墙的相关信息。其中，wall[i] 是一个代表从左至右每块砖的宽度的数组。你需要找出怎样画才能使这条线 穿过的砖块数量最少 ，并且返回 穿过的砖块数量 。

 

示例 1：


输入：wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
输出：2
示例 2：

输入：wall = [[1],[1],[1]]
输出：3
 
提示：

n == wall.length
1 <= n <= 104
1 <= wall[i].length <= 104
1 <= sum(wall[i].length) <= 2 * 104
对于每一行 i ，sum(wall[i]) 应当是相同的
1 <= wall[i][j] <= 231 - 1
通过次数21,773提交次数51,631

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/brick-wall
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;

int leastBricks(vector<vector<int>>& wall) 
{  
    unordered_map<int, int> mid_gap;
    int result = 0;
    for(int i = 0; i < wall.size(); i++)
    {
        int wall_gap = 0; // 记录每行的前缀和
        for(int j = 0; j < wall[i].size() - 1; j++)
        {
            wall_gap += wall[i][j];
            mid_gap[wall_gap]++; // 哈希表用于统计
        }
    }
    for(auto g : mid_gap) // 选出最多的前缀和数量
    {
        result = max(result, g.second);
    }
    return wall.size() - result; // 所有行中未出现这么多前缀和的行，即为要被穿过的砖块
}

// 穿过的地方实际就是每块砖与每块砖的交界点，即类似于数组中的前缀和这个概念

// 因此，能穿过的最少砖块点，实际就是拥有最多相同中间前缀和的地方

// 通过哈希表统计「每种」前缀和，将wall.size() 减去前缀和的最多出现次数，即为要被穿过的砖块的数量