/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
 

示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
 

提示：

1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成
*/

#include <string>
#include <vector>
using namespace std;

char leftOf(char right)
{
    char left;
    switch (right)
    {
        case ')':
            left = '(';
            break;
        case ']':
            left = '[';
            break;
        case '}':
            left = '{';
            break;
        default:
            break;
    }
    return left;
}

bool isParenthesesValid(string s) 
{
    vector<char> st;
    for(char p : s)
    {
        if(p == '(' || p == '[' || p == '{')
        {
            st.push_back(p);
        }
        else
        {
            if(!st.empty() && leftOf(p) == st.back()) // 必须同种括号闭合
            {
                st.pop_back();
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}