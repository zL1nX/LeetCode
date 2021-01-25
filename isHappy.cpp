/*
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。

 

示例：

输入：19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/happy-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
using namespace std;


long long bitAdd(int n)
{
    long long res = 0;
    while(n)
    {
        int bit = n % 10;
        res += bit * bit;
        n /= 10;
    }
    return res;
}

bool isHappy(int n) 
{
    long long fast = 0, slow = 0;
    do{ // 快慢双指针，类似于Pollard rho算法
        fast = bitAdd(bitAdd(fast));
        slow = bitAdd(slow);
    }
    while(fast != slow); // 首先需要明确，任意一个数在这种算法下都会出现无限循环，且快慢指针会相遇，不可能出现双方即不相遇，也继续循环的状态

    if(fast == 1)
    {
        return true;
    }
    return false;
    
}