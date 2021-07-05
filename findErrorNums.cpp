/*
集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且 有一个数字重复 。

给定一个数组 nums 代表了集合 S 发生错误后的结果。

请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。

 

示例 1：

输入：nums = [1,2,2,4]
输出：[2,3]
示例 2：

输入：nums = [1,1]
输出：[1,2]
 

提示：

2 <= nums.length <= 104
1 <= nums[i] <= 104
通过次数41,728提交次数98,277


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/set-mismatch
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <set>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) 
{
    int n = nums.size(), s = (1 + n) * n / 2;
    int all_all = 0, all_set = 0;
    set<int> re(nums.begin(), nums.end());
    for(int n : nums){
        all_all += n;
    }
    for(int n : re)
    {
        all_set += n;
    }
    return {all_all - all_set, s - all_set};
}

// 使用set这个空间来去重，然后根据1到N这个特点进行数学上的简单推导，就知道谁重复以及缺了谁了