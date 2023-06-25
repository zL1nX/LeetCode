/*
给你一个可能含有 重复元素 的整数数组 nums ，请你随机输出给定的目标数字 target 的索引。你可以假设给定的数字一定存在于数组中。

实现 Solution 类：

Solution(int[] nums) 用数组 nums 初始化对象。
int pick(int target) 从 nums 中选出一个满足 nums[i] == target 的随机索引 i 。如果存在多个有效的索引，则每个索引的返回概率应当相等。
 

示例：

输入
["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
输出
[null, 4, 0, 2]

解释
Solution solution = new Solution([1, 2, 3, 3, 3]);
solution.pick(3); // 随机返回索引 2, 3 或者 4 之一。每个索引的返回概率应该相等。
solution.pick(1); // 返回 0 。因为只有 nums[0] 等于 1 。
solution.pick(3); // 随机返回索引 2, 3 或者 4 之一。每个索引的返回概率应该相等。
 

提示：

1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
target 是 nums 中的一个整数
最多调用 pick 函数 104 次
*/

#include <vector>
#include <random>
#include <unordered_map>
using namespace std;

// class Solution {
// private:
//     vector<int> nums;

// public:
//     Solution(vector<int>& nums) {
//         this->nums = nums;
//     }
    
//     int pick(int target) {
//         int count = 0, res = 0;
//         for(int i = 0; i < nums.size(); i++)
//         {
//             if(nums[i] != target)
//             {
//                 continue;
//             }
//             count ++;
//             if(rand() % count == 0)
//             {
//                 res = i;
//             }
//         }
//         return res;
//     }
// };

// 也是水塘抽样, 这里用count来表示抽与不抽中的基数, 因为题目只在 == target的元素里面抽

// 然而最新的leetcode里面水塘抽样因为时间复杂度太高而过不了了

class Solution {
private:
    vector<int> nums;
    unordered_map<int, vector<int>> rec;

public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            rec[nums[i]].emplace_back(i);
        }
        srand((unsigned)time(0));
    }
    
    int pick(int target) {
        int size = this->rec[target].size();
        int idx = rand() % size;
        return this->rec[target][idx];
    }
};

// 只能直接哈希表暴力了


// 398-随机数索引