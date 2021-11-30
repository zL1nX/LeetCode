/*
给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。

请你返回字符串的能量。

 

示例 1：

输入：s = "leetcode"
输出：2
解释：子字符串 "ee" 长度为 2 ，只包含字符 'e' 。
示例 2：

输入：s = "abbcccddddeeeeedcba"
输出：5
解释：子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。
示例 3：

输入：s = "triplepillooooow"
输出：5
示例 4：

输入：s = "hooraaaaaaaaaaay"
输出：11
示例 5：

输入：s = "tourist"
输出：1
 

提示：

1 <= s.length <= 500
s 只包含小写英文字母。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/consecutive-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
using namespace std;

int maxPower(string s) 
{
    int maxn = 0;
    int left = 0, right = 0;
    while(right < s.length())
    {
        if(s[right] == s[left])
        {
            right++;
        }
        else
        {
            maxn = max(maxn, right - left);
            left = right;
        }
    }
    return max(maxn, right - left);
}

// 题意和要做的事情其实很好理解，就是看最长连续子串的长度

// 因此，找最长不用考虑，只需要考虑连续子串

// 而这可以直接双指针去做，每次更新最大值即可；每次遇到不一样的字符，就移动left指针

// 而要记得最后返回的时候，还应再看下此时right-left的值，因为原有循环里没有看这个最后的情况


/*
int maxPower(string s) {
        int ans = 1, cnt = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                ++cnt;
                ans = max(ans, cnt);
            } else {
                cnt = 1;
            }
        }
        return ans;
    }

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/consecutive-characters/solution/lian-xu-zi-fu-by-leetcode-solution-lctm/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
这是一种非双指针的写法，似乎更不容易写错一些

// 个人觉得这题可以用来作为面试的简单题，代码不多，但需要仔细的写一下和想一下，并不一定一次就能写对
*/