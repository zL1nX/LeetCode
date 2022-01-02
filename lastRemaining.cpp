/*
列表 arr 由在范围 [1, n] 中的所有整数组成，并按严格递增排序。请你对 arr 应用下述算法：

从左到右，删除第一个数字，然后每隔一个数字删除一个，直到到达列表末尾。
重复上面的步骤，但这次是从右到左。也就是，删除最右侧的数字，然后剩下的数字每隔一个删除一个。
不断重复这两步，从左到右和从右到左交替进行，直到只剩下一个数字。
给你整数 n ，返回 arr 最后剩下的数字。

 

示例 1：

输入：n = 9
输出：6
解释：
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
arr = [2, 4, 6, 8]
arr = [2, 6]
arr = [6]
示例 2：

输入：n = 1
输出：1
 

提示：

1 <= n <= 109
通过次数10,154提交次数20,016

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/elimination-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

int lastRemaining(int n) 
{
    int k = 0, cnt = n, a1 = 1, step = 1;
    while(cnt > 1)
    {
        if(k % 2 == 0)
        {
            a1 = a1 + step;
        }
        else
        {
            a1 = (cnt % 2 == 0) ? a1 : a1 + step;
        }
        k++;
        cnt >>= 1;
        step <<= 1;
    }
    return a1;
}
// 通过对等差数列的模拟，推出每次删除的时候，首项与末项的递推公式

// 而且每一轮暗含了一个条件就是，每一次删除后数量都会减半，等差数列的差会翻倍

// 而且这个问题很像是约瑟夫环问题，只不过约瑟夫环是循环删除，这个是到头后反着往回删除。

// 看个乐，这题的解法感觉得嗯记住。因为这个题目的模型是一个通用但又有点不一样的。