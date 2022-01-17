/*
给定两个以升序排列的整数数组 nums1 和 nums2 , 以及一个整数 k 。

定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。

请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。

 

示例 1:

输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
输出: [1,2],[1,4],[1,6]
解释: 返回序列中的前 3 对数：
     [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
示例 2:

输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
输出: [1,1],[1,1]
解释: 返回序列中的前 2 对数：
     [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
示例 3:

输入: nums1 = [1,2], nums2 = [3], k = 3 
输出: [1,3],[2,3]
解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]
 

提示:

1 <= nums1.length, nums2.length <= 104
-109 <= nums1[i], nums2[i] <= 109
nums1, nums2 均为升序排列
1 <= k <= 1000
通过次数25,651提交次数62,373

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
{
    auto cmp = [&](pair<int, int>& a, pair<int, int>& b)
    {
        return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    int m = nums1.size(), n = nums2.size();
    for(int i = 0; i < min(k ,m); i++) // 先以x为准，把所有的x都跑一遍加进去
    {
        pq.push(make_pair(i, 0));
    }
    vector<vector<int>> res;
    while(k-- && !pq.empty())
    {
        auto [x, y] = pq.top();
        pq.pop();
        res.push_back({nums1[x], nums2[y]});
        if(y + 1 < n) // 因为x y是当前最小的，那么有理由相信，y往下加的那个对可能也是结果里的
        { // 不加x是因为我们提前已经加过了
            pq.push(make_pair(x, y + 1)); 
        }
    }
    return res;
}

// 这种题一眼过去就是要用优先队列，只不过暴力的放到优先队列里面肯定会超时的

// 这里用的方法是，先放那些肯定算是比较小的对，比如 0, 0; 1, 0; 2, 0; ...; k - 1, 0

// 之后呢，对于0的那些加1即可；因为原数组时升序排列的，所以必然坐标下一个1的就也可能是更加小的