/*
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

整数除法仅保留整数部分。

 

示例 1：

输入：s = "3+2*2"
输出：7
示例 2：

输入：s = " 3/2 "
输出：1
示例 3：

输入：s = " 3+5 / 2 "
输出：5
 

提示：

1 <= s.length <= 3 * 105
s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
s 表示一个 有效表达式
表达式中的所有整数都是非负整数，且在范围 [0, 231 - 1] 内
题目数据保证答案是一个 32-bit 整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/basic-calculator-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
#include <numeric>

using namespace std;

int calculate(string s) 
{
    vector<int>  nums_stack;
    int n = s.length(), id = 0, num = 0;
    char sign = '+'; // deafult sign
    for(int i = 0;i < n; i++)
    {
        if(isdigit(s[i]))
        {
            num = num * 10 + int(s[i] - '0'); // 先算这个数是啥，比如123
        }
        if((!isdigit(s[i]) && s[i] != ' ') || (i == n - 1)) // 要是当前这个不是数（那就是符号喽），或者到了最后一个数，就该真正计算了
        {
            switch (sign){
                case '+':
                    nums_stack.push_back(num);
                    break;
                case '-':
                    nums_stack.push_back(-num);
                    break;
                case '*':
                    nums_stack.back() *= num;
                    break;
                default:
                    nums_stack.back() /= num;
            }
            num = 0;
            sign = s[i]; // 当前是符号时，其实sign还是上一个符号，num其实也是上一个符号后面的数字，这里是比较绕的
            // 每次其实是处理当前符号之前的数字运算
        }
    }
    return accumulate(nums_stack.begin(), nums_stack.end(), 0);

}
