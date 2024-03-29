/*
珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 h 小时后回来。

珂珂可以决定她吃香蕉的速度 k （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 k 根。如果这堆香蕉少于 k 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  

珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。

 

示例 1：

输入：piles = [3,6,7,11], h = 8
输出：4
示例 2：

输入：piles = [30,11,23,4,20], h = 5
输出：30
示例 3：

输入：piles = [30,11,23,4,20], h = 6
输出：23
 

提示：

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/koko-eating-bananas
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) 
{
    int left = 1, right = 1e9+1;
    while(left < right)
    {
        int mid = (right - left) / 2 + left;
        if(getHour(piles, mid) <= h) // 这里是 <= 而非< ,就是为了找到最近的那个左边界
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int getHour(vector<int>& piles, int speed)
{
    int hours = 0;
    for(int i = 0; i < piles.size(); i++)
    {
        hours += piles[i] / speed;
        if(piles[i] % speed > 0)
        {
            hours ++;
        }
    }
    return hours;
}


// 没想到还可以抽象成一个函数值的搜索问题, 不过细想一下也确实, 原题目中似乎没有任何可以优化的地方

// 背包或者dp吗? 似乎也没有明确的状态转移

// 而变成这种二分搜索后, 在结果上就是要查找最小的那个h

// 而如果泛化下原有的二分, 在写时实际就是找到函数值等于h的那个最小的边界值, 所以二分里面才要用 <= 时右边界不断紧缩的写法

// 这种函数值查找其实都可以用二分这种暴力方法写