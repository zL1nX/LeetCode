/*
请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/daily-temperatures
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;


// vector<int> dailyTemperatures(vector<int>& T) 
// {
//     vector<int> res;
//     for(int i = 0; i < T.size(); i++)
//     {
//         int cnt = 0;
//         for(int j = i + 1; j < T.size(); j++)
//         {
//             if(T[j] > T[i])
//             {
//                 cnt = j - i;
//                 break;
//             }
//         }
//         res.push_back(cnt);
//     }
//     return res;
// }

// 这么写果不其然超时了
vector<int> dailyTemperatures(vector<int>& T)
{
    vector<int> res(T.size());
    for(int i = T.size() - 2; i >= 0; i --)
    {
        for(int j = i + 1; j < T.size(); j+= res[j]) // 直接跃过后面resj个，因为要是还能循环的话，说明没break，即Ti大于Tj且resj不为0
        {
            if(T[i] < T[j])
            {
                res[i] = j - i;
                break;
            }
            else if(res[j] == 0) // 要是找不到比后面那个还大的了
            {
                res[i] = 0; // 那么当前这个肯定也找不到
                break;
            } 
        }
    }
    return res;
}
