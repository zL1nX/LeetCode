/*
有一组 n 个人作为实验对象，从 0 到 n - 1 编号，其中每个人都有不同数目的钱，以及不同程度的安静值（quietness）。为了方便起见，我们将编号为 x 的人简称为 "person x "。

给你一个数组 richer ，其中 richer[i] = [ai, bi] 表示 person ai 比 person bi 更有钱。另给你一个整数数组 quiet ，其中 quiet[i] 是 person i 的安静值。richer 中所给出的数据 逻辑自恰（也就是说，在 person x 比 person y 更有钱的同时，不会出现 person y 比 person x 更有钱的情况 ）。

现在，返回一个整数数组 answer 作为答案，其中 answer[x] = y 的前提是，在所有拥有的钱肯定不少于 person x 的人中，person y 是最安静的人（也就是安静值 quiet[y] 最小的人）。

 

示例 1：

输入：richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
输出：[5,5,2,5,4,5,6,7]
解释： 
answer[0] = 5，
person 5 比 person 3 有更多的钱，person 3 比 person 1 有更多的钱，person 1 比 person 0 有更多的钱。
唯一较为安静（有较低的安静值 quiet[x]）的人是 person 7，
但是目前还不清楚他是否比 person 0 更有钱。
answer[7] = 7，
在所有拥有的钱肯定不少于 person 7 的人中（这可能包括 person 3，4，5，6 以及 7），
最安静（有较低安静值 quiet[x]）的人是 person 7。
其他的答案也可以用类似的推理来解释。
示例 2：

输入：richer = [], quiet = [0]
输出：[0]
 
提示：

n == quiet.length
1 <= n <= 500
0 <= quiet[i] < n
quiet 的所有值 互不相同
0 <= richer.length <= n * (n - 1) / 2
0 <= ai, bi < n
ai != bi
richer 中的所有数对 互不相同
对 richer 的观察在逻辑上是一致的
通过次数7,321提交次数13,234

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/loud-and-rich
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) 
{
    int n = quiet.size();
    vector<vector<int>> rec(n);
    for(int i = 0; i < richer.size();i++)
    {
        rec[richer[i][1]].push_back(richer[i][0]);
    }
    // 这块是先把比自己富有的人记录下来，形成一个我原来想象中的哈希表的样子
    // 但注意到，比自己富有的人，并不只是自己这个vector，别人的vector，以及自己这个vector中元素的vector，也可能比自己富有
    vector<int> res(n, -1);

    // 那么我们就需要查看这些富有的人，并依次比较谁更安静
    function<void(int)> dfs = [&](int curr)
    {
        if(res[curr] != -1)
        {
            return; // 说明这块已经访问过了或者正在递归的访问，需要跳过
        }
        res[curr] = curr; // 首先，自己的钱不少于自己，所以先把自己作为一个初始值
        for(int& rich : rec[curr])
        {
            dfs(rich); //然后对于自己这些有钱的邻居，递归的看他们的res值，即最安静的值
            if(quiet[res[rich]] < quiet[res[curr]]) // 然后看看谁更安静
            {
                res[curr] = res[rich]; // 遍历完自己的邻居后，自己的res值就是最安静的值
            }
        }
    };
    for(int i = 0; i < n; i++)
    {
        dfs(i);
    }
    return res;
}

// 有向无环图，以及递归遍历

// 注意这个dfs的功能，就是求出你的目标值，先放dfs意思就是先求出谁的目标值
