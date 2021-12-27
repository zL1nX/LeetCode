/*
在社交媒体网站上有 n 个用户。给你一个整数数组 ages ，其中 ages[i] 是第 i 个用户的年龄。

如果下述任意一个条件为真，那么用户 x 将不会向用户 y（x != y）发送好友请求：

age[y] <= 0.5 * age[x] + 7
age[y] > age[x]
age[y] > 100 && age[x] < 100
否则，x 将会向 y 发送一条好友请求。

注意，如果 x 向 y 发送一条好友请求，y 不必也向 x 发送一条好友请求。另外，用户不会向自己发送好友请求。

返回在该社交媒体网站上产生的好友请求总数。

 

示例 1：

输入：ages = [16,16]
输出：2
解释：2 人互发好友请求。
示例 2：

输入：ages = [16,17,18]
输出：2
解释：产生的好友请求为 17 -> 16 ，18 -> 17 。
示例 3：

输入：ages = [20,30,100,110,120]
输出：3
解释：产生的好友请求为 110 -> 100 ，120 -> 110 ，120 -> 100 。
 

提示：

n == ages.length
1 <= n <= 2 * 104
1 <= ages[i] <= 120
通过次数17,253提交次数39,121

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/friends-of-appropriate-ages
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int numFriendRequests(vector<int>& ages) 
{
    int res = 0;
    sort(ages.begin(), ages.end()); // 先排序再说
    int left = 0, right = 0, n = ages.size();
    for(int age : ages)
    {
        if(age < 15)
        {
            continue;
        }
        while(ages[left] <= 0.5 * age + 7) // 凡是小于等于的均不行，收缩边界
        {
            left++;
        }
        while(right + 1 < n && ages[right + 1] <= age) // 凡是下一个元素大于age了，就不行了，扩展边界
        {
            // 下一个元素不行了，说明当前right这个元素是满足条件的最右边的
            right++;
        }
        res += right - left; // 
    }  
    return res;
}

// 本来想暴力来着，结果发现没人这么做（说明暴力铁超时）

// 然后题解用了 排序 + 双指针的方法，而要用这个方法需要对题目中的原条件进行转换和归纳

// 原题中条件2如果不满足，那么条件3一定不满足，再加上条件一的限制，对于一个x，相当于有 (0.5x + 7, x]这个区间内的值都满足

// 注意，当x小于等于14时是不满足的，因为两个端点相交了

// 那么，对原数组排序之后，依次扫描每个x，用left与right两个指针出搜索出当前x对应的一个合适的区间，然后累加即可