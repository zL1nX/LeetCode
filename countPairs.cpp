/*
大餐 是指 恰好包含两道不同餐品 的一餐，其美味程度之和等于 2 的幂。

你可以搭配 任意 两道餐品做一顿大餐。

给你一个整数数组 deliciousness ，其中 deliciousness[i] 是第 i​​​​​​​​​​​​​​ 道餐品的美味程度，返回你可以用数组中的餐品做出的不同 大餐 的数量。结果需要对 109 + 7 取余。

注意，只要餐品下标不同，就可以认为是不同的餐品，即便它们的美味程度相同。

 

示例 1：

输入：deliciousness = [1,3,5,7,9]
输出：4
解释：大餐的美味程度组合为 (1,3) 、(1,7) 、(3,5) 和 (7,9) 。
它们各自的美味程度之和分别为 4 、8 、8 和 16 ，都是 2 的幂。
示例 2：

输入：deliciousness = [1,1,1,3,3,3,7]
输出：15
解释：大餐的美味程度组合为 3 种 (1,1) ，9 种 (1,3) ，和 3 种 (1,7) 。
 

提示：

1 <= deliciousness.length <= 105
0 <= deliciousness[i] <= 220

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-good-meals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int countPairs(vector<int>& deliciousness) 
{
    int maxValue = *max_element(deliciousness.begin(), deliciousness.end());
    int upperBound = maxValue * 2; // 当前数组中大餐的理论上界值
    unordered_map<int, int> rec;
    int res = 0;
    for(int& meal : deliciousness) // 外层是meal，因为要看对于某一顿饭而言，有多少种搭配
    {
        for(int sum = 1; sum <= upperBound; sum <<= 1) // make sure it is the power of 2
        {   
            res = (res + rec[sum - meal]) % 1000000007;
        }
        rec[meal] ++;
    }
    return res;
}

// 基本思路其实有点像 几数之和，即正难则反；正着看和是否为2的幂，不如先把2的幂算出来

// 然后用哈希表查看差值是否出现过

// 那个求理论最大上界，属实一哈没想到要这么写