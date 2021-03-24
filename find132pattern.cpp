/*
给定一个整数序列：a1, a2, ..., an，一个132模式的子序列 ai, aj, ak 被定义为：当 i < j < k 时，ai < ak < aj。设计一个算法，当给定有 n 个数字的序列时，验证这个序列中是否含有132模式的子序列。

注意：n 的值小于15000。

示例1:

输入: [1, 2, 3, 4]

输出: False

解释: 序列中不存在132模式的子序列。
示例 2:

输入: [3, 1, 4, 2]

输出: True

解释: 序列中有 1 个132模式的子序列： [1, 4, 2].
示例 3:

输入: [-1, 3, 2, 0]

输出: True

解释: 序列中有 3 个132模式的的子序列: [-1, 3, 2], [-1, 3, 0] 和 [-1, 2, 0].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/132-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <set>
using namespace std;

bool find132pattern(vector<int>& nums) 
{
    int n = nums.size();
    if(n < 3)
    {
        return false;
    }
    int left_min = nums[0];//一个三元组中的最小元素
    multiset<int> right;
    for(int k = 2; k < n ; k ++)
    {
        right.insert(nums[k]);// 保存所有的第3个元素，即k; 所以会从第3个元素开始考虑
    }
    for(int j = 1; j < n - 1; j++) // 考虑所有第2个元素，因此是从第2个到第n - 1个开始
    {
        if(left_min < nums[j]) // nums[i] < nums[j]
        {
            auto it = right.upper_bound(left_min); // nums[i] < nums[k];
            if(it != right.end() && *it < nums[j]) //nums[k] < nums[j];
            {
                return true;
            }
        }
        left_min = min(left_min, nums[j]); // 更新leftmin，因为要找到最小的，因此希望尽可能满足条件
        right.erase(right.find(nums[j + 1])); // 要考虑下一个nums[j]了，那下一个元素必然不会是nums[k]，因此就删掉
    }
    return false;
}