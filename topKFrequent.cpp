/*
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

 

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
 

提示：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
你可以按任意顺序返回答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) 
{
    unordered_map<int, int> num_map;
    priority_queue<pair<int, int>> sort_map; // 优先队列，天然排序，其实也可以用于frequencySort那题
    vector<int> res;
    for(int n : nums)
    {
        num_map[n] ++;
    }
    for(auto it : num_map)
    {
        // 优先队列在比较pair时比较pair-first
        sort_map.push(pair<int, int>(-it.second, it.first)); // 按照元素频率的相反数排序，队头是最多的元素，队尾是最少的元素
        if(sort_map.size() > k) // 始终保持一个较小的队列规模
        {
            sort_map.pop();
        }
    }
    while(k --)
    {
        res.push_back(sort_map.top().second); // 优先队列默认情况下top是取队尾（即默认最大）的元素，并不是队头，这一点与queue取队头不一样
        sort_map.pop();
    }
    reverse(res.begin(), res.end()); // 所以要逆序
    return res;
}