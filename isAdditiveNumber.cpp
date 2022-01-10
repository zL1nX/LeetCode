/*
累加数 是一个字符串，组成它的数字可以形成累加序列。

一个有效的 累加序列 必须 至少 包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。

给你一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是 累加数 。如果是，返回 true ；否则，返回 false 。

说明：累加序列里的数 不会 以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。

 

示例 1：

输入："112358"
输出：true 
解释：累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
示例 2：

输入："199100199"
输出：true 
解释：累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
 

提示：

1 <= num.length <= 35
num 仅由数字（0 - 9）组成
 

进阶：你计划如何处理由过大的整数输入导致的溢出?



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/additive-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
using namespace std;

bool isAdditiveNumber(string num) 
{
    int n = num.length();
    for(int secondStart = 1; secondStart < n - 1; ++secondStart)
    {
        if(num[0] == '0' && secondStart != 1)
        {
            break;
        }
        for(int secondEnd = secondStart; secondEnd < n - 1; ++ secondEnd)
        {
            // 遍历这两个位置
            if(num[secondStart] == '0' && secondStart != secondEnd)
            {
                break;
            }
            if(valid(secondStart, secondEnd, num))
            {
                return true;
            }
        }
    }
    return false;
}

bool valid(int secondStart, int secondEnd, string num)
{
    int n = num.length();
    int firstStart = 0, firstEnd = secondStart - 1;
    while(secondEnd <= n - 1)
    {
        string third = stringAdd(num, firstStart, firstEnd, secondStart, secondEnd);
        int thirdStart = secondEnd + 1, thirdEnd = thirdStart + third.length() - 1;
        if(thirdEnd >= n || !(num.substr(thirdStart, third.length()) == third))
        {
            return false;
        }
        if(thirdEnd == n - 1) //最后遍历完了 ，整个序列可以刚好累加完成
        {
            return true;
        }
        firstStart = secondStart;
        firstEnd = secondEnd;
        secondStart = thirdStart;
        secondEnd = thirdEnd;
        // 重新赋值，向后推进，查看后面的能否实现两个累加的关系
    }
    return false;
}

// 字符串加法函数，防止溢出
string stringAdd(string n, int firstStart, int firstEnd, int secondStart, int secondEnd)
{
    string third;
    int flag = 0, curr = 0;
    while(firstEnd >= firstStart || secondEnd >= secondStart || flag != 0)
    {
        curr = flag; // 已有的进位值
        if(firstEnd >= firstStart)
        {
            curr += n[firstEnd] - '0';
            --firstEnd;
        }
        if(secondEnd >= secondStart)
        {
            curr += n[secondEnd] - '0';
            --secondEnd;
        }
        flag = curr / 10;
        curr %= 10;
        third.push_back(curr + '0');
    }
    reverse(third.begin(), third.end());
    return third;
}

// 本质其实就是在穷举两个位置，每次穷举都将结果试着加起来，如果可以那就继续

// 不知道这种能不能用dfs回溯去做，其实本质也是一样的