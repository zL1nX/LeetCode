/*
这里有 n 个航班，它们分别从 1 到 n 进行编号。

有一份航班预订表 bookings ，表中第 i 条预订记录 bookings[i] = [firsti, lasti, seatsi] 意味着在从 firsti 到 lasti （包含 firsti 和 lasti ）的 每个航班 上预订了 seatsi 个座位。

请你返回一个长度为 n 的数组 answer，其中 answer[i] 是航班 i 上预订的座位总数。

 

示例 1：

输入：bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
输出：[10,55,45,25,25]
解释：
航班编号        1   2   3   4   5
预订记录 1 ：   10  10
预订记录 2 ：       20  20
预订记录 3 ：       25  25  25  25
总座位数：      10  55  45  25  25
因此，answer = [10,55,45,25,25]
示例 2：

输入：bookings = [[1,2,10],[2,2,15]], n = 2
输出：[10,25]
解释：
航班编号        1   2
预订记录 1 ：   10  10
预订记录 2 ：       15
总座位数：      10  25
因此，answer = [10,25]
 

提示：

1 <= n <= 2 * 104
1 <= bookings.length <= 2 * 104
bookings[i].length == 3
1 <= firsti <= lasti <= n
1 <= seatsi <= 104
通过次数33,405提交次数63,602

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/corporate-flight-bookings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

/*vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
{
    vector<int> orders(n);
    for(int i = 0; i < n; i++)
    {
        for(int k = bookings[i][0]; k <= bookings[i][1]; k++)
        {
            orders[k - 1] += bookings[i][2];
        }
    }
    return orders;
}*/

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
{
    vector<int> res(n);
    for(auto& booking : bookings)
    {
        res[booking[0] - 1] += booking[2]; // d[l] += inc
        if(booking[1] < n)
        {
            res[booking[1]] -= booking[2]; // d[r + 1] -= inc
        }
    }
    for(int i = 1; i < n; i++)
    {
        res[i] += res[i - 1];
    }
    return res;
}

// 最开始暴力的写法直接超时了，根本原因在于，如果一个booking覆盖了太长的区间，得手动遍历一遍才能加上去

// 这就造成了是平方级别的复杂度，然而数据之间的差值并没有发生变化

// 因此可用差分数组的思想，即对一段数组的所有元素同时改变某个值，等价于在数组端点进行修改

// 当我们希望对原数组的某一个区间 [l,r] 施加一个增量inc 时，差分数组 d对应的改变是：d[l] 增加 inc，d[r+1] 减少 inc

// 因此初始时原数组实际就是全0数组，每个booking都对其作出改变，最后只要还原出原数组即可

// 注意这种一段区间的修改，都可以考虑用差分数组