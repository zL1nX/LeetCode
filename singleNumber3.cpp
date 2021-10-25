/*
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

 

进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

 

示例 1：

输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。
示例 2：

输入：nums = [-1,0]
输出：[-1,0]
示例 3：

输入：nums = [0,1]
输出：[1,0]
提示：

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
除两个只出现一次的整数外，nums 中的其他数字都出现两次
通过次数56,612提交次数77,857
请问您在哪类招聘中遇到此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

vector<int> singleNumber(vector<int>& nums) 
{
    int x = 0;
    for(int i = 0; i < nums.size(); i++) {
        x ^= nums[i];
    }
    int lsb = (x == INT_MIN) ? x : x & -x;
    int bit1 = 0, bit2 = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] & lsb){
            bit1 ^= nums[i];
        }else{
            bit2 ^= nums[i];
        }
    }
    return {bit1, bit2};
}

// 这思路也太残暴了，直接根据最低一位来进行分类，即先找到总异或结果的最低有效位

// 那么必然数字可以分为两类，一类对应的这位是1，一类是0，而且只出现一次的两数必然在不同的类里

// 这样才能保证异或的总结果这位是1

// 这他妈谁会能这么思考啊，哈希表不好吗