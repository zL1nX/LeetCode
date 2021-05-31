/*
给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。

整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4x

 

示例 1：

输入：n = 16
输出：true
示例 2：

输入：n = 5
输出：false
示例 3：

输入：n = 1
输出：true
 

提示：

-231 <= n <= 231 - 1


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-four
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
using namespace std;

bool isPowerOfFour(int n) 
{
    int appeared = 0, loc = 32;
    if(n <= 0) return false;
    for(int k = 31; k >= 0; k --)
    {
        int bit = (n >> k) & 1;
        if(bit)
        {
            if(loc % 2)
            {
                return false;
            }
            appeared += 1;
        }
    }
    return appeared == 1;
}

/*
 public boolean isPowerOfFour(int n) {
        int x = 4;
        while (x > 0 && x < n) {
            x <<= 2;
        }
        return n == 1 || n == x;
    }
*/
// 和昨天那题一样，实际上就是看1出现的位置，不过4的幂的1只会出现在奇数位上

// 这样的话时间复杂度还是常数级别的
// 另外的一种判定方式是num % 3 == 1也是4的幂 
