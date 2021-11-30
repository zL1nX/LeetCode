/*
给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中找出并返回第 n 位数字。

 

示例 1：

输入：n = 3
输出：3
示例 2：

输入：n = 11
输出：0
解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。
 

提示：

1 <= n <= 231 - 1
通过次数23,291提交次数53,828

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/nth-digit
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <math.h>

using namespace std;

int findNthDigit(int n) 
{
    int d = 1, cnt = 9;
    while(n > (long long)d * cnt )
    {
        n -= d * cnt;
        d ++;
        cnt *= 10;
    }// 找到n是位于哪个位中
    // 此时d就表示目前的数有多少位
    int index = n - 1; // 目标位的索引
    int start = (int) pow(10, d - 1); // 当前第x位的起始数字
    int targetNum = start + index / d; // 第n位所在的目标数字
    int targetBit = index % d; // 第n位所在的目标bit
    int res = (targetNum / (int)pow(10, d - 1 - targetBit)) % 10; // 先整除让目标位位于最后一位，然后%10得到目标位
    return res;
}

// 肯定是能找规律来做的

// 注意到第x位数字的位数总和是 x * 9 * 10^(x - 1)，因此可以通过这个式子递减地找到n是位于第哪位数字中间

// 此时的n就表示目标位在这些位间的索引
// 然后直接找到是第几个数字的第几位即可

// 能意识到第一步的这个位数总和的式子是很重要的