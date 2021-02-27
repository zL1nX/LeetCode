/*
给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。

 

示例 1：

输入：s = "aaabb", k = 3
输出：3
解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。
示例 2：

输入：s = "ababbc", k = 2
输出：5
解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
 

提示：

1 <= s.length <= 104
s 仅由小写英文字母组成
1 <= k <= 105


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <vector>
using namespace std;

int longestSubstring(string s, int k) 
{
    if(s.empty() || s.length() < k)
    {
        return 0;
    }

    // 记录当前字符串中的字符频数
    vector<int> hashed(26, 0);
    for(auto& c : s)
    {
        hashed[c]++;
    }

    // 找到当前字符串中出现的第一个不符合次数 大于等于k的位置
    int i = 0;
    while(i < s.length() && hashed[s[i]] >= k)
    {
        i++;
    }
    // 要是整个串都满足，直接返回即可
    if(s.length() == i)
    {
        return s.length();
    }
    // 被这个字符分隔的左边那部分
    int l = longestSubstring(s.substr(0, i), k);

    // 防止有多个不符合要求的字符相连
    while(i < s.length() && hashed[s[i]] < k)
    {
        i++;
    }

    // 被这个字符分隔的右边那部分
    int r = longestSubstring(s.substr(i), k);
    // 二分查找 + 递归实现 对每个分隔字符子段内的检查
    return max(l, r);
}

// 这个解法的思想非常好，首先是将问题转化为，找到那些不满足条件的字符，要返回的子串肯定就位于这些字符之间

// 那么就在这些分隔的字符之间寻找，如二分查找，递归地找到最大的那部分子串，就得到了题目要的结果