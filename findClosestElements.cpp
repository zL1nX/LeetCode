/*
给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。

整数 a 比整数 b 更接近 x 需要满足：

|a - x| < |b - x| 或者
|a - x| == |b - x| 且 a < b
 

示例 1：

输入：arr = [1,2,3,4,5], k = 4, x = 3
输出：[1,2,3,4]
示例 2：

输入：arr = [1,2,3,4,5], k = 4, x = -1
输出：[1,2,3,4]
 

提示：

1 <= k <= arr.length
1 <= arr.length <= 104
arr 按 升序 排列
-104 <= arr[i], x <= 104
通过次数49,244提交次数105,175

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-k-closest-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) 
{
    int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int left = right - 1; // (left,right] 即为满足题目要求的区间元素
    while(k--) // 每次调整一个边界, 长度加一, 每次都是要扩充元素
    {
        if(left < 0)
        {
            right ++;
        }
        else if (right >= arr.size()) // 边界处理
        {
            left--;
        }
        else if(x - arr[left] <= arr[right] - x) // 这个就是判断与x的距离, 因为是要扩充元素, 肯定是基于已有判断进行扩充
        {
            left--; // 当左边界更小时, 肯定希望是再往左边界扩充个元素, 直到发现右边界更小了
        }
        else
        {
            right++;
        }
    }
    return vector<int>(arr.begin() + left + 1, arr.begin() + right);
}

// 先通过lower bound定位中间元素, 然后通过双指针left和right不断向外扩充

// 或者可以反向思维, left和right从外向内不断删除元素, 两种思路在改变区间范围时的判断条件恰好相反

// 有意思的一道题
/*
public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int size = arr.length;

        int left = 0;
        int right = size - 1; // 从外向内进行删除

        int removeNums = size - k;
        while (removeNums > 0) {
            if (x - arr[left] <= arr[right] - x) {
                right--;
            } else {
                left++;
            }
            removeNums--;
        }

        List<Integer> res = new ArrayList<>();
        for (int i = left; i < left + k; i++) {
            res.add(arr[i]);
        }
        return res;
    }

作者：liweiwei1419
链接：https://leetcode.cn/problems/find-k-closest-elements/solution/pai-chu-fa-shuang-zhi-zhen-er-fen-fa-python-dai-ma/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/