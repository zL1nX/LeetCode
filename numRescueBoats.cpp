/*
第 i 个人的体重为 people[i]，每艘船可以承载的最大重量为 limit。

每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit。

返回载到每一个人所需的最小船数。(保证每个人都能被船载)。

 

示例 1：

输入：people = [1,2], limit = 3
输出：1
解释：1 艘船载 (1, 2)
示例 2：

输入：people = [3,2,2,1], limit = 3
输出：3
解释：3 艘船分别载 (1, 2), (2) 和 (3)
示例 3：

输入：people = [3,5,3,4], limit = 5
输出：4
解释：4 艘船分别载 (3), (3), (4), (5)
提示：

1 <= people.length <= 50000
1 <= people[i] <= limit <= 30000
通过次数22,989提交次数45,554


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/boats-to-save-people
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) 
{
    sort(people.begin(), people.end());
    int light = 0, heavy = people.size() - 1, boats = 0;
    while(light <= heavy)
    {
        if(people[light] + people[heavy] > limit)
        {
            heavy--; // 最重的那个人不能坐，只能单独一艘船
        }
        else // 两个人可以做坐一艘，尽可能利用船的重量
        {
            light ++;
            heavy --;
        }
        boats ++;
    }
    return boats;
}

// 排序肯定是必需的，但要注意到题目要求一艘船只能坐两个人，因此要充分利用船的重量，只能先轻的和重的一起

// 在写的时候用双指针来写即可，面试可能会做这种。

// 越重的人，越容易自己独占一条船。如果想尽可能地利用空间，就尽可能往它们上面塞人。