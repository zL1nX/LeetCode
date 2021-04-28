/*
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。

 

示例 1：

输入：c = 5
输出：true
解释：1 * 1 + 2 * 2 = 5
示例 2：

输入：c = 3
输出：false
示例 3：

输入：c = 4
输出：true
示例 4：

输入：c = 2
输出：true
示例 5：

输入：c = 1
输出：true
 

提示：

0 <= c <= 231 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-square-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <math.h>

using namespace std;

bool judgeSquareSum(int c) 
{
    long a = 0, b = (long)sqrt(c); // 会有溢出的问题
    while(a <= b) // 注意这里的判别条件
    {
        if(a * a + b * b == c)
        {
            return true;
        }
        
        if(a * a + b * b < c)
        {
            a += 1;
        }
        else if(a * a + b * b > c)
        {
            b -= 1;
        }
    }
    return false;
    
}
// 双指针解法，本质是矩阵的搜索

// 不断调整两个数的值，让其能逼近目标值

// 初始时，b已经到达一个最大值，因此a在累加的时候很容易超过目标值，所以在大于的时候要减a

//https://leetcode-cn.com/problems/sum-of-square-numbers/solution/shuang-zhi-zhen-de-ben-zhi-er-wei-ju-zhe-ebn3/