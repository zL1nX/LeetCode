/*
给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。

 

示例 1:

输入: num = 100
输出: "202"
示例 2:

输入: num = -7
输出: "-10"
 

提示：

-107 <= num <= 107

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/base-7
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <math.h>
using namespace std;

string convertToBase7(int num) 
{
    if (num == 0)
        return "0";
    int n = abs(num);
    string res;
    while(n)
    {
        res += to_string(n % 7);
        n /= 7;
    }
    reverse(res.begin(), res.end());
    if(num < 0)
    {
        res = "-" + res;
    }
    return res;
}

// 题意很简单，模拟即可。只不过写的时候其实有两种写法，一种是直接用string存储的

// 还有一种是真的把数字转换成7进制下的int之后，再tostring

// 这种写法感觉可能在样例大的时候会有溢出风险

// 写的时候想想进制转换的关系和多种解法