/*
给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

 

 

示例 1：

输入：[3,2,3]
输出：[3]
示例 2：

输入：nums = [1]
输出：[1]
示例 3：

输入：[1,1,1,3,3,2,2,2]
输出：[1,2]
 

提示：

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 

进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;

vector<int> majorityElement(vector<int>& nums) 
{
    unordered_map<int,int> rec;
    int hold = nums.size() / 3;
    vector<int> result;
    for(int& num : nums)
    {
        rec[num]++;
    }
    for(auto it : rec)
    {
        if(it.second > hold)
        {
            result.push_back(it.first);
        }
    }
    return result;
}

// 其实有好几种做法，直接map感觉最现实，当然还有排序 + 双指针，但其时间复杂度就要稍高

// 当然满足最高要求的就是摩尔投票法，这种方法的本质是想说，超过1/2个的元素在一个数组中最多只有1个，那么同理 1/3 最多只有两个

// 但这种方法写起来太笨重了说实话，虽然思路很奇特（x

// 但根据众数的标准去反推众数最多的个数是值得学习的，下面贴个代码

/*
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int element1 = 0;
        int element2 = 0;
        int vote1 = 0;
        int vote2 = 0;

        for (auto & num : nums) {
            if (vote1 > 0 && num == element1) { //如果该元素为第一个元素，则计数加1
                vote1++;
            } else if (vote2 > 0 && num == element2) { //如果该元素为第二个元素，则计数加1
                vote2++;
            } else if (vote1 == 0) { // 选择第一个元素
                element1 = num;
                vote1++;
            } else if (vote2 == 0) { // 选择第二个元素
                element2 = num;
                vote2++;
            } else { //如果三个元素均不相同，则相互抵消1次
                vote1--;
                vote2--;
            }
        }

        int cnt1 = 0;
        int cnt2 = 0;
        for (auto & num : nums) {
            if (vote1 > 0 && num == element1) {
                cnt1++;
            }
            if (vote2 > 0 && num == element2) {
                cnt2++;
            }
        }
        // 检测元素出现的次数是否满足要求
        if (vote1 > 0 && cnt1 > nums.size() / 3) {
            ans.push_back(element1);
        }
        if (vote2 > 0 && cnt2 > nums.size() / 3) {
            ans.push_back(element2);
        }

        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/majority-element-ii/solution/qiu-zhong-shu-ii-by-leetcode-solution-y1rn/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/