/*
在整数数组中，如果一个整数的出现频次和它的数值大小相等，我们就称这个整数为「幸运数」。

给你一个整数数组 arr，请你从中找出并返回一个幸运数。

如果数组中存在多个幸运数，只需返回 最大 的那个。
如果数组中不含幸运数，则返回 -1 。
 

示例 1：

输入：arr = [2,2,3,4]
输出：2
解释：数组中唯一的幸运数是 2 ，因为数值 2 的出现频次也是 2 。
示例 2：

输入：arr = [1,2,2,3,3,3]
输出：3
解释：1、2 以及 3 都是幸运数，只需要返回其中最大的 3 。
示例 3：

输入：arr = [2,2,2,3,3]
输出：-1
解释：数组中不存在幸运数。
示例 4：

输入：arr = [5]
输出：-1
示例 5：

输入：arr = [7,7,7,7,7,7,7]
输出：7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-lucky-integer-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <map>
using namespace std;
int findLucky(vector<int>& arr) 
{
    vector<int> lucky;
    map<int, int> times;
    for(int i = 0; i < arr.size(); i ++)
    {
        times.insert(pair(arr[i], count(arr.begin(), arr.end(), arr[i])));
    }
    for(auto it : times)
    {
        if(it.first == it.second)
            lucky.push_back(it.first);
    }
    if(lucky.size())
        return *max_element(lucky.begin(), lucky.end());
    else
        return -1;
    
}

/*

unordered_map <int, int> m;
    int findLucky(vector<int>& arr) {
        for (auto x: arr) ++m[x];
        int ans = -1;
        for (auto [key, value]: m) {
            if (key == value) {
                ans = max(ans, key);
            }
        }
        return ans;
    }

*/