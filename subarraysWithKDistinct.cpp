/*
给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。

（例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）

返回 A 中好子数组的数目。

 

示例 1：

输入：A = [1,2,1,2,3], K = 2
输出：7
解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
示例 2：

输入：A = [1,2,1,3,4], K = 3
输出：3
解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
 

提示：

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarrays-with-k-different-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;

int subarraysWithMostNDistinct(vector<int>& A, int K)
{
    int left = 0, right = 0, distinct = 0, cnt = 0;
    unordered_map<int,int> appeared;
    while(right < A.size())
    {
        if(appeared[A[right]] == 0)
        {
            distinct ++;
        }
        appeared[A[right]]++;
        while(distinct > K)
        {
            appeared[A[left]]--;
            if(appeared[A[left]] == 0)
            {
                distinct --;
            }
            left++;
        }
        cnt += right - left + 1;
        right++;
    }
    return cnt;
}

int subarraysWithKDistinct(vector<int>& A, int K) 
{
    return subarraysWithMostNDistinct(A, K) - subarraysWithMostNDistinct(A, K - 1); // smart
}

// 注意使用模板
// https://leetcode-cn.com/problems/subarrays-with-k-different-integers/solution/cong-zui-jian-dan-de-wen-ti-yi-bu-bu-tuo-7f4v/