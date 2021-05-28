/*
两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。

计算一个数组中，任意两个数之间汉明距离的总和。

示例:

输入: 4, 14, 2

输出: 6

解释: 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
所以答案为：
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
注意:

数组中元素的范围为从 0到 10^9。
数组的长度不超过 10^4。
通过次数14,614提交次数25,724

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/total-hamming-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

// int hammingDistance(int x, int y) 
// {
//     int res = x ^ y, cnt = 0;
//     // 题目求的是汉明距离，因此要异或后看1的位数
//     while(res)
//     {
//         cnt += res % 2 ;
//         res /= 2;
//     }
//     return cnt;
// }

// int totalHammingDistance(vector<int>& nums) 
// {
//     int n = nums.size(), res = 0;
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = i + 1; j < n; j++)
//         {
//             res += hammingDistance(nums[i], nums[j]);
//         }
//     }
//     return res;
// }

// int totalHammingDistance(vector<int>& nums) 
// {
//     int n = nums.size(), res = 0;
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = i + 1; j < n; j++)
//         {
//             int hd = 0;
//             for(int k = 31; k >= 0; k--)
//             {
//                 hd += ((nums[i] >> k) & 1) ^ ((nums[j] >> k) & 1);
//             }
//             res += hd;
//             //res += hammingDistance(nums[i], nums[j]);
//         }
//     }
//     return res;
// }

int totalHammingDistance(vector<int>& nums) 
{
    int n = nums.size(), res = 0;
    for(int b = 0; b < 30; b ++) //按位计算
    {
        int bit_count = 0;
        for(auto& num : nums)
        {
            bit_count += (num >> b) & 1; // 位为1的个数
        }
        res += bit_count * (n - bit_count); // 0 * 1
    }
    return res;
}

// 果不其然，上面两种写法都直接超时了，说明复杂度还需要再降

// 题解的方法是，注意到每一位的汉明距离和其他位都没有关系

// 那么为什么不直接按位去遍历呢？

// 同时，对于每一位而言，其汉明距离之和就是1的个数 * 0的个数（因为是两两异或后加起来，仔细想想其中的道理）

// 那么循环的编写就很简单了

// 注意最终要求的内容，选择恰当的循环变量