/*
给你一个字符串 s 和一个字符串数组 dictionary 作为字典，找出并返回字典中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。

如果答案不止一个，返回长度最长且字典序最小的字符串。如果答案不存在，则返回空字符串。

 

示例 1：

输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
输出："apple"
示例 2：

输入：s = "abpcplea", dictionary = ["a","b","c"]
输出："a"
 

提示：

1 <= s.length <= 1000
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 1000
s 和 dictionary[i] 仅由小写英文字母组成


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <vector>
using namespace std;

string findLongestWord(string s, vector<string>& dictionary) 
{
    vector<string> candidate;
    for(string ss : dictionary)
    {
        int j = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ss[j])
            {
                j++; // 看有多少个元素在s中
            }
        }
        if(j == ss.length()) // 用这方法来筛选出符合题意的元素感觉还挺巧妙的
        {
            candidate.push_back(ss);
        }
    }
    sort(candidate.begin(), candidate.end(), [](const string& s1, const string& s2){
        return (s1.length() > s2.length()) || (s1.length() == s2.length() && s1 < s2);
    });
    return candidate.size() > 0 ? candidate[0] : "";
}

// 乍一看感觉不太好做，但实际上道理非常简单的一道题，适合面试