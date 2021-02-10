/*
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
 

示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False
 

注意：

输入的字符串只包含小写字母
两个字符串的长度都在 [1, 10,000] 之间

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
using namespace std;

bool isPermutation(string candidate, vector<int> target, int len)
{
    int cnt = 0;
    for(char c : candidate)
    {
        target[c - 'a']--;
        if(target[c - 'a'] == 0)
        {
            cnt++;
        }
    }
    return cnt == len;
}

bool checkInclusion(string s1, string s2) 
{
    vector<int> target(26,0);
    if(s1.length() > s2.length()) // 注意对特殊情况的讨论
    {
        return false;
    }
    int window = s1.length(), len = 0;
    for(char c : s1)
    {
        target[c - 'a']++;
        if(target[c - 'a'] == 1) // 注意对哈希表的计数
        {
            len++;
        }
    }
    for(int i = 0; i + window <= s2.length(); i++)
    {
        string candidate = s2.substr(i, window); // 注意最后一个window
        if(isPermutation(candidate, target, len))
        {
            return true;
        }
    }
    return false;
}

// 典型的滑动窗口题，需要注意一些实现上的问题