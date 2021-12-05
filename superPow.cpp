/*
你的任务是计算 ab 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。

 

示例 1：

输入：a = 2, b = [3]
输出：8
示例 2：

输入：a = 2, b = [1,0]
输出：1024
示例 3：

输入：a = 1, b = [4,3,3,8,5,2]
输出：1
示例 4：

输入：a = 2147483647, b = [2,0,0]
输出：1198
 

提示：

1 <= a <= 231 - 1
1 <= b.length <= 2000
0 <= b[i] <= 9
b 不含前导 0
通过次数17,568提交次数33,544

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/super-pow
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <math.h>
using namespace std;

const int base = 1337;

int powmod(int a, int k)
{
    int res = 1;
    a %= base;
    for(int i = 0; i < k; i++)
    {
        res = (res * a) % base;
    }
    return res;
}

int superPow(int a, vector<int>& b) 
{
    if(b.size() == 0) return 1;
    int last = b.back();
    b.pop_back();
    return (powmod(superPow(a, b), 10) + powmod(a, last)) % base;
}

// 直接去求次方好像谁都会，但好像也谁都不会

// 这里用的就是秦九韶算法，即每次算一位，然后10的倍数往前算

// 可以递归，也可以迭代去写

// 这题感觉问题很基础，但真的去写不一定能写对，面试可以试试