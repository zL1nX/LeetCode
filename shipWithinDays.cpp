/*
传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。

传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。

返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。

 

示例 1：

输入：weights = [1,2,3,4,5,6,7,8,9,10], D = 5
输出：15
解释：
船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
第 1 天：1, 2, 3, 4, 5
第 2 天：6, 7
第 3 天：8
第 4 天：9
第 5 天：10

请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成 (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) 是不允许的。 
示例 2：

输入：weights = [3,2,2,4,1,4], D = 3
输出：6
解释：
船舶最低载重 6 就能够在 3 天内送达所有包裹，如下所示：
第 1 天：3, 2
第 2 天：2, 4
第 3 天：1, 4
示例 3：

输入：weights = [1,2,3,1,1], D = 4
输出：3
解释：
第 1 天：1
第 2 天：2
第 3 天：3
第 4 天：1, 1
 

提示：

1 <= D <= weights.length <= 50000
1 <= weights[i] <= 500

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <numeric>
using namespace std;

int shipWithinDays(vector<int>& weights, int D) 
{
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    // 使用二分查找，查找谁？查找最终的结果，即每日最低载重
    // 那么左边界肯定就是weights中最大的那单个元素
    // 那么右边界就是整个数组的重量累加

    while(left < right) // 选取左闭右开式的二分
    {
        int mid = left + (right - left) / 2;
        int days = 1, carried = 0;
        for(int weight : weights) // 模拟载重过程
        {
            if(carried + weight > mid) // 一旦当前载重超过了目前这个界定值
            {
                days += 1; // 就需要再来一天
                carried = 0;
            }
            carried += weight; // 实际的累加操作
        }
        // 最终会输出一个当前mid载重时，需要days的大小
        if(days <= D)
        {
            right = mid; // 开区间取法
        }
        else
        {
            left = mid + 1; // 闭区间取法
        }
    }
    return left;

}
// 这道题有趣的一点是 虽然是有序数组，而且也用了二分查找，但实际上这和原来所说的「二分需要有序」
// 并不是一个概念，本题的二分需要有序是建立在max_element到accumulate之间的有序
// 但这个题这种做法的思路真的挺有意思，用二分去直接查到对应值