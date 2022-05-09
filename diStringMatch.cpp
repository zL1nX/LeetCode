/*
由范围 [0,n] 内所有整数组成的 n + 1 个整数的排列序列可以表示为长度为 n 的字符串 s ，其中:

如果 perm[i] < perm[i + 1] ，那么 s[i] == 'I' 
如果 perm[i] > perm[i + 1] ，那么 s[i] == 'D' 
给定一个字符串 s ，重构排列 perm 并返回它。如果有多个有效排列perm，则返回其中 任何一个 。

 

示例 1：

输入：s = "IDID"
输出：[0,4,1,3,2]
示例 2：

输入：s = "III"
输出：[0,1,2,3]
示例 3：

输入：s = "DDI"
输出：[3,2,0,1]
 

提示：

1 <= s.length <= 105
s 只包含字符 "I" 或 "D"

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/di-string-match
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>

using namespace std;

vector<int> diStringMatch(string s) 
{
    int n = s.size(), small = 0, big = n;
    vector<int> res;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'I')
        {
            res.push_back(small);
            small++;
        }
        else
        {
            res.push_back(big);
            big--;
        }
    }
    res.push_back(small); // 两边最后一定是相遇的
    return res;
}

// 乍一看还有些犯嘀咕, 想着简单题也要回溯了吗

// 但其实发现直接贪心就可以, 遇到I的话从最小的开始放, 遇到D的话从最大的开始放

// 因为也是不重不漏, 所以最后两边一定是相遇的

// 挺有意思的一道题