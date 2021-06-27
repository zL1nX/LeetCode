/*
在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示.

一次移动定义为选择 0 与一个相邻的数字（上下左右）进行交换.

最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。

给出一个谜板的初始状态，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。

示例：

输入：board = [[1,2,3],[4,0,5]]
输出：1
解释：交换 0 和 5 ，1 步完成
输入：board = [[1,2,3],[5,4,0]]
输出：-1
解释：没有办法完成谜板
输入：board = [[4,1,2],[5,0,3]]
输出：5
解释：
最少完成谜板的最少移动次数是 5 ，
一种移动路径:
尚未移动: [[4,1,2],[5,0,3]]
移动 1 次: [[4,1,2],[0,5,3]]
移动 2 次: [[0,1,2],[4,5,3]]
移动 3 次: [[1,0,2],[4,5,3]]
移动 4 次: [[1,2,0],[4,5,3]]
移动 5 次: [[1,2,3],[4,5,0]]
输入：board = [[3,2,4],[1,5,0]]
输出：14
提示：

board 是一个如上所述的 2 x 3 的数组.
board[i][j] 是一个 [0, 1, 2, 3, 4, 5] 的排列.
通过次数20,232提交次数28,318

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-puzzle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

int slidingPuzzle(vector<vector<int>>& board) 
{
    vector<vector<int>> loc_neighbours = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    string target = "123450";
    auto get_status = [&](string status)->vector<string>
    {
        int loc = status.find('0');
        vector<string> res;
        for(int l : loc_neighbours[loc])
        {
            swap(status[l], status[loc]);
            res.push_back(status);
            swap(status[l], status[loc]);
        }
        return res;
    };

    queue<pair<string, int>> q;
    string initial = "";
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j ++)
        {
            initial += to_string(board[i][j]);
        }
    }
    if(initial == target)
    {
        return 0;
    }

    q.emplace(initial, 0);
    unordered_set<string> visited = {initial} ;
    while(!q.empty())
    {
        auto [status, step] = q.front();
        q.pop();
        vector<string> next_status = get_status(status);
        for(string& nstatus : next_status)
        {
            if(visited.find(nstatus) == visited.end())
            {
                if(nstatus == target)
                {
                    return step + 1;
                }
                q.emplace(nstatus, step + 1);
                visited.insert(move(nstatus));
            }
        }
    }
    return -1;
}

// 和昨天的题目基本一样，但这道题在邻居状态的定义上更需要注意

// 本来想着也是定义四个转移函数，但这样实在是太啰嗦了，而且边界检查还容易出错

// 而题解的方法还挺妙，即转化成一维的字符串进行操作，这样交换这个操作好实现了

// 进一步地，定义一个neighbour数组标明每个位置的邻居位置，这样写的话就不用care边界检查，而且代码也更简洁了

// 妙啊