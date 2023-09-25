/*
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。

 

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

1 <= s.length <= 3 * 105
s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
s 表示一个有效的表达式
'+' 不能用作一元运算(例如， "+1" 和 "+(2 + 3)" 无效)
'-' 可以用作一元运算(即 "-1" 和 "-(2 + 3)" 是有效的)
输入中不存在两个连续的操作符
每个数字和运行的计算将适合于一个有符号的 32位 整数
*/

#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <numeric>

using namespace std;

int subcalculate(deque<char>& sd)
{
    vector<int> st;
    int num = 0;
    char sign = '+';
    while(!sd.empty())
    {
        char c = sd.front();
        sd.pop_front();
        if(isdigit(c))
        {
            num = 10 * num + (c - '0');
        }
        if(c == '(')
        {
            num = subcalculate(sd);
        }
        
        if((!isdigit(c) && c != ' ') || sd.empty()) // i到最后了也应该把刚才的num给入栈
        {
            switch (sign)
            {
                case '+':
                    st.push_back(num);
                    break;
                case '-':
                    st.push_back(-num);
                    break;
                case '*':
                    st.push_back(st.back() * num);
                    break;
                case '/':
                    st.push_back(st.back() / num);
                    break;
                default:
                    break;
            }
            num = 0;
            sign = c; // c当前是个运算符
        }
        
        if(c == ')')
        {
            break; // 不循环了直接返回
        }
    }
    return accumulate(st.begin(), st.end(), 0);
}

int calculate(string s) 
{        
    deque<char> sd(s.begin(), s.end());
    return subcalculate(sd);
    
}

// 224-基本计算器