/*
给你一个整数数组 arr，请你判断数组中是否存在连续三个元素都是奇数的情况：如果存在，请返回 true ；否则，返回 false 。

 

示例 1：

输入：arr = [2,6,4,1]
输出：false
解释：不存在连续三个元素都是奇数的情况。
示例 2：

输入：arr = [1,2,34,3,4,5,7,23,12]
输出：true
解释：存在连续三个元素都是奇数的情况，即 [5,7,23] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/three-consecutive-odds
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;
bool threeConsecutiveOdds(vector<int>& arr) 
{
    if(arr.size() < 3)
    {
        return false;
    }
    for(int i = 0; i <= arr.size() - 3; i ++) // remember the "<=" not "<"
    {
        int sum = 0;
        for(int j = i; j < i + 3; j ++)
        {
            sum += arr[j] % 2;
        }
        if(sum == 3)
            return true;
    }
    return false;
}