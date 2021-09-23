/*
给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。

整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x

 

示例 1：

输入：n = 27
输出：true
示例 2：

输入：n = 0
输出：false
示例 3：

输入：n = 9
输出：true
示例 4：

输入：n = 45
输出：false
 

提示：

-231 <= n <= 231 - 1
 

进阶：

你能不使用循环或者递归来完成本题吗？


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-three
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


using namespace std;

bool isPowerOfThree(int n) 
{
    int bit, sum = 0;
    while(n)
    {
        bit = n % 3;
        n /= 3;
        sum += bit;
    }
    return sum == 1;
}

// 别看是简单题，其实写法有很多，还可以二分查找、递归等等

// 这种写法算是比较稳健而且普适的了

// 不用循环递归的，基本都是取巧去做（比如打表，或者利用一些边界条件），这其实不太好

// 虽然是简单题，但感觉挺容易就写错了