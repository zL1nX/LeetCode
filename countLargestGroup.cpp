/*
给你一个整数 n 。请你先求出从 1 到 n 的每个整数 10 进制表示下的数位和（每一位上的数字相加），然后把数位和相等的数字放到同一个组中。

请你统计每个组中的数字数目，并返回数字数目并列最多的组有多少个。

 

示例 1：

输入：n = 13
输出：4
解释：总共有 9 个组，将 1 到 13 按数位求和后这些组分别是：
[1,10]，[2,11]，[3,12]，[4,13]，[5]，[6]，[7]，[8]，[9]。总共有 4 个组拥有的数字并列最多。
示例 2：

输入：n = 2
输出：2
解释：总共有 2 个大小为 1 的组 [1]，[2]。
示例 3：

输入：n = 15
输出：6
示例 4：

输入：n = 24
输出：5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-largest-group
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <unordered_map>
#include <vector>
using namespace std;
int digit_sum(int n)
{
    int sum = 0;
    while(n)
    {
        int digit = n % 10;
        sum += digit;
        n /= 10;
    }
    return sum;
}
int countLargestGroup(int n) 
{
    unordered_map<int, vector<int>> times;
    unordered_map<int, int> sizes;
    for(int i = 1; i <= n; i++)
    {
        times[digit_sum(i)].push_back(i);
    }
    for(auto it : times)
    {
        sizes[it.second.size()]++;
    }

    int max = -1;
    for(auto it : sizes)
    {
        if(it.first > max)
            max = it.first;
    }
    return sizes[max];
}

/*


class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> hashMap;
        int maxValue = 0;
        for (int i = 1; i <= n; ++i) {
            int key = 0, i0 = i;
            while (i0) {
                key += i0 % 10;
                i0 /= 10;
            }
            ++hashMap[key];
            maxValue = max(maxValue, hashMap[key]);
        }
        int count = 0;
        for (auto& kvpair: hashMap) {
            if (kvpair.second == maxValue) {
                ++count;
            }
        }
        return count;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/count-largest-group/solution/tong-ji-zui-da-zu-de-shu-mu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/