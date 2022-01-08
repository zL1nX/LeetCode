/*
n 位格雷码序列 是一个由 2n 个整数组成的序列，其中：
每个整数都在范围 [0, 2n - 1] 内（含 0 和 2n - 1）
第一个整数是 0
一个整数在序列中出现 不超过一次
每对 相邻 整数的二进制表示 恰好一位不同 ，且
第一个 和 最后一个 整数的二进制表示 恰好一位不同
给你一个整数 n ，返回任一有效的 n 位格雷码序列 。

 

示例 1：

输入：n = 2
输出：[0,1,3,2]
解释：
[0,1,3,2] 的二进制表示是 [00,01,11,10] 。
- 00 和 01 有一位不同
- 01 和 11 有一位不同
- 11 和 10 有一位不同
- 10 和 00 有一位不同
[0,2,3,1] 也是一个有效的格雷码序列，其二进制表示是 [00,10,11,01] 。
- 00 和 10 有一位不同
- 10 和 11 有一位不同
- 11 和 01 有一位不同
- 01 和 00 有一位不同
示例 2：

输入：n = 1
输出：[0,1]
 

提示：

1 <= n <= 16
通过次数67,396提交次数93,853

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gray-code
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

vector<int> grayCode(int n) 
{
    vector<int> res;
    res.push_back(0); // 0阶格雷码
    for(int i = 0; i < n; i++)
    {
        int m = res.size();
        for(int j = m - 1; j >= 0;j --) // 要添加的数量，等于上一阶的格雷码数量
        {
            res.push_back(res[j] | (1 << i)); // 逆序添加，并且每个元素都在最高位前加1
        }
    }
    return res;
}

// 格雷码的镜面逆序生成，还挺有意思的 

// 在上一阶格雷码的基础上，在所有元素前面加1，然后逆序加到 原数组后面，就成了下一阶格雷码

// 牛啊，感觉直接背了算了