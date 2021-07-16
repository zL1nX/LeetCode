/*
统计一个数字在排序数组中出现的次数。

 

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
 

限制：

0 <= 数组长度 <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int search(vector<int>& nums, int target) 
{
    int cnt = 0, n = nums.size(), id = 0;
    if(n == 0) return 0;
    for(; id < n && nums[id] != target; id++) {
    }
    while(id < n && nums[id] == target)
    {
        cnt++;
        id++;
    }
    return cnt;
}

// 谁都知道这题是让你写二分搜索边界来着，但我就是想看看lc后台测试样例行不行

// 好像不太行，这直接搜都能80%的胜出

// 二分的话无非就是搜到id在哪，然后同样用一个循环来搞