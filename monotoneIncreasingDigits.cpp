/*
给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）

示例 1:

输入: N = 10
输出: 9
示例 2:

输入: N = 1234
输出: 1234
示例 3:

输入: N = 332
输出: 299
说明: N 是在 [0, 10^9] 范围内的一个整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/monotone-increasing-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
using namespace std;

int monotoneIncreasingDigits(int N) 
{
    string snum = to_string(N);
    int md = -1, idx = -1;
    for(int i = 0; i < snum.length() - 1;i ++)
    {
        if(md < snum[i])
        {
            md = snum[i];
            idx = i;
        }
        if(snum[i] > snum[i + 1])
        {
            snum[idx]--;
            for(int j = idx + 1; j < snum.length(); j++)
            {
                snum[j] = '9';
            }
        }
    }
    return stoi(snum);
}

// 找到位于最前面的那个最大数，记住位置（idx）后，如果发现有当前位大于后面的位，那么旧把之前那个最大位
// 的值减一，最大位之后的位都变成9（贪心）