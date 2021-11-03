/*
给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

进阶：不要 使用任何内置的库函数，如  sqrt 。

 

示例 1：

输入：num = 16
输出：true
示例 2：

输入：num = 14
输出：false
 

提示：

1 <= num <= 2^31 - 1
通过次数86,835提交次数196,144

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-perfect-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
using namespace std;

bool isPerfectSquare(int num) 
{
    int left = 1, right = num;
    while(left < right)
    {
        int mid = left + (right - left) / 2, t = num / mid;
        if(t == mid) return true;
        else if(mid > num / mid)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left * left == num;
}

// 回字的四种写法，二分属实可以，而且刚开始其实都没想到二分去做

// 二分的思路非常简单，但要注意几个点：整数类型长度溢出、除法转乘法（防止除0）、左闭右开

// 尤其是前两个点，能转换成 a * a = b，就不要写成 c = b / a，这样不仅会有精度损失，而且会出现zero division

// 其他的方法：暴力（遍历+判断），sqrt判断，牛顿迭代法、完全平方数肯定是前n个连续奇数的和（遍历法）