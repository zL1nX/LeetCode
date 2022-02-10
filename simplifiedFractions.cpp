/*
给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于  n 的 最简 分数 。分数可以以 任意 顺序返回。

 

示例 1：

输入：n = 2
输出：["1/2"]
解释："1/2" 是唯一一个分母小于等于 2 的最简分数。
示例 2：

输入：n = 3
输出：["1/2","1/3","2/3"]
示例 3：

输入：n = 4
输出：["1/2","1/3","1/4","2/3","3/4"]
解释："2/4" 不是最简分数，因为它可以化简为 "1/2" 。
示例 4：

输入：n = 1
输出：[]
 

提示：

1 <= n <= 100
通过次数10,140提交次数15,519

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/simplified-fractions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

vector<string> simplifiedFractions(int n) 
{
    vector<string> res;
    for(int num = 1; num < n; num++)
    {
        for(int denom = num + 1; denom <= n; denom++)
        {
            if(gcd(denom, num) && num != 1)
            {
                continue;
            }
            res.push_back(to_string(num) + "/" + to_string(denom));
        }
    }
    return res;
}

// 正向从分子开始遍历，逐渐累加，在累加过程中判断是否互质

// 然后直接加进来就好，本以为这种暴力方法会超时，但没想到直接就过了