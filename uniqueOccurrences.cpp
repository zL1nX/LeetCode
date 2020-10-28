/*
给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。

如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。

 

示例 1：

输入：arr = [1,2,2,1,1,3]
输出：true
解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。
示例 2：

输入：arr = [1,2]
输出：false
示例 3：

输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
输出：true
*/

#include <vector>
#include <unordered_map>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) 
{
    unordered_map<int, int> times;
    vector<int> cnt;
    for(int i : arr)
    {
        times[i]++;
    }
    for(auto i : times)
    {
        cnt.push_back(i.second);
    }
    for(int i : cnt)
    {
        if(count(cnt.begin(), cnt.end(), i) > 1)
        {
            return false;
        }
    }
    return true;
}

/*


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occur;
        for (const auto& x: arr) {
            occur[x]++;
        }
        unordered_set<int> times;
        for (const auto& x: occur) {
            times.insert(x.second);
        }
        return times.size() == occur.size();
    }
};

*/