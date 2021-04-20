/*
实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

 

说明：

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。

 

示例 1：

输入：haystack = "hello", needle = "ll"
输出：2
示例 2：

输入：haystack = "aaaaa", needle = "bba"
输出：-1
示例 3：

输入：haystack = "", needle = ""
输出：0
 

提示：

0 <= haystack.length, needle.length <= 5 * 104
haystack 和 needle 仅由小写英文字符组成


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
using namespace std;

int strStr(string haystack, string needle) 
{
    int m = needle.length(), n = haystack.length();
    if(m == 0)
    {
        return 0;
    }
    int pos = -1;
    for(int i = 0; i < n; i ++)
    {
        if(haystack[i] == needle[0])
        {
            int p = 1;
            while(p < m)
            {
                if(haystack[i + p] != needle[p])
                {
                    break;
                }
                p++;
            }
            if(p == m)
            {
                pos = i;
                break;
            }
        }
    }
    return pos;
}

// 也是相对适合练手的一道题，思路比较暴力，但实际上应该用KMP等经典匹配算法

// 但肯定不能去用API做题