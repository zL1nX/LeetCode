/*
给定一个表示整数的字符串 n ，返回与它最近的回文整数（不包括自身）。如果不止一个，返回较小的那个。

“最近的”定义为两个整数差的绝对值最小。

 

示例 1:

输入: n = "123"
输出: "121"
示例 2:

输入: n = "1"
输出: "0"
解释: 0 和 2是最近的回文，但我们返回最小的，也就是 0。
 

提示:

1 <= n.length <= 18
n 只由数字组成
n 不含前导 0
n 代表在 [1, 1018 - 1] 范围内的整数
通过次数6,816提交次数31,093


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-closest-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<long> getCandidates(const string& n)
{
    int l = n.length();
    vector<long> candidates = {
        (long)pow(10, l - 1) - 1, 
        (long)pow(10, l) + 1
    };
    long halfpart = stol(n.substr(0, (l + 1) / 2));
    for(int i : {halfpart - 1, halfpart, halfpart + 1})
    {
        string prefix = to_string(i);
        string candidate = prefix + string(prefix.rbegin() + (l & 1), prefix.rend());
        candidates.push_back(stol(candidate));
    }
    return candidates;
}

string nearestPalindromic(string n) 
{
    long nnum = stol(n), res = -1;
    const vector<long>& candidates = getCandidates(n);
    for(auto& can : candidates)
    {
        if(can == nnum)
            continue;
        if(res == -1 || (abs(can - nnum) < abs(res - nnum)) ||
        (abs(can - nnum) == abs(res - nnum) && can < res))
        {
            res = can;
        }
    }
    return to_string(res);
}

//https://leetcode-cn.com/problems/find-the-closest-palindrome/solution/xun-zhao-zui-jin-de-hui-wen-shu-by-leetc-biyt/