/*
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。

如果小数部分为循环小数，则将循环的部分括在括号内。

如果存在多个答案，只需返回 任意一个 。

对于所有给定的输入，保证 答案字符串的长度小于 104 。

 

示例 1：

输入：numerator = 1, denominator = 2
输出："0.5"
示例 2：

输入：numerator = 2, denominator = 1
输出："2"
示例 3：

输入：numerator = 2, denominator = 3
输出："0.(6)"
示例 4：

输入：numerator = 4, denominator = 333
输出："0.(012)"
示例 5：

输入：numerator = 1, denominator = 5
输出："0.2"
 

提示：

-231 <= numerator, denominator <= 231 - 1
denominator != 0
通过次数27,915提交次数92,323

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fraction-to-recurring-decimal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <unordered_map>

using namespace std;

string fractionToDecimal(int numerator, int denominator) 
{
    string ret;
    long long n = numerator, d = denominator;
    if(n * d < 0)
    {
        ret += "-";
    }
    // 计算整数部分
    long long inter = n / d;
    if(inter < 0)
    {
        inter *= -1;
    }
    ret += to_string(inter);

    // 计算小数部分
    if(n < 0) n *= -1;
    if(d < 0) d *= -1;
    n %= d;
    if(n == 0) // 如果能整除就直接返回
    {
        return ret;
    }
    ret += ".";
    unordered_map<int, int> app; // 记录每次出现的位置
    string flt;
    int curr = 0; // 永远指向最新的小数点
    while(n && !app.count(n))
    {
        app[n] = curr++; // 记录
        n *= 10; // 这样每次乘完10后再除，就可以得到一位的结果
        flt.push_back((char)(n / d + '0'));
        n %= d;
    }
    if(n != 0) // 说明是count条件触发了，即出现了一个相同的n，此时curr指向的是第二个n
    {
        ret += flt.substr(0, app[n]) + "(" + flt.substr(app[n], curr) + ")";
    }
    else
    {
        ret += flt;
    }
    return ret;
}