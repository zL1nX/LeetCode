/*
给你一个下标从 0 开始的正整数数组 candiesCount ，其中 candiesCount[i] 表示你拥有的第 i 类糖果的数目。同时给你一个二维数组 queries ，其中 queries[i] = [favoriteTypei, favoriteDayi, dailyCapi] 。

你按照如下规则进行一场游戏：

你从第 0 天开始吃糖果。
你在吃完 所有 第 i - 1 类糖果之前，不能 吃任何一颗第 i 类糖果。
在吃完所有糖果之前，你必须每天 至少 吃 一颗 糖果。
请你构建一个布尔型数组 answer ，满足 answer.length == queries.length 。answer[i] 为 true 的条件是：在每天吃 不超过 dailyCapi 颗糖果的前提下，你可以在第 favoriteDayi 天吃到第 favoriteTypei 类糖果；否则 answer[i] 为 false 。注意，只要满足上面 3 条规则中的第二条规则，你就可以在同一天吃不同类型的糖果。

请你返回得到的数组 answer 。

 

示例 1：

输入：candiesCount = [7,4,5,3,8], queries = [[0,2,2],[4,2,4],[2,13,1000000000]]
输出：[true,false,true]
提示：
1- 在第 0 天吃 2 颗糖果(类型 0），第 1 天吃 2 颗糖果（类型 0），第 2 天你可以吃到类型 0 的糖果。
2- 每天你最多吃 4 颗糖果。即使第 0 天吃 4 颗糖果（类型 0），第 1 天吃 4 颗糖果（类型 0 和类型 1），你也没办法在第 2 天吃到类型 4 的糖果。换言之，你没法在每天吃 4 颗糖果的限制下在第 2 天吃到第 4 类糖果。
3- 如果你每天吃 1 颗糖果，你可以在第 13 天吃到类型 2 的糖果。
示例 2：

输入：candiesCount = [5,2,6,4,1], queries = [[3,1,2],[4,10,3],[3,10,100],[4,100,30],[1,3,1]]
输出：[false,true,true,false,false]
 

提示：

1 <= candiesCount.length <= 105
1 <= candiesCount[i] <= 105
1 <= queries.length <= 105
queries[i].length == 3
0 <= favoriteTypei < candiesCount.length
0 <= favoriteDayi <= 109
1 <= dailyCapi <= 109
通过次数5,050提交次数15,778


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) 
{
    int n = candiesCount.size();
    vector<long long> already_eat(n);
    already_eat[0] = candiesCount[0];
    vector<bool> res;
    for(int i = 1; i < n; i ++)
    {
        already_eat[i] += already_eat[i - 1] + candiesCount[i]; // 前缀和看吃到type类糖果时，得吃多少糖果
    }
    for(auto& q : queries)
    {
        long long eat_type = q[0], eat_day = q[1], day_eat = q[2];
        long long min_eat = eat_day + 1, max_eat = (long long)(eat_day + 1) * day_eat;// 在每天理论吃那么多糖果的条件下，理论能吃的糖果上下界
        long long min_can_eat = eat_type == 0 ? 1 : already_eat[eat_type - 1] + 1; // type-1的前缀和还没到type这类糖果，总体+1是第一颗type类糖果
        long long max_can_eat = already_eat[eat_type]; 
        bool isoverlapped = !(min_eat > max_can_eat || max_eat < min_can_eat); // 判断区间是否重叠，即上下界是否满足合理的大小关系
        res.push_back(isoverlapped);
    }
    return res;
}

// 太奇怪了这题的表述的，但核心思想其实很常见

// 就是用前缀和 + 区间的思路 判定是否能落到某一区间，但题目说的怎么就那么绕呢，我佛了

// 核心思路就是，看我理论上究竟能吃多少糖果，然后看到吃的那天时，得吃多少糖果才算能吃到最喜欢的糖果（因为题目有递增的条件，所以可以用前缀和）

// 然后把这俩可能的糖果区间一比，要有交集，就说明肯定能吃到喜欢的糖果

// 核心点在于能将题目给出的吃糖果的条件，转化为前缀和；以及能将是否能吃到糖果的问题转化为区间是否有交集

// 实际上是挺有意思的一道题，但tm的翻译的这些员工是不会说人话吗？