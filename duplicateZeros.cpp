/*
给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。

注意：请不要在超过该数组长度的位置写入元素。

要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。

 

示例 1：

输入：[1,0,2,3,0,4,5,0]
输出：null
解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]
示例 2：

输入：[1,2,3]
输出：null
解释：调用函数后，输入的数组将被修改为：[1,2,3]
 

提示：

1 <= arr.length <= 10000
0 <= arr[i] <= 9
通过次数26,849提交次数45,283

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/duplicate-zeros
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

void duplicateZeros(vector<int>& arr) 
{
    vector<int> loc;
    int n = arr.size();
    for(int i = 0; i < n; i++)
    {
        loc.push_back(arr[i]);
        if(arr[i] == 0)
        {
            loc.push_back(0);
        }
    }
    for(int i = 0; i < n; i++)
    {
        arr[i] = loc[i];
    }
} 

// 我寻思你也妹说不能额外空间啊 (逃

// 双指针也太难想到了吧, 我麻了