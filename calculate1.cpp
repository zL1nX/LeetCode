/*
实现一个基本的计算器来计算一个简单的字符串表达式 s 的值。

 

示例 1：

输入：s = "1 + 1"
输出：2
示例 2：

输入：s = " 2-1 + 2 "
输出：3
示例 3：

输入：s = "(1+(4+5+2)-3)+(6+8)"
输出：23
 

提示：

1 <= s.length <= 3 * 105
s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
s 表示一个有效的表达式


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/basic-calculator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <stack>
using namespace std;

int calculate(string s) 
{
    stack<int> signs_stack;
    long long res = 0;
    int sign = 1, id = 0, n = s.length();
    signs_stack.push(1);
    while(id < n)
    {
        if(s[id] == ' ')
        {
            id++;
        }
        else if(s[id] == '+')
        {
            sign = signs_stack.top();
            id++; 
        }
        else if(s[id] == '-')
        {
            sign = -signs_stack.top();
            id++;
        }
        else if(s[id] == '(')
        {
            signs_stack.push(sign);
            id++;
        }
        else if(s[id] == ')')
        {
            signs_stack.pop();
            id++;
        }
        else
        {
            long long temp = 0;
            while(id < n && s[id] >= '0' && s[id] <= '9')
            {
                temp = temp * 10 + s[id] - '0';
                id++;
            } 
            res += sign * temp;
        }
        
    }
    return res;
}
// 先注意到本题没有乘除，只有加减，因此用后缀表达式写的话就会非常麻烦

// 因为只有加减，所以本质就是加，但是要处理好符号问题

// 此处影响符号的只会有括号，用一个栈来维护符号的变化

// 栈底始终为元素1，用来作为翻转的基准；遇到括号就将前面的符号入栈，等括号算完之后在pop出来，括号内的值的符号是由入栈的括号整体符号来决定翻转的

// 总之就是一定处理好符号多会要翻转，依据谁来翻转的问题

// 得多想想