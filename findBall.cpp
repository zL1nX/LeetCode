/*
用一个大小为 m x n 的二维网格 grid 表示一个箱子。你有 n 颗球。箱子的顶部和底部都是开着的。

箱子中的每个单元格都有一个对角线挡板，跨过单元格的两个角，可以将球导向左侧或者右侧。

将球导向右侧的挡板跨过左上角和右下角，在网格中用 1 表示。
将球导向左侧的挡板跨过右上角和左下角，在网格中用 -1 表示。
在箱子每一列的顶端各放一颗球。每颗球都可能卡在箱子里或从底部掉出来。如果球恰好卡在两块挡板之间的 "V" 形图案，或者被一块挡导向到箱子的任意一侧边上，就会卡住。

返回一个大小为 n 的数组 answer ，其中 answer[i] 是球放在顶部的第 i 列后从底部掉出来的那一列对应的下标，如果球卡在盒子里，则返回 -1 。

 

示例 1：



输入：grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
输出：[1,-1,-1,-1,-1]
解释：示例如图：
b0 球开始放在第 0 列上，最终从箱子底部第 1 列掉出。
b1 球开始放在第 1 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
b2 球开始放在第 2 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
b3 球开始放在第 3 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
b4 球开始放在第 4 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
示例 2：

输入：grid = [[-1]]
输出：[-1]
解释：球被卡在箱子左侧边上。
示例 3：

输入：grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
输出：[0,1,2,3,4,-1]
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] 为 1 或 -1
通过次数8,018提交次数12,263

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/where-will-the-ball-fall
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

vector<int> findBall(vector<vector<int>>& grid) 
{
    int n = grid[0].size();
    vector<int> res(n, -1);
    for(int j = 0; j < n; j++) // 遍历每一个球
    {
        int ball = j;
        for(auto& row : grid)
        {
            int dir = row[ball]; // 当前位置
            ball += dir; // 移动到了下一个位置
            // ball实际上就是横行里的index
            if(ball < 0 || ball >= n || row[ball] != dir) // 这块就表示，原单元格的邻居与原单元格的方向相反，即V字型
            {
                ball = -1;
                break;
            }
        }
        if(ball >= 0)
        {
            res[j] = ball;
        }
    }
    return res;
}


// 这题的题解代码写的真的巧妙而且整洁，在想着如何表示+-1的时候，题解敏锐地察觉到，+-1实际就是表示在下一行和当前行中index的变化

// 当想着如何表示V字型的时候，题解敏锐地察觉到，V字型其实就是，球要滚到的下一个index处在当前行的方向，与原来单元格方向相反

// 这个是真的巧妙

// 有了上面两步转化后，整个的框架就是遍历每个球，从第一行开始遍历，每移动一行，就看下下次的位置是否触碰了边界或者遇到了V型

// 然后按需返回vector就可以

// 这个代码写的是真的精简而且巧妙
