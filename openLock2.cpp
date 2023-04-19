/*
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。

 

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
解释：把最后一位反向旋转一次即可 "0000" -> "0009"。
示例 3:

输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
输出：-1
解释：无法旋转到目标数字且不被锁定。
 

提示：

1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target 不在 deadends 之中
target 和 deadends[i] 仅由若干位数字组成
*/

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

string plus_one(string s, int j) 
{
    if (s[j] == '9') s[j] = '0';
    else s[j] += 1;
    return s;
}

string minus_one(string s, int j) 
{
    if (s[j] == '0') s[j] = '9';
    else s[j] -= 1;
    return s;
}

int openLock(vector<string>& deadends, string target) 
{
    unordered_set<string> deads, visited;
    for(string& d : deadends){
        deads.insert(d);
    }

    int steps = 0;
    queue<string> q;
    q.push("0000");
    visited.insert("0000");
    while(!q.empty())
    {
        int sz = q.size();
        for(int i = 0; i < sz; i++)
        {
            string curr = q.front();
            q.pop();
            if(deads.count(curr))
            {
                continue;
            }
            if(curr == target)
            {
                return steps;
            }

            for(int k = 0; k < 4; k++)
            {
                string plusone = plus_one(curr, k);
                if(!visited.count(plusone))
                {
                    q.push(plusone);
                    visited.insert(plusone);
                }

                string minusone = minus_one(curr, k);
                if(!visited.count(minusone))
                {
                    q.push(minusone);
                    visited.insert(minusone);
                }
            }
        }
        steps++;
    }

    return -1;
}


// 将拨动锁的过程抽象成一个有8个邻居节点的图, 那么使用BFS就能用最快的方式找到从0000到最终目标的步数