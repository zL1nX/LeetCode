/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]
 

提示：

1 <= n <= 8
*/

#include <vector>
#include <string>

using namespace std;

vector<string> res;

vector<string> generateParenthesis(int n) 
{
    string track;
    backtrack(track, n, n);
    return res;
}


void backtrack(string& track, int left, int right)
{
    if(left == 0 && right == 0)
    {
        res.emplace_back(track);
        return;
    }
    if(left < 0 || right < 0 || left > right)
    {
        return;
    }
    track.push_back('(');
    backtrack(track, left - 1, right);
    track.pop_back();

    track.push_back(')');
    backtrack(track, left, right - 1);
    track.pop_back();
    
}