/*
给你一个仅包含小写英文字母和 '?' 字符的字符串 s，请你将所有的 '?' 转换为若干小写字母，使最终的字符串不包含任何 连续重复 的字符。

注意：你 不能 修改非 '?' 字符。

题目测试用例保证 除 '?' 字符 之外，不存在连续重复的字符。

在完成所有转换（可能无需转换）后返回最终的字符串。如果有多个解决方案，请返回其中任何一个。可以证明，在给定的约束条件下，答案总是存在的。

 

示例 1：

输入：s = "?zs"
输出："azs"
解释：该示例共有 25 种解决方案，从 "azs" 到 "yzs" 都是符合题目要求的。只有 "z" 是无效的修改，因为字符串 "zzs" 中有连续重复的两个 'z' 。
示例 2：

输入：s = "ubv?w"
输出："ubvaw"
解释：该示例共有 24 种解决方案，只有替换成 "v" 和 "w" 不符合题目要求。因为 "ubvvw" 和 "ubvww" 都包含连续重复的字符。
示例 3：

输入：s = "j?qg??b"
输出："jaqgacb"
示例 4：

输入：s = "??yw?ipkj?"
输出："acywaipkja"
 

提示：

1 <= s.length <= 100

s 仅包含小写英文字母和 '?' 字符

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
using namespace std;

string modifyString(string s) 
{
    char chs[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != '?')
        {
            continue;
        }
        pair<char, char> neighbors = {'#', '#'};
        if(i > 0)
        {
            neighbors.first = s[i - 1];
        }
        if(i < s.length() - 1 && s[i + 1] != '?')
        {
            neighbors.second = s[i + 1];
        }
        for(int c = 0; c < 26; c ++)
        {
            if(chs[c] != neighbors.first && chs[c] != neighbors.second)
            {
                s[i] = chs[c];
                break;
            }
        }
    }
    return s;
}

// 设出两端的内容之后，每次记录两边的邻居是啥，然后选一个都不相同的字符

// 其实如果懒得写那么多的话，直接用abc三个字符用来填充即可，但这样代码看起来不太好，总之这个写的时候注意点边界情况和条件的判断顺序就行

// 别的直接写就好