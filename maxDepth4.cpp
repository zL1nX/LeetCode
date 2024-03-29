/*
如果字符串满足以下条件之一，则可以称之为 有效括号字符串（valid parentheses string，可以简写为 VPS）：

字符串是一个空字符串 ""，或者是一个不为 "(" 或 ")" 的单字符。
字符串可以写为 AB（A 与 B 字符串连接），其中 A 和 B 都是 有效括号字符串 。
字符串可以写为 (A)，其中 A 是一个 有效括号字符串 。
类似地，可以定义任何有效括号字符串 S 的 嵌套深度 depth(S)：

depth("") = 0
depth(C) = 0，其中 C 是单个字符的字符串，且该字符不是 "(" 或者 ")"
depth(A + B) = max(depth(A), depth(B))，其中 A 和 B 都是 有效括号字符串
depth("(" + A + ")") = 1 + depth(A)，其中 A 是一个 有效括号字符串
例如：""、"()()"、"()(()())" 都是 有效括号字符串（嵌套深度分别为 0、1、2），而 ")(" 、"(()" 都不是 有效括号字符串 。

给你一个 有效括号字符串 s，返回该字符串的 s 嵌套深度 。

 

示例 1：

输入：s = "(1+(2*3)+((8)/4))+1"
输出：3
解释：数字 8 在嵌套的 3 层括号中。
示例 2：

输入：s = "(1)+((2))+(((3)))"
输出：3
示例 3：

输入：s = "1+(2*3)/(2-1)"
输出：1
示例 4：

输入：s = "1"
输出：0
 

提示：

1 <= s.length <= 100
s 由数字 0-9 和字符 '+'、'-'、'*'、'/'、'('、')' 组成
题目数据保证括号表达式 s 是 有效的括号表达式
通过次数23,310提交次数27,831

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-nesting-depth-of-the-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>

using namespace std;

int maxDepth(string s) 
{
    int pcnt = 0, maxn = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            pcnt++;
            maxn = max(maxn, pcnt);
        }
        else if(s[i] == ')')
        {
            pcnt--;
        }
    }
    return maxn;
}

// 属实流汗黄豆，因为这其实就是一个非常简单的题：找到这个字符串中嵌套括号层数的最大值

// 这非得描述成那个样子，本以为要使用栈等方法去实现

// 但实际上就遍历整个字符串中的括号数目就可以，遇到左括号加1，遇到右括号减1

// 因为题目给出的字符串一定是有效的括号匹配的字符串，所以不用担心这种方法统计出来括号数量的正确性

// 在每次累加过程中，记录左括号的最大值，在保证括号嵌套方式一定正确的前提下，这个最大值就一定是该字符串的最大嵌套深度