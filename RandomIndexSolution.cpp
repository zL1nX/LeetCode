/*
给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。

注意：
数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。

示例:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
solution.pick(3);

// pick(1) 应该返回 0。因为只有nums[0]等于1。
solution.pick(1);

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/random-pick-index
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <random>
using namespace std;


class RandomIndexSolution {
private:
    vector<int> res;
public:
    RandomIndexSolution(vector<int>& nums) {
        res = nums;
    }
    
    int pick(int target) {
        int loc = 0;
        for(int i = 0, cnt = 0; i < res.size(); i++)
        {
            if(res[i] == target)
            {
                cnt ++; // 第几次遇到这个target
                if(rand() % cnt == 0) // 从 0,i中抽取一个值, 如果刚好是i, 那就把i作为索引
                {
                    loc = i;
                }
            }
        }
        return loc;
    }
};

// 最直白的暴力解法无非就是直接用哈希表, 然后随机算一个index

// 但对于元素的占地太大, 不能load到哈希表里的情况, 需要有一种根据当前时刻和后续时刻的下标抽取

// 这个写法就是标准的水池抽样, 具体为什么可以做到等概率, 大致就是某次选中 其余不选中的一个概率累乘

// 这个题目本质上是从无限长的序列中随机选取元素, 核心的点就要记住这个水池抽样即可