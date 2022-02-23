/*
复数 可以用字符串表示，遵循 "实部+虚部i" 的形式，并满足下述条件：

实部 是一个整数，取值范围是 [-100, 100]
虚部 也是一个整数，取值范围是 [-100, 100]
i2 == -1
给你两个字符串表示的复数 num1 和 num2 ，请你遵循复数表示形式，返回表示它们乘积的字符串。

 

示例 1：

输入：num1 = "1+1i", num2 = "1+1i"
输出："0+2i"
解释：(1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
示例 2：

输入：num1 = "1+-1i", num2 = "1+-1i"
输出："0+-2i"
解释：(1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。 
 

提示：

num1 和 num2 都是有效的复数表示。
通过次数18,063提交次数24,555

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/complex-number-multiplication
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>

using namespace std;

string complexNumberMultiply(string num1, string num2) 
{
    auto getReal = [](const string& s) {
        int loc = s.find('+');
        pair<int, int> real;
        real.first = stoi(s.substr(0, loc));
        real.second = stoi(s.substr(loc + 1, s.size() - loc - 1 - 1));
        return real;
    };
    pair<int, int> a = getReal(num1), b = getReal(num2);   
    int real = a.first * b.first - a.second * b.second, imag = a.first * b.second + a.second * b.first;
    return to_string(real) + "+" + to_string(imag) + "i";
}

// 寄，还是没有想到用sscanf来直接获取复数的每个位置的数字

// 所以思路还会是用单独定义一个复数转换函数，然后直接写就好。