/*
在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。

现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足满足：

 nums1[i] == nums2[j]
且绘制的直线不与任何其他连线（非水平线）相交。
请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。

以这种方法绘制线条，并返回可以绘制的最大连线数。

 

示例 1：


输入：nums1 = [1,4,2], nums2 = [1,2,4]
输出：2
解释：可以画出两条不交叉的线，如上图所示。 
但无法画出第三条不相交的直线，因为从 nums1[1]=4 到 nums2[2]=4 的直线将与从 nums1[2]=2 到 nums2[1]=2 的直线相交。
示例 2：

输入：nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
输出：3
示例 3：

输入：nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
输出：2
 

提示：

1 <= nums1.length <= 500
1 <= nums2.length <= 500
1 <= nums1[i], nums2[i] <= 2000
 

通过次数10,557提交次数17,717

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/uncrossed-lines
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/  

#include <vector>
using namespace std;

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
{
    int m = nums1.size() , n = nums2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= m; i ++)
    {
        int n1 = nums1[i - 1];
        for(int j = 1; j <= n; j++)
        {
            int n2 = nums2[j - 1];
            if(n1 == n2)
            {
                dp[i][j] = dp[i - 1][j - 1] + 1; // 遇见了公共元素就直接+1
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 不相等的话，看看上下的最长公共子序列结果谁大
            }
            // 时刻设想一个二维矩阵的样子
        }
    }
    return dp[m][n];
}

// 这题的思路神了

// 元素之间的线不相交，意味着元素之间的相对顺序保持一致，同时元素还互相相同

// 那么实际上就是求两数组的最长公共子序列问题

// 然后动态规划就开始了