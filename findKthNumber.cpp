/*
给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。

 

示例 1:

输入: n = 13, k = 2
输出: 10
解释: 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
示例 2:

输入: n = 1, k = 1
输出: 1
 

提示:

1 <= k <= n <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>

using namespace std;

int findKthNumber(int n, int k) 
{
    int curNum = 1;
    k--; // 因为是1到n, 所以刚开始k就要先减去一个
    while(k > 0)
    {
        int steps = getSteps(curNum, n); // 从根节点开始, 到当前节点这个子树的所有子节点数
        if(steps <= k)
        {
            k -= steps;
            curNum++;
        }
        else
        {
            curNum *= 10; // 将cur移到字典树的下一层中
            k--;
        }
    }
    return curNum;
}


int getSteps(int curNum, long n)
{
    long first = curNum, last = curNum;
    int steps = 0;
    while(first <= n)
    {
        steps += min(last, n) - first + 1; // 所有子树节点的个数
        // min(last, n) 不一定每层都是刚好整个节点
        first = first * 10; // 最左端的节点
        last = last * 10 + 9; // 最右端的节点
    }
    return steps;
}

// 据说是字节的常考难题

// 图形化的角度, 如果以字典树的形式, 是很好理解的

// 要么k在这一层, 要么不在, 最后找到那个让k为0的curnum

// 同时, 要找到每一层的子节点数 (而且要累加之前所有的)