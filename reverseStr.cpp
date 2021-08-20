/*
给定一个字符串 s 和一个整数 k，从字符串开头算起，每 2k 个字符反转前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 

示例 1：

输入：s = "abcdefg", k = 2
输出："bacdfeg"
示例 2：

输入：s = "abcd", k = 2
输出："bacd"
 

提示：

1 <= s.length <= 104
s 仅由小写英文组成
1 <= k <= 104
通过次数46,145提交次数78,630


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-string-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <algorithm>
using namespace std;

string reverseStr(string s, int k) 
{
    int n = s.length(), r = n % (2 * k);
    for(int i = 0; i < n - r; i += 2 * k){
        reverse(s.begin() + i, s.begin() + i + k);
    }
    if(r < k && r > 0)
    {
        reverse(s.begin() + n - r, s.end());
    }
    else
    {
        reverse(s.begin() + n - r, s.begin() + n - r + k);
    }
    return s;
}

// 同理，直接模拟去写就可以，不过好像我这么写有点啰嗦了，应该有更简洁的写法