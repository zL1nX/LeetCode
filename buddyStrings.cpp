/*
给你两个字符串 s 和 goal ，只要我们可以通过交换 s 中的两个字母得到与 goal 相等的结果，就返回 true ；否则返回 false 。

交换字母的定义是：取两个下标 i 和 j （下标从 0 开始）且满足 i != j ，接着交换 s[i] 和 s[j] 处的字符。

例如，在 "abcd" 中交换下标 0 和下标 2 的元素可以生成 "cbad" 。
 

示例 1：

输入：s = "ab", goal = "ba"
输出：true
解释：你可以交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 相等。
示例 2：

输入：s = "ab", goal = "ab"
输出：false
解释：你只能交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 不相等。
示例 3：

输入：s = "aa", goal = "aa"
输出：true
解释：你可以交换 s[0] = 'a' 和 s[1] = 'a' 生成 "aa"，此时 s 和 goal 相等。
示例 4：

输入：s = "aaaaaaabc", goal = "aaaaaaacb"
输出：true
 

提示：

1 <= s.length, goal.length <= 2 * 104
s 和 goal 由小写英文字母组成


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/buddy-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <vector>
using namespace std;

bool buddyStrings(string s, string goal) 
{
    int m = s.size();
    if(m != goal.size() || m < 2)
    {
        return false;
    }
    int a = -1, b = -1;
    if(s == goal) // 好家伙还真敢这么去写
    {   
        vector<int> v(26);
        for(int i = 0; i < m; ++i)
        {
            v[s[i] - 'a']++;
            if(v[s[i] - 'a'] > 1)
            {
                return true;
            }
        }
        return false;
    }
    for(int i = 0; i < m; i++)
    {
        if(s[i] != goal[i])
        {
            if(a == -1)
            {
                a = i;
            }
            else if(b == -1) // 这个分支发生的情形已经是a ！= -1了
            {
                b = i;
            }
            else // 这个分支表示已经有两个不相等字符了，然后这时又出现一个不相等字符
            {
                return false;
            }
        }
    }
    return b != -1 && s[a] == goal[b] && s[b] == goal[a]; // 这里直接这么写返回就行
}

// 这道题首先要脑子清楚，即先排除几个错误选项，比如长度太小等

// 之后先考虑比较容易的情况：两个字符串不相等咋办，这时用两个变量去记录出现的不同字符，然后比较s与goal对应位置上两个变量是否相等即可

// 而对于两个字符串相等的情形，最开始这块我因为效率问题没太敢写，但发现题解还真敢直接哈希表去写

// 当两个字符串相等时，如果有重复字符那就可以直接true（要没有重复字符，那肯定false了）

// 这道题要是面试的时候写，肯定容易写不出来，但一定要保证脑子清楚