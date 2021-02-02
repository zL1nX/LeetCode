/*
给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。

注意：字符串长度 和 k 不会超过 104。

 

示例 1：

输入：s = "ABAB", k = 2
输出：4
解释：用两个'A'替换为两个'B',反之亦然。
示例 2：

输入：s = "AABABBA", k = 1
输出：4
解释：
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-repeating-character-replacement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
using namespace std;

int characterReplacement(string s, int k) 
{
    vector<int> freq(26,0);
    int right = 0, left = 0, maxn = 0;
    while(right < s.length())
    {
        freq[s[right] - 'A']++;
        maxn = max(maxn, freq[s[right] - 'A']);
        if(right - left + 1 - maxn > k)
        {
            freq[s[left] - 'A']--;
            left++;
        }
        right++;
    }
    return right - left;
}

//最后返回的是right-left而没有+1是因为right已经++过了，相当于+1

// 这个解法妙就妙在它是用右指针去移动，左指针在不满足条件时移动，始终维护窗口就是最大值