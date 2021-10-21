/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

 

示例 1：

输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。
示例 2：

输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。
示例 3：

输入：digits = [0]
输出：[1]
 

提示：

1 <= digits.length <= 100
0 <= digits[i] <= 9
通过次数363,938提交次数793,046

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) 
{
    // long long res = 0;
    // for(int i = 0; i < digits.size(); i++)
    // {
    //     res = res * 10 + digits[i];
    // }
    // res += 1;
    // vector<int> ans;
    // while(res)
    // {
    //     ans.push_back(res % 10);
    //     res /= 10;
    // }
    // reverse(ans.begin(), ans.end());
    // return ans;
}

vector<int> plusOne(vector<int>& digits) 
{
   int len=digits.size();
    for(int i=len-1;i>-1;i--)
    {
        if(digits[i]==9)
        {
            digits[i]=0;
        }
        else
        {
            digits[i]++;
            break;
        }
    }
    if(digits[0]==0) // 循环完了都没return，此时首位必然为0（因为进位得到的）
    {
        digits.push_back(0);
        digits[0]=1;
    }
    return digits;
}

// 这他妈算简单？

// 刚开始直接按转换整数去写，果然他娘的溢出了

// 因为这道题的操作很少，就是+1与进位，所以完全可以在原数组上完成

// 而写时只要有一位不是9，那么+1肯定没问题，所以就能直接return

// 而如果整个循环都执行完还没return，说明此时数组中全是9，那么循环后作一个1000xx的数组即可

// 面试如果考这个，感觉一下慌了可能就写不出来

// 核心在于，只有1位的加法，以及进位始终都只有1