
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });
        int n = envelopes.size();
        // 麻了 N2的dp解决LIS已经超时了，需要用NlogN的二分查找解决LIS, 或者对dp的写法做一些优化，比如用pair或者其他api
        /*
        int res = 1;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(envelopes[j][1] < envelopes[i][1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        */
        vector<int> top(n, 0); // 用来指示每个牌堆的顶部放谁，只有当前牌比牌堆顶部的牌小才能放这个堆
        int piles = 0; // 蜘蛛纸牌摆扑克牌，扑克牌的堆数就是LIS的长度
        for(int i = 0; i < n; i++)
        {
            int left = 0, right = piles, curr = envelopes[i][1];
            while(left < right)
            {
                int mid = left + (right - left) / 2;
                if(top[mid] < curr)
                {
                    left = mid + 1;
                }
                else // 没有 == 的处理操作，表示left放的是最左边的牌堆
                {
                    right = mid;
                }
            }
            if(left == piles)
            {
                piles++;
            }
            top[left] = curr; // 这里注意是left而不是piles，因为piles是一个counter，而left是索引，所以根据二分的结果
            // 一定是放在left那个地方的，即使是要新建一个堆，那么也是piles这个counter++，而left本身已经指向了counter之前那个值了
        }
        return piles; // 牌堆的数量即为LIS的长度，这个方法学术点叫耐心排序
    }
};

// 354. 俄罗斯套娃信封问题

// 先按照一边升序排序，再按照另一边降序排序，降序排序那一边的值的最长递增子序列即为信封结果
