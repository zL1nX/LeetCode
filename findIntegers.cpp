/*
给定一个正整数 n，找出小于或等于 n 的非负整数中，其二进制表示不包含 连续的1 的个数。

示例 1:

输入: 5
输出: 5
解释: 
下面是带有相应二进制表示的非负整数<= 5：
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
其中，只有整数3违反规则（有两个连续的1），其他5个满足规则。
说明: 1 <= n <= 109

通过次数5,161提交次数13,766

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

int findIntegers(int n) 
{
    vector<int> dp(31);
    dp[0] = dp[1] = 1;
    int lastNode = 0, res = 0;
    for(int i = 2; i < 31; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2]; // 一旦右子树根节点为1，就是左子树的t-1和t-2高度的累加
    }
    for(int i = 29; i >= 0; i--)
    {
        int maxVal = 1 << i; // 这层的右子树的最小值，即100000.... 这种 
        if((n & maxVal) != 0) // 不为0 说明有右子树
        {
            n -= maxVal;
            res += dp[i + 1];
            if(lastNode == 1) // 上一层也是1
            {
                break; //  不是continue，按层遍历 ；因为连续两个1一定出现的某个分支的最右边的子树，因此一旦包含了，就可以直接break
                // 右子树根节点如果为1，同时自己也是1，那么整个分支就直接pass掉；而这个分支也只会是最后的分支，所以直接break
            }
            lastNode = 1;
        }
        else // 没有右子树，循环继续
        {
            lastNode = 0; // 如果没有右子树，则说明左半边不一定是满二叉树，循环继续到下一层看看
        }
        if(i == 0)
        {
            res++;
        }
    }
    return res;
}

// 它这个遍历树的逻辑不是按照树上元素进行遍历的，而是按照每一层右子树的最小值来控制
// 其实不是很懂，算了不求甚解罢了