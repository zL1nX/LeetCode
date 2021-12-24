/*
有一棵特殊的苹果树，一连 n 天，每天都可以长出若干个苹果。在第 i 天，树上会长出 apples[i] 个苹果，这些苹果将会在 days[i] 天后（也就是说，第 i + days[i] 天时）腐烂，变得无法食用。也可能有那么几天，树上不会长出新的苹果，此时用 apples[i] == 0 且 days[i] == 0 表示。

你打算每天 最多 吃一个苹果来保证营养均衡。注意，你可以在这 n 天之后继续吃苹果。

给你两个长度为 n 的整数数组 days 和 apples ，返回你可以吃掉的苹果的最大数目。

 

示例 1：

输入：apples = [1,2,3,5,2], days = [3,2,1,4,2]
输出：7
解释：你可以吃掉 7 个苹果：
- 第一天，你吃掉第一天长出来的苹果。
- 第二天，你吃掉一个第二天长出来的苹果。
- 第三天，你吃掉一个第二天长出来的苹果。过了这一天，第三天长出来的苹果就已经腐烂了。
- 第四天到第七天，你吃的都是第四天长出来的苹果。
示例 2：

输入：apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
输出：5
解释：你可以吃掉 5 个苹果：
- 第一天到第三天，你吃的都是第一天长出来的苹果。
- 第四天和第五天不吃苹果。
- 第六天和第七天，你吃的都是第六天长出来的苹果。
 

提示：

apples.length == n
days.length == n
1 <= n <= 2 * 104
0 <= apples[i], days[i] <= 2 * 104
只有在 apples[i] = 0 时，days[i] = 0 才成立
通过次数16,016提交次数37,943


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-eaten-apples
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int eatenApples(vector<int>& apples, vector<int>& days) 
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int n = apples.size(), curr_time = 0, res = 0;
    while(curr_time < n || !pq.empty()) // 只要堆不为空，且当前时间足够
    {
        if(curr_time < n && apples[curr_time] > 0) // 略过那些不生产苹果的时候
        {
            pq.emplace(curr_time + days[curr_time] - 1, apples[curr_time]);
        }
        while(!pq.empty() && pq.top().first < curr_time) // 时间小于的话，说明这个苹果在当前时间点已经烂了，
        {
            pq.pop(); // 过期的苹果
        }
        if(!pq.empty())
        {
            pii curr = pq.top();
            pq.pop();
            if(--curr.second > 0 && curr.first > curr_time) // 当吃完还剩苹果，以及当前苹果还没烂的时候
            {
                pq.push(curr); // 重新放回堆里面（这一堆苹果还能吃，别丢了）
            }
            res ++; // 因为上面的if判断是必进的，所以优先队列必然更新了，所以必然吃了个苹果
        }
        curr_time++;
    }
    return res;
}

// 一道关于贪心和优先队列的经典题目，这道题贪心是指，优先吃掉快要过期的苹果。因此这个动态维护过程就是用堆来实现

// 以二元组：还能吃的最后一天，当天产生的苹果数 在队列中进行存储；第一个元素能帮助判断现在吃这个过没过期，第二个元素能维护这个元素对应的苹果还有多少（帮助结果计数）

// 剩下的过程就是模拟去写，但是也有很多细节在里面

// 还是思路非常经典，写起来还挺需要细节的一道题