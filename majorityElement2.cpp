/*
数组中占比超过一半的元素称之为主要元素。给你一个 整数 数组，找出其中的主要元素。若没有，返回 -1 。请设计时间复杂度为 O(N) 、空间复杂度为 O(1) 的解决方案。

 

示例 1：

输入：[1,2,5,9,5,9,5,5,5]
输出：5
示例 2：

输入：[3,2]
输出：-1
示例 3：

输入：[2,2,1,1,1,2,2]
输出：2
通过次数54,136提交次数95,998

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-majority-element-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) 
{   
    int n = nums.size(), candidate = -1;
    int count = 0;
    for(int& num : nums)
    {
        if(count == 0)
        {
            candidate = num;
            count = 1;
        }
        else
        {
            /* code */
            count += candidate == num ? 1 : -1;
        }
    }
    count = 0;
    for(int& num : nums)
    {
        count += candidate == num ? 1 : 0;
    }
    return count > n / 2 ? candidate : -1;
}

// boyer Moore投票法，非常妙啊

// 因为既然是主要元素，那么只有主要元素这么抵消之后，才能剩下1来

// 因为第一个循环最后得到的candidate就是可能的主要元素（因为一旦是主要元素，count就不会为0了，也就不会更新了）

    // 有可能就是大家全为0，或者就没有主要元素，那这就取决于剩下元素的次数了

// 第二个循环来确认下candidate究竟是不是主要元素