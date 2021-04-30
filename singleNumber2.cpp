/*

给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

 

示例 1：

输入：nums = [2,2,3,2]
输出：3
示例 2：

输入：nums = [0,1,0,1,0,1,99]
输出：99
 

提示：

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次
*/



#include <vector>
using namespace std;

// 牢牢把握其他所有数字都出现3次，只有一个数字出现1次这个含义

int singleNumber(vector<int>& nums) 
{
    int res = 0;
    for(int i = 0; i < 32; i++) // 以位为视角，考察每个数在这位上的情况
    {
        int bit_cnt = 0, mask = 1 << i; // 通过mask考察每一位上的值，cnt进行累加
        for(int k = 0; k < nums.size(); k++)
        {
            if((nums[k] & mask) != 0) // 若这一位不是0就累加（这里的判断其实有点多余，但写出来比较清晰）
            {
                bit_cnt++;
            }
        }
        if(bit_cnt % 3 != 0) // 看所有数的这位累加结果如何，因为如果其他所有数都是3次的话，那么对应二进制位也是3次，那么累加结果必然是3N或3N+1
        {
            res |= mask; // 或起来相当于每位加起来
        }
        // 3N 表示只1次的那个数这位是0
        // 3N 表示只1次的那个数这位是1
    }
    return res;
}

// 非常妙妙的解法
// 我最开始想着通过累加和的角度把这个只1次的数筛出来，因为累加和的结果也与3的倍数有关
// 但这道题从位的角度来思考确实很8错