/*
对于一个 正整数，如果它和除了它自身以外的所有 正因子 之和相等，我们称它为 「完美数」。

给定一个 整数 n， 如果是完美数，返回 true，否则返回 false

 

示例 1：

输入：num = 28
输出：true
解释：28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, 和 14 是 28 的所有正因子。
示例 2：

输入：num = 6
输出：true
示例 3：

输入：num = 496
输出：true
示例 4：

输入：num = 8128
输出：true
示例 5：

输入：num = 2
输出：false
 

提示：

1 <= num <= 108
通过次数38,572提交次数87,276


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <math.h>

using namespace std;

bool checkPerfectNumber(int num) 
{
    if(num <= 5){
        return false;
    }
    int sum = 1;
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            sum += i;
            if(num / i != i)
            {
                sum += num / i;
            }
        }
    }
    return sum;
}

// 直接循环写就好，因子直接用sqrt来削减就好，但要注意到平方数的最后那个因子不要重复加

// 还有点坑的地方就是1这个数并不是，因为1的因子是1，所以1对应的是0

// 别的直接写就好