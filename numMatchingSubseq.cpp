/*
给定字符串 s 和字符串数组 words, 返回  words[i] 中是s的子序列的单词个数 。

字符串的 子序列 是从原始字符串中生成的新字符串，可以从中删去一些字符(可以是none)，而不改变其余字符的相对顺序。

例如， “ace” 是 “abcde” 的子序列。
 

示例 1:

输入: s = "abcde", words = ["a","bb","acd","ace"]
输出: 3
解释: 有三个是 s 的子序列的单词: "a", "acd", "ace"。
Example 2:

输入: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
输出: 2
 

提示:

1 <= s.length <= 5 * 104
1 <= words.length <= 5000
1 <= words[i].length <= 50
words[i]和 s 都只由小写字母组成。
*/
#include <vector>
#include <string>

using namespace std;

int numMatchingSubseq(string s, vector<string>& words) 
{
    int m = s.length();

    vector<vector<int>> index(256);
    for(int i = 0; i < m; i++)
    {
        char c = s[i];
        index[c].push_back(i);
    }

    int cnt = 0;
    for(string word : words)
    {
        int n = word.length(), i = 0, j = 0;
        for(; i < n; i++)
        {
            char c = word[i];
            if(index[c].empty())
            {
                break;
            }
            auto loc = lower_bound(index[c].begin(), index[c].end(), j);
            if(loc == index[c].end())
            {
                break;
            }
            j = *loc + 1;
        }
        if(i == n)
        {
            cnt++;
        }
    }

    return cnt;
}

// 792-匹配子序列的单词数