/*
 f(x) 是 x! 末尾是 0 的数量。回想一下 x! = 1 * 2 * 3 * ... * x，且 0! = 1 。

例如， f(3) = 0 ，因为 3! = 6 的末尾没有 0 ；而 f(11) = 2 ，因为 11!= 39916800 末端有 2 个 0 。
给定 k，找出返回能满足 f(x) = k 的非负整数 x 的数量。

 

示例 1：

输入：k = 0
输出：5
解释：0!, 1!, 2!, 3!, 和 4! 均符合 k = 0 的条件。
示例 2：

输入：k = 5
输出：0
解释：没有匹配到这样的 x!，符合 k = 5 的条件。
示例 3:

输入: k = 3
输出: 5
 

提示:

0 <= k <= 109
通过次数
27.5K
提交次数
56.6K
通过率
48.7%
*/

using namespace std;

long trailingZeroes(long n) 
{
    long res = 0;
    long d = 5;
    for (long d = 5; d <= n; d = d * 5)
    {
        res += n / d;
    }
    return res;
}

long left_bound(int target)
{
    long left = 0, right = __LONG_MAX__, mid;
    while(left < right) // [left, right) 
    {
        mid = left + (right - left) / 2;
        long val = trailingZeroes(mid);
        if(val == target)
        {
            right = mid; // 缩紧右边界, 最终就缩到了目标左边界上
        }
        else if(val < target)
        {
            left = mid + 1;
        }
        else if(val > target)
        {
            right = mid;
        }
    }
    return left;
}

long right_bound(int target)
{
    long left = 0, right = __LONG_MAX__, mid;
    while(left < right) // [left, right)
    {
        mid = left + (right - left) / 2;
        long val = trailingZeroes(mid);
        if(val == target)
        {
            left = mid + 1; // 缩紧左边界, 而且是mid +1, 因为最后会 left == right, 是移到了右边开区间
        }
        else if(val < target)
        {
            left = mid + 1;
        }
        else if(val > target)
        {
            right = mid;
        }
    }
    return left - 1; // 所以最后返回的是 -1
}

int preimageSizeFZF(int k) 
{
    return (int)(right_bound(k) - left_bound(k)) + 1;
}


// 793-阶乘函数后 K 个零