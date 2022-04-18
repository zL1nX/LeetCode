/*
给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。

你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。

 

示例 1：

输入：n = 13
输出：[1,10,11,12,13,2,3,4,5,6,7,8,9]
示例 2：

输入：n = 2
输出：[1,2]
 

提示：

1 <= n <= 5 * 104
通过次数33,821提交次数44,510

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lexicographical-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

vector<int> lexicalOrder(int n) 
{
    vector<int> numbers(n);
    int curr = 1;
    for(int i = 0; i < n; i++)
    {
        numbers[i] = curr;
        if(curr * 10 <= n)
        {
            curr *= 10; // 例如10 100 1000肯定是要先排的
        }
        else
        {
            while(curr % 10 == 9 || curr + 1 > n) // 当递增到1009这种的时候, 需要递减到101重新开始1011, 1012
            {
                curr /= 10; //因此要递减到第一个末尾不是9的, 可以explore的数字去, (要是后面是两位99, 那必然不能从他俩继续开始)
            }
            curr ++; // 1000排完后, 就是1001, 1002这样递增的
        }
    }
    return numbers;
}

// 感觉可以作为许多面试的模板题, 题面很简单

// 思路就是: 先找到最大的那个数, 然后逐级递增再递减

// 多写几遍感受下这种迭代的DFS