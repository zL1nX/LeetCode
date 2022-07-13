/*
给定一个整数数组 asteroids，表示在同一行的行星。

对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。每一颗行星以相同的速度移动。

找出碰撞后剩下的所有行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。

 

示例 1：

输入：asteroids = [5,10,-5]
输出：[5,10]
解释：10 和 -5 碰撞后只剩下 10 。 5 和 10 永远不会发生碰撞。
示例 2：

输入：asteroids = [8,-8]
输出：[]
解释：8 和 -8 碰撞后，两者都发生爆炸。
示例 3：

输入：asteroids = [10,2,-5]
输出：[10]
解释：2 和 -5 发生碰撞后剩下 -5 。10 和 -5 发生碰撞后剩下 10 。
 

提示：

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/asteroid-collision
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) 
{
    stack<int> ss;
    ss.push(asteroids[0]);
    for(int i = 1; i < asteroids.size(); i++)
    {
        bool remain = true;
        while(remain && !ss.empty() && asteroids[i] < 0 && ss.top() > 0)
        {
            remain = ss.top() < -asteroids[i];
            if(ss.top() <= -asteroids[i])
            {
                ss.pop();
            }
        }
        if(remain) // 当行星没爆炸的时候才能入栈
        {
            ss.push(asteroids[i]);
        }
    }
    vector<int> res(ss.size());
    for(int i = ss.size() - 1; i >= 0; i--)
    {
        res[i] = ss.top();
        ss.pop();
    }
    return res;
}


// 栈模拟这一点应该不难想到, 关键在于知道栈的结构后, 模拟的重心该是谁

// 这里很巧妙的就是以每个行星元素为重点, 不停地将其和栈顶进行比较,

// 因为只有当行星不是因为被爆炸而存活的时候, 才能去入栈

// 