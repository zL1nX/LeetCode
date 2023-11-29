/*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

致谢：

特别感谢 @pbrother 添加此问题并且创建所有测试用例。

 

示例 1：

输入：s = "abc", t = "ahbgdc"
输出：true
示例 2：

输入：s = "axc", t = "ahbgdc"
输出：false
 */

#include <vector>
#include <string>

using namespace std;


bool isStringSubsequence(string s, string t) 
{
    int m = s.length(), n = t.length();
    vector<vector<int>> index(256);

    for(int i = 0; i < n; i++)
    {
        char ch = t[i];
        index[ch].push_back(i); // 将每个字符的索引都保存进来, 便于后续查找
    }

    int j = 0;
    for(int i = 0; i < m; i++)
    {
        char ch = s[i];
        if(index[ch].empty()) // 没有对应的字符, 那肯定不是子序列了
        {
            return false;
        }

        auto loc = lower_bound(index[ch].begin(), index[ch].end(), j); // 二分查找, 找到大于等于index j的那个索引
        if(loc == index[ch].end())
        {
            return false;
        }

        j = *loc + 1; // 因为lower bound是大于等于, 所以要+1

    }

    return true;
}

// 本质上是用二分来优化匹配的索引查找, 用空间换时间

// 392-判断子序列