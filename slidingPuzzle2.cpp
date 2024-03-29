/*
在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示。一次 移动 定义为选择 0 与一个相邻的数字（上下左右）进行交换.

最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。

给出一个谜板的初始状态 board ，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。

 

示例 1：



输入：board = [[1,2,3],[4,0,5]]
输出：1
解释：交换 0 和 5 ，1 步完成
示例 2:



输入：board = [[1,2,3],[5,4,0]]
输出：-1
解释：没有办法完成谜板
示例 3:



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
 

提示：

board.length == 2
board[i].length == 3
0 <= board[i][j] <= 5
board[i][j] 中每个值都 不同
通过次数34,298提交次数48,881

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/sliding-puzzle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;


int slidingPuzzle(vector<vector<int>>& board) 
{
    string target = "123450", start = "";

    int m = 2, n = 3;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            start += to_string(board[i][j]); // convert vector to string
        }
    }

    vector<vector<int>> neighbor = {{1, 3},{0, 4, 2},{1, 5},{0, 4},{3,1, 5},{4, 2}}; // neighbour index

    queue<string> q;
    unordered_set<string> visited;
    q.push(start);
    visited.insert(start);
    int step = 0;

    while(!q.empty())
    {
        int sz = q.size();
        for(int i = 0; i < sz; i++)
        {
            string curr = q.front();
            q.pop();
            if(target == curr)
            {
                return step;
            }

            int loc = curr.find('0');
            for(int act : neighbor[loc])
            {
                string new_move = swap(curr, loc, act);
                if(!visited.count(new_move))
                {
                    visited.insert(new_move);
                    q.push(new_move);
                }
            }
        }
        step++;
    }
    return -1;
}

string swap(string s, int a, int b)
{
    char c = s[a];
    s[a] = s[b];
    s[b] = c;
    return s;
}