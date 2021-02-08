/*
当 A 的子数组 A[i], A[i+1], ..., A[j] 满足下列条件时，我们称其为湍流子数组：

若 i <= k < j，当 k 为奇数时， A[k] > A[k+1]，且当 k 为偶数时，A[k] < A[k+1]；
或 若 i <= k < j，当 k 为偶数时，A[k] > A[k+1] ，且当 k 为奇数时， A[k] < A[k+1]。
也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。

返回 A 的最大湍流子数组的长度。

 

示例 1：

输入：[9,4,2,10,7,8,8,1,9]
输出：5
解释：(A[1] > A[2] < A[3] > A[4] < A[5])
示例 2：

输入：[4,8,12,16]
输出：2
示例 3：

输入：[100]
输出：1
 

提示：

1 <= A.length <= 40000
0 <= A[i] <= 10^9


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-turbulent-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int maxTurbulenceSize(vector<int>& arr) 
{
    int left = 0, right = 0;
    int length = 1;
    while(right < arr.size() - 1)
    {
        if(left == right)
        {
            if(arr[left] != arr[left + 1])
            {
                left++;
            }
            right++;
        }
        else
        {
            if(arr[right] > arr[right - 1] && arr[right] > arr[right + 1])
            {
                right++;
            }
            else if(arr[right] < arr[right - 1] && arr[right] < arr[right + 1])
            {
                right++;
            }
            else
            {
                left = right;
            }
        }
    }
    length = max(length, right - left + 1);
    return length;
}