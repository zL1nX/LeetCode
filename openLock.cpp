/*
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。

 

示例 1:

输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
输出：6
解释：
可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
因为当拨动到 "0102" 时这个锁就会被锁定。
示例 2:

输入: deadends = ["8888"], target = "0009"
输出：1
解释：
把最后一位反向旋转一次即可 "0000" -> "0009"。
示例 3:

输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
输出：-1
解释：
无法旋转到目标数字且不被锁定。
示例 4:

输入: deadends = ["0000"], target = "8888"
输出：-1
 

提示：

死亡列表 deadends 的长度范围为 [1, 500]。
目标数字 target 不会在 deadends 之中。
每个 deadends 和 target 中的字符串的数字会在 10,000 个可能的情况 '0000' 到 '9999' 中产生。
通过次数45,905提交次数91,531

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/open-the-lock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

int openLock(vector<string>& deadends, string target) 
{
    if(target == "0000")
    {
        return 0;
    }
    unordered_set<string> dead(deadends.begin(), deadends.end()); 
    // 转换为set，这样在C++里操作更方便一些
    if(dead.count("0000"))
    {
        return -1;
    }
    // 对单个旋钮进行操作
    auto prev_button = [](char x)->char
    {
        return x == '0' ? '9' : x - 1; // 注意是char型的9不是数字9
    };
    auto next_button = [](char x)->char
    {
        return x == '9' ? '0' : x + 1;
    };

    //
    auto get_status = [&](string status)->vector<string>
    {
        vector<string> next_status;
        for(int i = 0; i < 4; i++)
        {
            char x = status[i];
            status[i] = prev_button(x); //改变这个旋锁的状态，每次改变一个并加入
            next_status.push_back(status);
            status[i] = next_button(x);
            next_status.push_back(status);
            status[i] = x; // 再恢复原状态，因为每次只考察一种状态的变化
        }
        return next_status;
    };

    // 用队列来实现BFS
    queue<pair<string, int>> q;
    q.emplace("0000", 0);
    unordered_set<string> visited = {"0000"}; //首先加入初始状态
    while(!q.empty())
    {
        // 取队首
        auto [status, step] = q.front();
        q.pop();
        for(auto&& st : get_status(status))
        {
            if(visited.find(st) == visited.end() && dead.find(st) == dead.end())
            {// 要是即没出现过，而且也不是死亡状态
                if(st == target)
                {
                    return step + 1;
                }
                q.emplace(st, step + 1); // 加入队列，即BFS
                visited.insert(move(st));
            }
        }
    }
    return -1;
}

// 经典的BFS题解，定义状态的变化是比较关键的

// 每次改变一个旋钮，就是一个状态，这个解法里C++特性的使用，以及两个哈希表的定义都挺关键