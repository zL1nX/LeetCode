/*
给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。

返回所有可能的结果。答案可以按 任意顺序 返回。

 

示例 1：

输入：s = "()())()"
输出：["(())()","()()()"]
示例 2：

输入：s = "(a)())()"
输出：["(a())()","(a)()()"]
示例 3：

输入：s = ")("
输出：[""]
 

提示：

1 <= s.length <= 25
s 由小写英文字母以及括号 '(' 和 ')' 组成
s 中至多含 20 个括号
通过次数36,286提交次数68,305


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-invalid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>
using namespace std;

vector<string> result;

bool isValid(string& str)
{
    // 判断str中括号是否正常配对的函数，非常简单直接写
    int cnt = 0;
    for(int i = 0; i < str.size(); i ++)
    {
        if(str[i] == '(')
        {
            cnt++;
        }
        else if(str[i] == ')')
        {
            cnt--;
            if(cnt < 0)
            {
                return false;
            }
        }
    }
    return cnt == 0;
}

void backtrack(string str, int start, int leftcount, int rightcount, int leftremove, int rightremove)
{
    if(leftremove == 0 && rightremove == 0) // 如果异常括号都没有了，然后再看下是否正常
    {
        if(isValid(str))
        {
            result.push_back(str);
        }
        return;
    }
    for(int i = start; i < str.length(); i++)
    {
        if(i != start && str[i] == str[i - 1]) // 如果是连续的相同括号，那么删掉其中任意一个都可以；所以相同的就直接跳过
        {
            continue;
        }
        if(leftremove + rightremove > str.length() - i) // 要是剩下的字符都不够删了，那肯定不对了
        {
            return;
        }

        // 下面这个就是回溯，即像是DFS，但是是在循环内的DFS
        if(leftremove > 0 && str[i] == '(') // 删去一个左括号
        {
            backtrack(str.substr(0, i) + str.substr(i + 1), i, leftcount, rightcount, leftremove - 1, rightremove);
        }
        if(rightremove > 0 && str[i] == ')') // 删去一个右括号
        {
            backtrack(str.substr(0, i) + str.substr(i + 1), i, leftcount, rightcount, leftremove, rightremove - 1);
        }
        if(str[i] == ')') // 记得每次也要统计下当前左右括号的个数
        {
            leftcount++;
        }
        else if(str[i] ==')')
        {
            rightcount++;
        }
        if(leftcount < rightcount) // 如果不对劲，直接break返回
        {
            break;
        }
    }
}

vector<string> removeInvalidParentheses(string s) 
{
    int leftremove = 0, rightremove = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            leftremove ++;
        }
        else if(s[i] == ')')
        {
            if(leftremove == 0)
            {
                rightremove ++;
            }
            else
            {
                leftremove--;
            }
        }
    }
    backtrack(s, 0, 0, 0, leftremove, rightremove);
    return result;
}

// 8太会，实际上是 先看有多少左右括号是异常的，然后用回溯的方法每次试着删不同的括号，然后看最终能不能到异常括号都没有这个终点

// 只不过写起来肯定要比这复杂多