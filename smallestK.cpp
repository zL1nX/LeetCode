/*
设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。

示例：

输入： arr = [1,3,5,7,2,4,6,8], k = 4
输出： [1,2,3,4]
提示：

0 <= len(arr) <= 100000
0 <= k <= min(100000, len(arr))


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-k-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <queue>
using namespace std;

vector<int> smallestK(vector<int>& arr, int k) 
{
    sort(arr.begin(), arr.end());
    return vector<int>(arr.begin(), arr.begin() + k);
}

vector<int> smallestK(vector<int>& arr, int k) 
{
    priority_queue<int, vector<int>, less<int>> q;
    for(int i = 0; i < arr.size(); i++)
    {
        q.push(arr[i]);
        if(q.size() > k)
        {
            q.pop();
        }
    }
    vector<int> res(k);
    for(int i = k - 1; i >= 0; i--)
    {
        res[i] = q.top();
        q.pop();
    }
    return res; 
}

// 乍一看只有排序 或 小根堆两种方法

// 但题目中说，能以任意顺序返回元素。因此只要挑出来这小的就可以

// 因此似乎可以使用快排的思想去写