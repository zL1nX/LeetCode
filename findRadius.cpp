/*
冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

在加热器的加热半径范围内的每个房屋都可以获得供暖。

现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。

说明：所有供暖器都遵循你的半径标准，加热的半径也一样。

 

示例 1:

输入: houses = [1,2,3], heaters = [2]
输出: 1
解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
示例 2:

输入: houses = [1,2,3,4], heaters = [1,4]
输出: 1
解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
示例 3：

输入：houses = [1,5], heaters = [2]
输出：3
 

提示：

1 <= houses.length, heaters.length <= 3 * 104
1 <= houses[i], heaters[i] <= 109


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/heaters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters) 
{
    int result = 0;
    sort(heaters.begin(), heaters.end());
    for(int house : houses)
    {
        int j = upper_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
        int i = j - 1;
        int rightdis = j >= heaters.size() ? INT_MAX : heaters[j] - house;
        int leftdis = i < 0 ? INT_MAX : house - heaters[i];
        result = max(result, min(rightdis, leftdis));
    }
    return result;
}

// 这个题还是挺抽象的，精髓在于：对于一个house而言，看左右两边的heater谁比较近，这个较近的距离就是对于这个house的最小距离

// 最后的答案是所有最小距离中的最大距离（因为反正一个heater能对应的房屋是无限）

// 那么问题就在于，对于每个house而言，如何找到其最近的左右两边的heater，这个就是用二分去找

// upperbound能找到右边的heater，这个下标j减去1就是左边的heater，所以对于一个heater而言，其最近的距离就是看下j和i哪个近一点

// 当然对于越界的情况，即j太大或者i太小，直接置一个最大值

// 对于最后的结果，取上述过程中的最大值即可

// 据说是华为面试，多做几遍