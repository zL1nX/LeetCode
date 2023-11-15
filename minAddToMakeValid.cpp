/*
只有满足下面几点之一，括号字符串才是有效的：

它是一个空字符串，或者
它可以被写成 AB （A 与 B 连接）, 其中 A 和 B 都是有效字符串，或者
它可以被写作 (A)，其中 A 是有效字符串。
给定一个括号字符串 s ，在每一次操作中，你都可以在字符串的任何位置插入一个括号

例如，如果 s = "()))" ，你可以插入一个开始括号为 "(()))" 或结束括号为 "())))" 。
返回 为使结果字符串 s 有效而必须添加的最少括号数。

 

示例 1：

输入：s = "())"
输出：1
示例 2：

输入：s = "((("
输出：3
 

提示：

1 <= s.length <= 1000
s 只包含 '(' 和 ')' 字符。
*/

#include <string>
using namespace std;

int minAddToMakeValid(string s) 
{
    int left_need = 0, right_need = 0;
    for(char c : s)
    {
        if(c == '(')
        {
            right_need ++;
        }
        else if(c == ')')
        {
            right_need --;
        }

        if(right_need == -1) // 右括号太多了, 这下需要加左括号来平衡了
        {
            right_need = 0;
            left_need ++;
        }
    }
    return left_need + right_need;
}

// 下面是以left为主的,

int minAddToMakeValid(string s) 
{
    int left_need = 0, right_need = 0;
    reverse(s.begin(), s.end()); // 如果以右括号为基准, 就应该从后往前遍历, 这样才能保证是正确的插入顺序
    for(char c : s)
    {
        if(c == ')')
        {
            left_need ++;
        }
        else if(c == '(')
        {
            left_need --;
        }

        if(left_need == -1) 
        {
            left_need = 0;
            right_need ++;
        }
    }
    return left_need + right_need;
}