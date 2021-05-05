/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。
 

示例 1：

输入：x = 123
输出：321
示例 2：

输入：x = -123
输出：-321
示例 3：

输入：x = 120
输出：21
示例 4：

输入：x = 0
输出：0
 

提示：

-231 <= x <= 231 - 1
通过次数685,322提交次数1,941,853

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <limits.h>
using namespace std;


int reverse(int x) 
{
   int rev = 0;
    while (x != 0) {
        if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
            return 0;
        }
        int digit = x % 10;
        x /= 10;
        rev = rev * 10 + digit;
    }
    return rev;
}


int reverse(int x)
{
    int res = 0;
    while(x != 0)
    {
        if(res < INT_MIN / 10 || res > INT_MAX / 10) // 先判后算，注意这里的溢出要除10
        {
            return 0;
        }
        int digit = x % 10;
        res = res * 10 + digit; // 后面乘10后加digit再返回
        x /= 10;
    }
    return res;
}

// 之所以要写成那种很诡异的除10的写法，是因为比如12345678这种，倒过来的时候数就会变得非常大

// 因此，下面这种写法会在判断是否溢出前就给溢出了。所以要在操作之前先预判下会不会溢出，要会的话直接返回，不会的话再说

/* 一种看似正常，但实际是错的样例 */

// int reverse(int x)
// {
//     int res = 0;
//     while(x != 0)
//     { 
//         int digit = x % 10;
//         res = res * 10 + digit; // 后面乘10后加digit再返回
//         if(res < INT_MIN || res > INT_MAX) // 先判后算，注意这里的溢出要除10
//         {
//             return 0;
//         }
//         x /= 10;
//     }
//     return res;
// }

// 1534236469, -2147483412 注意这个样例

