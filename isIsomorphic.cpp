/*
给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:

输入: s = "egg", t = "add"
输出: true
示例 2:

输入: s = "foo", t = "bar"
输出: false
示例 3:

输入: s = "paper", t = "title"
输出: true
说明:
你可以假设 s 和 t 具有相同的长度。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/isomorphic-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) 
{
    unordered_map<char, char> s1, s2;
    for(int i = 0;i < s.size(); i ++)
    {
        char x = s[i], y = t[i];
        if((s1[x] && s1[x] != y) || (s2[y] && s2[y] != x))
        {
            return false;
        }
        s1[x] = y;
        s2[y] = x;
    }
    return true;
}

// 本质上就是通过哈希表构建双射关系