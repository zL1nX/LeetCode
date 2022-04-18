/*
给你一个字符串 s 和一个字符 c ，且 c 是 s 中出现过的字符。

返回一个整数数组 answer ，其中 answer.length == s.length 且 answer[i] 是 s 中从下标 i 到离它 最近 的字符 c 的 距离 。

两个下标 i 和 j 之间的 距离 为 abs(i - j) ，其中 abs 是绝对值函数。

 

示例 1：

输入：s = "loveleetcode", c = "e"
输出：[3,2,1,0,1,0,0,1,2,2,1,0]
解释：字符 'e' 出现在下标 3、5、6 和 11 处（下标从 0 开始计数）。
距下标 0 最近的 'e' 出现在下标 3 ，所以距离为 abs(0 - 3) = 3 。
距下标 1 最近的 'e' 出现在下标 3 ，所以距离为 abs(1 - 3) = 2 。
对于下标 4 ，出现在下标 3 和下标 5 处的 'e' 都离它最近，但距离是一样的 abs(4 - 3) == abs(4 - 5) = 1 。
距下标 8 最近的 'e' 出现在下标 6 ，所以距离为 abs(8 - 6) = 2 。
示例 2：

输入：s = "aaab", c = "b"
输出：[3,2,1,0]
 

提示：
1 <= s.length <= 104
s[i] 和 c 均为小写英文字母
题目数据保证 c 在 s 中至少出现一次
通过次数34,414提交次数48,732

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-distance-to-a-character
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>

using namespace std;


vector<int> shortestToChar(string s, char c) 
{
    int n = s.length();
    vector<int> pos(n);
    for(int i = 0, target = -n; i < n; i++) // 最开始target取啥都无所谓, 反正刚开始某一侧的位置值是无意义的
    {
        if(s[i] == c)
        {
            target = i;
        }
        pos[i] = i - target;
    }
    for(int i = n - 1, target = 2 * n; i >= 0; i--)
    {
        if(s[i] == c)
        {
            target = i;
        }
        pos[i] = min(pos[i], target - i);
    }
    return pos;
}

// 两次遍历, 每次遍历时记录当前这个字符到上一个目标字符的距离

// 这样一来, 先不考虑两端的情况, 对于中间那些元素, 其答案自然就可以得出 

// 因为两遍遍历是相当于取自己距离左右字符最近的那个值, 所以必然是正确的

// 而对于两端的, 只有一侧有目标字符的元素而言, 两遍遍历中的某一次遍历是无效值

// 比如对于左侧端点, 第一次遍历就填充了一些无意义值, 但到第二次反着遍历的时候, 他们对应的位置值

// 才被赋为了最近的那个字符减去自己的位置这个值

// 当然暴力或者是二分肯定是能做的, 但这个两次遍历的思路还真挺巧妙