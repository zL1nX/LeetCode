/*
假设有从 1 到 N 的 N 个整数，如果从这 N 个数字中成功构造出一个数组，使得数组的第 i 位 (1 <= i <= N) 满足如下两个条件中的一个，我们就称这个数组为一个优美的排列。条件：

第 i 位的数字能被 i 整除
i 能被第 i 位上的数字整除
现在给定一个整数 N，请问可以构造多少个优美的排列？

示例1:

输入: 2
输出: 2
解释: 

第 1 个优美的排列是 [1, 2]:
  第 1 个位置（i=1）上的数字是1，1能被 i（i=1）整除
  第 2 个位置（i=2）上的数字是2，2能被 i（i=2）整除

第 2 个优美的排列是 [2, 1]:
  第 1 个位置（i=1）上的数字是2，2能被 i（i=1）整除
  第 2 个位置（i=2）上的数字是1，i（i=2）能被 1 整除
说明:

N 是一个正整数，并且不会超过15。
通过次数14,595提交次数21,565

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/beautiful-arrangement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

vector<int> visited;
vector<vector<int>> divide;
int nums; // 

void backtrack(int index, int N)
{
    if(index == N + 1)
    {
        nums += 1;
        return; // 找到一种排列，即index到n后面了
    }
    for(int& x : divide[index]) // 遍历每个可能的节点
    {
        if(!visited[x])
        {
            visited[x] = true;
            backtrack(index + 1, N); // 继续找
            visited[x] = false; // 记得清除自己的访问痕迹，从而方便上层backtrack进行遍历
            // 这句不是为了本层遍历的，本层直接一个for，肯定不会访问到相同的x
        }
    }
}

int countArrangement(int n) 
{
    visited.resize(n + 1);
    divide.resize(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i % j == 0 || j % i == 0)
            {
                divide[i].push_back(j);
            }
        }
    }
    backtrack(1, n);
    return nums;
}

// 最开始想到了要搞一个divide和visited数组来记录，但是没想好这个放的过程该怎么写

// 这种回溯递归还挺经典的写起来，关键就是backtrack的参数要写什么

// 而在回溯（或者dfs）也好，记得在一条线路递归结束后，把visited对应的置回false

// 这是由于假设backtrak完之后nums也++了，此时退栈继续遍历其他节点，遍历结束后再次退栈，这下轮到上层遍历其他节点了，所以你在退栈的时候必须把自己访问的痕迹清除干净、

// 回溯的经典写法，或者说是排列组合，将元素放到数组里的经典写法