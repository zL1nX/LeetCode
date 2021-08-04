/*
给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。

示例 1:

输入: [2,2,3,4]
输出: 3
解释:
有效的组合是: 
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3
注意:

数组长度不超过1000。
数组里整数的范围为 [0, 1000]。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-triangle-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int triangleNumber(vector<int>& nums) 
{
    int n = nums.size(), sum = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int left = j + 1, right = n, mid, k = j; // 令k=j是可以，当有一条边为0时，二分查找会失败（因为所有边都大于j），因此就算找不到k，那么k-j还是0
            while(left < right)
            {
                mid = left + (right - left) / 2;
                if(nums[mid] < nums[i] + nums[j])
                {
                    left = mid + 1;
                    k = mid;
                }
                else
                {
                    right = mid;
                }
            }
            sum += k - 1 - j + 1;
        }
    }
    return sum;
}

// 肯定是要先排序的，这样就只用看最小的两条边之和了

// 排完序之后还要看后面有多少边满足小于前两条边之和，那么本质其实就是一个查找问题

// 因此可以使用二分找到最后一个小于两边之和的地方，然后看下长度即可

// 排序后如何看有多少边，这点思路需要突破