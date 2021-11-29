/*
给你一个按递增顺序排序的数组 arr 和一个整数 k 。数组 arr 由 1 和若干 素数  组成，且其中所有整数互不相同。

对于每对满足 0 < i < j < arr.length 的 i 和 j ，可以得到分数 arr[i] / arr[j] 。

那么第 k 个最小的分数是多少呢?  以长度为 2 的整数数组返回你的答案, 这里 answer[0] == arr[i] 且 answer[1] == arr[j] 。

 
示例 1：

输入：arr = [1,2,3,5], k = 3
输出：[2,5]
解释：已构造好的分数,排序后如下所示: 
1/5, 1/3, 2/5, 1/2, 3/5, 2/3
很明显第三个最小的分数是 2/5
示例 2：

输入：arr = [1,7], k = 1
输出：[1,7]
 

提示：

2 <= arr.length <= 1000
1 <= arr[i] <= 3 * 104
arr[0] == 1
arr[i] 是一个 素数 ，i > 0
arr 中的所有数字 互不相同 ，且按 严格递增 排序
1 <= k <= arr.length * (arr.length - 1) / 2
通过次数7,322提交次数12,923

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-th-smallest-prime-fraction
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>

using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) 
{
    auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
        return arr[a.first] * arr[b.second] > arr[a.second] * arr[b.first];
    };
    int n = arr.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    for(int i = 1; i < n; i++)
    {
        q.emplace(0, i); // 先加进来这些最小的分数
    }
    for(int _ = 1; _ < k; _ ++) // 少作1次，因为最后加进去相当于又排序了一次
    {
        auto [i, j] = q.top(); // 每次都取出最小的分数来
        q.pop();
        if(i + 1 < j) // 根据这些最小的分数，向大的逼近
        {
            q.emplace(i + 1, j);
        }
    }
    return {arr[q.top().first], arr[q.top().second]};
}

// 首先，如果直接暴力去做，那就是自定义排序策略，然后对所有分数都进行排序即可。注意比较时使用交叉相乘，而不要直接除法避免精度损失

// 在暴力的基础上进行优化，可知如果选定一个arri作为分母，那么它前面的所有数与它会形成一个列表，这个列表中就是形成的部分分数

// 那么题目就转化为了，在这n-1个列表中的，第k小的分数是什么。因此我们就要涉及到列表的合并与排序问题

// 对于排序，优先队列可以有效的解决这个问题，而且能准确地找到第k小的值

// 对于合并，题解的方法的确非常巧妙，就是因为那些小的分数，必然分子是尽可能小的，因此我们先存那些分子最小的分数

// 然后根据这些分数，如果分子还足够小，那就再加进来，这样再来看，一定就可以逐步向第k小的分数逼近

// 这道题的写法挺有意思