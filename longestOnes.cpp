/*
给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。

返回仅包含 1 的最长（连续）子数组的长度。

 

示例 1：

输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释： 
[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。
示例 2：

输入：A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。
 

提示：

1 <= A.length <= 20000
0 <= K <= A.length
A[i] 为 0 或 1 
通过次数23,208提交次数40,417

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-consecutive-ones-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;    

int longestOnes(vector<int>& A, int K) 
{
    int left = 0, right = 0, n = A.size(), cnt = 0;
    int maxn = 0;
    while(right < n)
    {
        if(A[right] == 0)
        {
            cnt++;
        }
        right++;

        while(cnt > K)
        {
            if(A[left] == 0)
            {
                cnt --;
            }
            left++;
        }
        maxn = max(maxn, right - left);
    }
    return maxn;
}

// 模板题