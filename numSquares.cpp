/*
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

 

示例 1：

输入：n = 12
输出：3 
解释：12 = 4 + 4 + 4
示例 2：

输入：n = 13
输出：2
解释：13 = 4 + 9
 
提示：

1 <= n <= 104


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-squares
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

int numSquares(int n) 
{   
    vector<int> dp(n + 1);
    for(int i = 1; i <= n; i++)
    {
        dp[i] = i;
        for(int j = 1; i - j * j >= n; j ++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}

// 思路非常相似，但有两点不同
    // 平方数
    // 最少的数

// 平方数这一点由j * j来保证，即保证递归到下一个状态时，肯定是由一个平方数递归来的
//  最少的数这一点由min来保证，即对不同的j，求min，相当于考察各种转移来的状态中最小的那个
// 但也可以看到，我们会遍历到很多无用状态，导致此处dp的效率其实并不是很高