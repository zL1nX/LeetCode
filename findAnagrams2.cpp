/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

 

示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 示例 2:

输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 

提示:

1 <= s.length, p.length <= 3 * 104
s 和 p 仅包含小写字母
通过次数107,584提交次数205,477

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool checkAnagram(vector<int>& a, vector<int>& b)
{
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i])
            return false;
    }
    return true;
}

vector<int> findAnagrams(string s, string p) 
{
    vector<int> res;
    vector<int> target(26);
    for(char& c : p)
    {
        target[c - 'a']++;
    }
    for(int i = 0;i < s.length(); i++)
    {
        string curr = s.substr(i, p.length());
        vector<int> curr_target(26);
        for(char& c: curr)
        {
            curr_target[c - 'a']++;
        }
        if(checkAnagram(target, curr_target))
        {
            res.push_back(i);
        }
    }
    return res;
}

// 之前做过这题，只要能想到滑动窗口，后面该怎么写就迎刃而解了

// 而且感觉没有特别好的优化方法，已有的方法也都是滑动窗口的变种，无非是减少一些多余操作

// 没有那种别的，特别牛逼的另一种思路的优化，所以这道题就当作是一种模板题来写吧