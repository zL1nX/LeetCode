/*

给你个整数数组 arr，其中每个元素都 不相同。

请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。

 

示例 1：

输入：arr = [4,2,1,3]
输出：[[1,2],[2,3],[3,4]]
示例 2：

输入：arr = [1,3,6,10,15]
输出：[[1,3]]
示例 3：

输入：arr = [3,8,-10,23,19,-4,-14,27]
输出：[[-14,-10],[19,23],[23,27]]
 

提示：

2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-absolute-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <vector>
#include <map>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    int min_diff = INT_MAX;
    for(int i = 1; i < arr.size(); i ++)
    {
        if(arr[i] - arr[i - 1] < min_diff)
        {
            res.clear();
            res.push_back({arr[i], arr[i - 1]});
            min_diff = arr[i - 1] - arr[i];
        }
        else if(arr[i] - arr[i - 1] == min_diff)
        {
            res.push_back({arr[i], arr[i - 1]});
        }
    }
    return res;

}

// 注意排序后如果是最小绝对差的，那么必然是连续的