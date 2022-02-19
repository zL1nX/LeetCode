/*
给你一个整数数组 arr ，请使用 煎饼翻转 完成对数组的排序。

一次煎饼翻转的执行过程如下：

选择一个整数 k ，1 <= k <= arr.length
反转子数组 arr[0...k-1]（下标从 0 开始）
例如，arr = [3,2,1,4] ，选择 k = 3 进行一次煎饼翻转，反转子数组 [3,2,1] ，得到 arr = [1,2,3,4] 。

以数组形式返回能使 arr 有序的煎饼翻转操作所对应的 k 值序列。任何将数组排序且翻转次数在 10 * arr.length 范围内的有效答案都将被判断为正确。

 

示例 1：

输入：[3,2,4,1]
输出：[4,2,4,3]
解释：
我们执行 4 次煎饼翻转，k 值分别为 4，2，4，和 3。
初始状态 arr = [3, 2, 4, 1]
第一次翻转后（k = 4）：arr = [1, 4, 2, 3]
第二次翻转后（k = 2）：arr = [4, 1, 2, 3]
第三次翻转后（k = 4）：arr = [3, 2, 1, 4]
第四次翻转后（k = 3）：arr = [1, 2, 3, 4]，此时已完成排序。 
示例 2：

输入：[1,2,3]
输出：[]
解释：
输入已经排序，因此不需要翻转任何内容。
请注意，其他可能的答案，如 [3，3] ，也将被判断为正确。
 

提示：

1 <= arr.length <= 100
1 <= arr[i] <= arr.length
arr 中的所有整数互不相同（即，arr 是从 1 到 arr.length 整数的一个排列）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pancake-sorting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


vector<int> pancakeSort(vector<int>& arr) 
{
    vector<int> res;
    for(int n = arr.size(); n > 1; n--)
    {
        int maxi = max_element(arr.begin(), arr.begin() + n) - arr.begin(); // find the largest element
        if(maxi == n - 1) // 恰好最大值就在最后一个位置
        {
            continue;
        }
        reverse(arr.begin(), arr.begin() + maxi + 1); // 先reverse前半部分，把这个最大值放到最前面
        // 注意这里是max + 1，这样才能把max也算上，因为C++迭代器是前开后闭的
        reverse(arr.begin(), arr.begin() + n); // 再reverse整个数组，把这个最大值放到末尾
        res.push_back(maxi + 1); // 因为reverse（即操作了两次，所以要push这两次的index进去）
        res.push_back(n); 
    }
    return res; // 这只是一种满足条件的结果，其实并不是最优的（因为每次都要reverse两次）
}


// 煎饼排序算法，神奇

// 转化的思路和冒泡排序很像，就是每次找出当前数组最大的元素，然后把这个最大值放到数组最后

// 之后，对于除最后一个元素之外的前面所有元素，重复相同的过程，即找到最大元素然后放到最后

// 这样一来，这种递归的过程处理外，就可以让原数组变成一个有序数组了

// 在实现的时候，找到最大值之后，先reverse一次，把当前最大值放到最前面，再reverse一次把它放到后面即可