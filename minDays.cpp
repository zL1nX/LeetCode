/*
给你一个整数数组 bloomDay，以及两个整数 m 和 k 。

现需要制作 m 束花。制作花束时，需要使用花园中 相邻的 k 朵花 。

花园中有 n 朵花，第 i 朵花会在 bloomDay[i] 时盛开，恰好 可以用于 一束 花中。

请你返回从花园中摘 m 束花需要等待的最少的天数。如果不能摘到 m 束花则返回 -1 。

 

示例 1：

输入：bloomDay = [1,10,3,10,2], m = 3, k = 1
输出：3
解释：让我们一起观察这三天的花开过程，x 表示花开，而 _ 表示花还未开。
现在需要制作 3 束花，每束只需要 1 朵。
1 天后：[x, _, _, _, _]   // 只能制作 1 束花
2 天后：[x, _, _, _, x]   // 只能制作 2 束花
3 天后：[x, _, x, _, x]   // 可以制作 3 束花，答案为 3
示例 2：

输入：bloomDay = [1,10,3,10,2], m = 3, k = 2
输出：-1
解释：要制作 3 束花，每束需要 2 朵花，也就是一共需要 6 朵花。而花园中只有 5 朵花，无法满足制作要求，返回 -1 。
示例 3：

输入：bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
输出：12
解释：要制作 2 束花，每束需要 3 朵。
花园在 7 天后和 12 天后的情况如下：
7 天后：[x, x, x, x, _, x, x]
可以用前 3 朵盛开的花制作第一束花。但不能使用后 3 朵盛开的花，因为它们不相邻。
12 天后：[x, x, x, x, x, x, x]
显然，我们可以用不同的方式制作两束花。
示例 4：

输入：bloomDay = [1000000000,1000000000], m = 1, k = 1
输出：1000000000
解释：需要等 1000000000 天才能采到花来制作花束
示例 5：

输入：bloomDay = [1,10,2,9,3,8,4,7,5,6], m = 4, k = 2
输出：9
 

提示：

bloomDay.length == n
1 <= n <= 10^5
1 <= bloomDay[i] <= 10^9
1 <= m <= 10^6
1 <= k <= n
通过次数8,324提交次数16,174

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-days-to-make-m-bouquets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

bool check(vector<int>& bloomDay, int m, int k, int days) // 注意下这种判定连续子数组的写法
{
    int consecutive = 0, cnt = 0;
    for(int i = 0;i < bloomDay.size(); i++)
    {
        if(bloomDay[i] <= days)
        {
            consecutive ++;
            if(consecutive == k)
            {
                cnt ++;
                consecutive = 0; // 只要求够了k只花就算，因此可以直接归0
            }
        }
        else
        {
            consecutive = 0;
        }
    }
    return cnt >= m; // 够不够m束花
}


int minDays(vector<int>& bloomDay, int m, int k) 
{
    if(k * m > bloomDay.size()) // m束花，每束花k只
    {
        return -1;
    }
    int low = 1, high = bloomDay[0];
    for(int i = 0;i < bloomDay.size(); i++)
    {
        high = max(high, bloomDay[i]); //找最大值，即一定可以check通过的
    }
    // 二分，前闭后开
    while(low < high)
    {
        int mid = (high - low) / 2  + low;
        if(check(bloomDay, m, k, mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

// 本题的核心需求根据提示其实容易知道，就是「如何判定在某天时能扎多少花束」

// 这一需求如果给定天数是容易实现的，就是check函数

// 那么问题转化到了如何找合适的days呢？

// 可以肯定的是，days越大越容易通过check函数。因此正确的days是一个有序变化（或排列）的，那么就直接用二分查找，对所有可能的days开始搜索

// 妙啊