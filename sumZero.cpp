/*
给你一个整数 n，请你返回 任意 一个由 n 个 各不相同 的整数组成的数组，并且这 n 个数相加和为 0 。

 

示例 1：

输入：n = 5
输出：[-7,-1,1,3,4]
解释：这些数组也是正确的 [-5,-1,1,2,3]，[-3,-1,2,-2,4]。
示例 2：

输入：n = 3
输出：[-1,0,1]
示例 3：

输入：n = 1
输出：[0]
 

提示：

1 <= n <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-n-unique-integers-sum-up-to-zero
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;
vector<int> sumZero(int n) 
{
    vector<int> res;
    for(int i = 1; i < n / 2 + 1; i++)
    {
        res.push_back(i);
        res.push_back(-i);
    }
    if(n % 2)
    {
        res.push_back(0);
    }
    return res;
    
}

/*

vector<int> sumZero(int n) {
        vector<int> ans;
        int sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            ans.push_back(i);
            sum += i;
        }
        ans.push_back(-sum);
        return ans;
    }

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/find-n-unique-integers-sum-up-to-zero/solution/he-wei-ling-de-nge-wei-yi-zheng-shu-by-leetcode-so/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/