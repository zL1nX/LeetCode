/*
给出一个字符串 s（仅含有小写英文字母和括号）。

请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。

注意，您的结果中 不应 包含任何括号。

 

示例 1：

输入：s = "(abcd)"
输出："dcba"
示例 2：

输入：s = "(u(love)i)"
输出："iloveu"
示例 3：

输入：s = "(ed(et(oc))el)"
输出："leetcode"
示例 4：

输入：s = "a(bcdefghijkl(mno)p)q"
输出："apmnolkjihgfedcbq"
 

提示：

0 <= s.length <= 2000
s 中只有小写英文字母和括号
我们确保所有括号都是成对出现的
通过次数16,246提交次数26,447

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <stack>
using namespace std;


string reverseParentheses(string s) 
{
    stack<string> ss;
    string middle = "";
    for(auto& ch : s)
    {
        if(ch == '(')
        {
            ss.push(middle); // 新middle，先保存
            middle = "";
        }
        else if(ch == ')')
        {
            reverse(middle.begin(), middle.end()); // 当前middle就是一对括号里的字符串
            middle = ss.top() + middle; // 冒险还需继续，反转之后要与前面保存下来的middle拼接，继续往后
            ss.pop();
        }
        else
        {
            middle.push_back(ch);
        }
    }
    return middle;
}

// 一开始没理解题意，以为是要各个括号内的内容倒序后再拼接；没想到就是和栈一样，从内到外进行倒序然后拼接；所以最后有的例子里部分子串的顺序没变

// 因此，就可以直接模拟栈的操作了

// 具体策略就是用一个middle变量维护着括号之间的字符串，从（开始到）结束，遇到（时，将原middle先保存，即入栈，然后令新middle为空；遇到）时，将当前的middle反转

// 因此每次将反转后的middle与栈里的top进行拼接，就能模拟出这个过程了

// 典中典的面试题，需要多作