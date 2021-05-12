/*
有一个正整数数组 arr，现给你一个对应的查询数组 queries，其中 queries[i] = [Li, Ri]。

对于每个查询 i，请你计算从 Li 到 Ri 的 XOR 值（即 arr[Li] xor arr[Li+1] xor ... xor arr[Ri]）作为本次查询的结果。

并返回一个包含给定查询 queries 所有结果的数组。

 

示例 1：

输入：arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
输出：[2,7,14,8] 
解释：
数组中元素的二进制表示形式是：
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
查询的 XOR 值为：
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
示例 2：

输入：arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
输出：[8,0,4,4]
 

提示：

1 <= arr.length <= 3 * 10^4
1 <= arr[i] <= 10^9
1 <= queries.length <= 3 * 10^4
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] < arr.length
通过次数10,598提交次数15,113

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xor-queries-of-a-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
{
    vector<int> result;
    for(int i = 0; i < queries.size(); i++)
    {
        int qres = 0;
        for(int j = queries[i][0]; j <= queries[i][1]; j++)
        {
            qres ^= arr[j];
        }
        result.push_back(qres);
    }
    return result;
}
// 直接暴力写，然后超时了（流汗黄豆）

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
{
    vector<int> result;
    for(int i = 0; i < arr.size(); i++)
    {
        arr[i] = arr[i - 1] ^ arr[i]; // 每个arr即为包括自己的前面所有值的异或 
    }
    for(int i = 0; i < queries.size(); i++)
    {
        if(queries[i][0] == 0)
        {
            result.push_back(arr[queries[i][1]]); //要是从0开始查，那直接插入这个值即可
        }
        else
        {
            result.push_back(arr[queries[i][0] - 1] ^ arr[queries[i][1]]); // 否则，用query的前一个异或query的右边界，由于异或性质就可以得到中间这部分的查询异或值
        }
    }
    return result;
}

// 用前缀和的思想减少重复运算的次数