/*

给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters 相同

 

示例 1：

输入：s = "bcabc"
输出："abc"
示例 2：

输入：s = "cbacdcbc"
输出："acdb"
 

提示：

1 <= s.length <= 104
s 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicate-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <string>
#include <vector>
using namespace std;
// 核心问题在于找关键字符，即不符合字典序的最小索引对应的字符，保证当前栈中相邻字典序是最小的
// 同时考虑字符是否在栈中，以及字符的出现次数
// 注意，不论当前字符是否入了栈，只要遍历了一次，其对应的出现次数就会减少
string removeDuplicateLetters(string s) 
{
    vector<int> instack(26, 0), times(26, 0);
    for(char c : s)
    {
        times[c - 'a']++;
    }
    string stack = "";
    for(char c : s)
    {
        if(!instack[c - 'a'])
        {
            while(!stack.empty() && stack.back() > c)
            {
                if(times[stack.back() - 'a'] > 0)
                {
                    instack[stack.back() - 'a'] = 0;
                    stack.pop_back();
                }
                else
                {
                    break;
                }
            }
            stack.push_back(c);
            instack[c - 'a'] = 1;
        }
        times[c - 'a'] --;

    }
    return stack;
}

// 题目与1081相同