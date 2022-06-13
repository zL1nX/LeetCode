/*
学校打算为全体学生拍一张年度纪念照。根据要求，学生需要按照 非递减 的高度顺序排成一行。

排序后的高度情况用整数数组 expected 表示，其中 expected[i] 是预计排在这一行中第 i 位的学生的高度（下标从 0 开始）。

给你一个整数数组 heights ，表示 当前学生站位 的高度情况。heights[i] 是这一行中第 i 位学生的高度（下标从 0 开始）。

返回满足 heights[i] != expected[i] 的 下标数量 。

 

示例：

输入：heights = [1,1,4,2,1,3]
输出：3 
解释：
高度：[1,1,4,2,1,3]
预期：[1,1,1,2,3,4]
下标 2 、4 、5 处的学生高度不匹配。
示例 2：

输入：heights = [5,1,2,3,4]
输出：5
解释：
高度：[5,1,2,3,4]
预期：[1,2,3,4,5]
所有下标的对应学生高度都不匹配。
示例 3：

输入：heights = [1,2,3,4,5]
输出：0
解释：
高度：[1,2,3,4,5]
预期：[1,2,3,4,5]
所有下标的对应学生高度都匹配。
 

提示：

1 <= heights.length <= 100
1 <= heights[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/height-checker
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>

using namespace std;

int heightChecker(vector<int>& heights) 
{
    vector<int> sorted(heights);
    sort(sorted.begin(), sorted.end());
    int res = 0;
    for(int i = 0; i < heights.size(); i++)
    {
        if(sorted[i] != heights[i])
        {
            res ++;
        }
    }
    return res;
}

// 最直接的方法, 排序后直接比较

// 还有一种方法是类似于桶排序的计数排序, 因为数据范围最多到100

/*
class Solution {
    public int heightChecker(int[] heights) {
        int[] arr = new int[101];
        for (int height : heights) {
            arr[height]++;
        }
        int count = 0;
        for (int i = 1, j = 0; i < arr.length; i++) {
            while (arr[i]-- > 0) {
                if (heights[j++] != i) count++;
            }
        }
        return count;
    }
}

作者：holy-sword
链接：https://leetcode.cn/problems/height-checker/solution/onjie-fa-yong-shi-yu-nei-cun-ji-bai-100-javayong-h/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

// arr就相当于有若干个桶, 每个桶里有若干个数字


// 从桶里取数据时, 必然是非递减的顺序, 因此这个时候只要按顺序和height进行比较即可了