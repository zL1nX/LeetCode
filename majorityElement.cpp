/*
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1：

输入：[3,2,3]
输出：3
示例 2：

输入：[2,2,1,1,1,2,2]
输出：2


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) 
{   
    unordered_map<int, int> times;
    int hold = nums.size() / 2 + 1;
    for(int i = 0; i < nums.size(); i ++)
    {
        times[nums[i]]++;
    }
    for(auto it : times)
    {
        if(it.second >= hold)
        {
            return it.first;
        }
    }
    return 0;

}

/*
public int majorityElement(int[] nums) {
		int count = 1;
		int maj = nums[0];
		for (int i = 1; i < nums.length; i++) {
			if (maj == nums[i])
				count++;
			else {
				count--;
				if (count == 0) {
					maj = nums[i + 1];
				}
			}
		}
		return maj;
	}
摩尔投票法

*/