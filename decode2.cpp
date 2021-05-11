/*
给你一个整数数组 perm ，它是前 n 个正整数的排列，且 n 是个 奇数 。

它被加密成另一个长度为 n - 1 的整数数组 encoded ，满足 encoded[i] = perm[i] XOR perm[i + 1] 。比方说，如果 perm = [1,3,2] ，那么 encoded = [2,1] 。

给你 encoded 数组，请你返回原始数组 perm 。题目保证答案存在且唯一。

 

示例 1：

输入：encoded = [3,1]
输出：[1,2,3]
解释：如果 perm = [1,2,3] ，那么 encoded = [1 XOR 2,2 XOR 3] = [3,1]
示例 2：

输入：encoded = [6,5,4,6]
输出：[2,4,1,5,3]
 

提示：

3 <= n < 105
n 是奇数。
encoded.length == n - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-xored-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

vector<int> decode(vector<int>& encoded) 
{
    vector<int> result;
    int n = encoded.size();
    int all_xor = 0;
    for(int i = 1; i <= n; i++)
    {
        all_xor ^= i;
    }
    // 所有的异或起来：a xor b xor c xor d xor e
    int left_xor = 0; // 除了a之外的异或起来 b xor c xor d xor e
    for(int i = 1; i <= n + 1; i += 2)
    {
        left_xor ^= encoded[i];
    }
    int first = all_xor ^ left_xor; // 即为a，剩下的就很简单了
    result.push_back(first);
    for(int i = 0; i < n; i ++)
    {
        first ^= encoded[i];
        result.push_back(first);
    }
    return result;
}

// 注意到原数组是前n个数的排列，因此原数组的总异或值是一定的