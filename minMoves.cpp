/*
给你一个长度为 n 的整数数组，每次操作将会使 n - 1 个元素增加 1 。返回让数组所有元素相等的最小操作次数。

 

示例 1：

输入：nums = [1,2,3]
输出：3
解释：
只需要3次操作（注意每次操作会增加两个元素的值）：
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
示例 2：

输入：nums = [1,1,1]
输出：0
 

提示：

n == nums.length
1 <= nums.length <= 105
-109 <= nums[i] <= 109
答案保证符合 32-bit 整数


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <numeric>
using namespace std;

int minMoves(vector<int>& nums) 
{
    int minn = *min_element(nums.begin(), nums.end());
    int sumn = accumulate(nums.begin(), nums.end(), 0);
    return sumn - minn * nums.size();
}

// 这个题有意思，虽然最开始没想出来

// 就是说，当有n-1个数加一时，相当于所有数加1，唯独有一个数加完还要再减1。这不就相当于，所有人的差距没变，每次有一个人要自减来减少差距吗

// 因此大家最后要变相等的话，就是除了最小值的其他所有值都自减到它，那么结果其实就是 所有值 与 最小值 之间差的和

// 这也就是正难则反，不过这种思维还是挺好玩的。就是所有人加了，等于没加。其余所有人加了，相当于你减了

// 以及这不就是一个木桶原理的影子吗