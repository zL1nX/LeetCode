/*
给定两个数组，编写一个函数来计算它们的交集。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
 

说明：

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。

*/

#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
    unordered_map<int, int> map1, map2;
    vector<int> inter;
    if(!nums1.size() || !nums2.size())
    {
        return inter;
    }
    for(int i : nums1)
    {
        map1[i] ++;
    }
    for(int i : nums2)
    {
        map2[i] ++;
    }
    for(auto it : map1)
    {
        if(map2[it.first])
        {
            inter.push_back(it.first);
        }
    }
    return inter;
}

/*
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }

*/