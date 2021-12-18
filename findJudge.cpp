/*
在一个小镇里，按从 1 到 n 为 n 个人进行编号。传言称，这些人中有一个是小镇上的秘密法官。

如果小镇的法官真的存在，那么：

小镇的法官不相信任何人。
每个人（除了小镇法官外）都信任小镇的法官。
只有一个人同时满足条件 1 和条件 2 。
给定数组 trust，该数组由信任对 trust[i] = [a, b] 组成，表示编号为 a 的人信任编号为 b 的人。

如果小镇存在秘密法官并且可以确定他的身份，请返回该法官的编号。否则，返回 -1。

 

示例 1：

输入：n = 2, trust = [[1,2]]
输出：2
示例 2：

输入：n = 3, trust = [[1,3],[2,3]]
输出：3
示例 3：

输入：n = 3, trust = [[1,3],[2,3],[3,1]]
输出：-1
示例 4：

输入：n = 3, trust = [[1,2],[2,3]]
输出：-1
示例 5：

输入：n = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
输出：3
 

提示：

1 <= n <= 1000
0 <= trust.length <= 104
trust[i].length == 2
trust[i] 互不相同
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= n
通过次数43,232提交次数83,417

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-town-judge
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

int findJudge(int n, vector<vector<int>>& trust) 
{
    vector<int> in(n + 1), out(n + 1);
    for(auto& t : trust)
    {
        in[t[1]]++;
        out[t[0]]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(in[i] == n - 1 && out[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

// 题意比较好理解，而且题目给的条件都很充足了

// 包含所有的n个人；每个项互不相同，而且每个人只能信任一个人；

// 这样一来，如果是法官，那么必然有n-1个人信任他，这样就省去了判断究竟n-1是不是涵盖了其他的n-1个人

// 同时，还要满足法官他没有信任的人

// 因此，这样的结构就类似于图里的入度出度，用两个数组遍历判断，然后进行上面两个条件的判断即可

// 相对比较简单，可以作为面试的热身题或者是门槛题
