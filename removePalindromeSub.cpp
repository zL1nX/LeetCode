/*
给你一个字符串 s，它仅由字母 'a' 和 'b' 组成。每一次删除操作都可以从 s 中删除一个回文 子序列。

返回删除给定字符串中所有字符（字符串为空）的最小删除次数。

「子序列」定义：如果一个字符串可以通过删除原字符串某些字符而不改变原字符顺序得到，那么这个字符串就是原字符串的一个子序列。

「回文」定义：如果一个字符串向后和向前读是一致的，那么这个字符串就是一个回文。

 

示例 1：

输入：s = "ababa"
输出：1
解释：字符串本身就是回文序列，只需要删除一次。
示例 2：

输入：s = "abb"
输出：2
解释："abb" -> "bb" -> "". 
先删除回文子序列 "a"，然后再删除 "bb"。
示例 3：

输入：s = "baabb"
输出：2
解释："baabb" -> "b" -> "". 
先删除回文子序列 "baab"，然后再删除 "b"。
 

提示：

1 <= s.length <= 1000
s 仅包含字母 'a'  和 'b'
通过次数13,860提交次数19,034

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-palindromic-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
using namespace std;

int removePalindromeSub(string s) 
{
    int i = 0, j = s.size() - 1;
    while(i < j)
    {
        if(s[i] != s[j])
        {
            return 2;
        }
        i++;
        j--;
    }
    return 1;
}

// 因为只有a和b，所以最多就是删两次，一次把所有a删了，一次把所有b删了

// 那么只要做不到完美的轴对称，就说明你就取这种暴力的方法去删两次；只有完美的轴对称时，你才可能一次删完

// 挺有意思的一道题