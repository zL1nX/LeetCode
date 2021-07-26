/*
给你一个数组 target ，包含若干 互不相同 的整数，以及另一个整数数组 arr ，arr 可能 包含重复元素。

每一次操作中，你可以在 arr 的任意位置插入任一整数。比方说，如果 arr = [1,4,1,2] ，那么你可以在中间添加 3 得到 [1,4,3,1,2] 。你可以在数组最开始或最后面添加整数。

请你返回 最少 操作次数，使得 target 成为 arr 的一个子序列。

一个数组的 子序列 指的是删除原数组的某些元素（可能一个元素都不删除），同时不改变其余元素的相对顺序得到的数组。比方说，[2,7,4] 是 [4,2,3,7,2,1,4] 的子序列（加粗元素），但 [2,4,2] 不是子序列。

 

示例 1：

输入：target = [5,1,3], arr = [9,4,2,3,4]
输出：2
解释：你可以添加 5 和 1 ，使得 arr 变为 [5,9,4,1,2,3,4] ，target 为 arr 的子序列。
示例 2：

输入：target = [6,4,8,1,3,2], arr = [4,7,6,2,3,8,6,1]
输出：3
 

提示：

1 <= target.length, arr.length <= 105
1 <= target[i], arr[i] <= 109
target 不包含任何重复元素。
通过次数2,720提交次数5,546

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int minOperations(vector<int>& target, vector<int>& arr) 
{
    int n = target.size();
    unordered_map<int, int> pos;
    for(int i = 0; i < n; i++)
    {
        pos[target[i]] = i; // like 0, 1, 2, 3, 4, 5
    }
    vector<int> rising;
    for(int& num : arr)
    {
        if(pos.find(num) != pos.end())
        {
            int idx = pos[num]; // actual value or target
            auto loc = lower_bound(rising.begin(), rising.end(), idx);
            if(loc != rising.end())
            {
                *loc = idx;
            }
            else
            {
                rising.push_back(idx);
            }  
        }
    }
    return n - rising.size();

}

// 妙啊这题的题解思路：因为反正要让target变成arr的子序列，那本质上就是，先看target与arr的最长子序列是啥

// 然后操作次数就是看这个最长子序列还差target长度有多少，有多少补多少不就完了

// 所以可先转化为求二者的最长公共子序列

// 然后一般的解法时间复杂度不和要求，这里作了一个很妙的转化：求坐标值的最长公共子序列

// 而target对于自己的坐标就是严格递增的，同时没有重复元素，这就说明坐标没有重复元素

// 因此arr求出的递增子序列长度一定小于等于target的长度（因为一旦超过，说明有重复元素，则矛盾）

// 因此问题又转化成了求arr对应target坐标的递增子序列（真滴秀）

// 这种就可以用二分+贪心来求，即每次让队尾最小，一旦前面有大的就进行替换
