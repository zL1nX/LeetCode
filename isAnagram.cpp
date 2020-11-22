/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
*/
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) 
{
    unordered_map<char, int> stable, ttable;
    if(s.length() != t.length())
    {
        return false;
    }
    for(int i = 0; i < s.length(); i ++)
    {
        stable[s[i]]++;
        ttable[t[i]]++;
    }
    if(stable.size() != ttable.size())
    {
        return false;
    }
    for(int i = 0; i < s.length(); i++)
    {
        if(stable[s[i]] != ttable[s[i]])
        {
            return false;
        }
    }
    return true;
}

/*
bool isAnagram(string s, string t) 
{
    unordered_map<char, int> stable;
    if(s.length() != t.length())
    {
        return false;
    }
    for(int i = 0; i < s.length(); i ++)
    {
        stable[s[i]]++;
        stable[t[i]]--;
    }
    for(auto i : stable)
    {
        if(i.second != 0)
        {
            return false;
        }
    }
    return true;
}
*/