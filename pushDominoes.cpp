/*
n 张多米诺骨牌排成一行，将每张多米诺骨牌垂直竖立。在开始时，同时把一些多米诺骨牌向左或向右推。

每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。

如果一张垂直竖立的多米诺骨牌的两侧同时有多米诺骨牌倒下时，由于受力平衡， 该骨牌仍然保持不变。

就这个问题而言，我们会认为一张正在倒下的多米诺骨牌不会对其它正在倒下或已经倒下的多米诺骨牌施加额外的力。

给你一个字符串 dominoes 表示这一行多米诺骨牌的初始状态，其中：

dominoes[i] = 'L'，表示第 i 张多米诺骨牌被推向左侧，
dominoes[i] = 'R'，表示第 i 张多米诺骨牌被推向右侧，
dominoes[i] = '.'，表示没有推动第 i 张多米诺骨牌。
返回表示最终状态的字符串。

 
示例 1：

输入：dominoes = "RR.L"
输出："RR.L"
解释：第一张多米诺骨牌没有给第二张施加额外的力。
示例 2：


输入：dominoes = ".L.R...LR..L.."
输出："LL.RR.LLRRLL.."
 

提示：

n == dominoes.length
1 <= n <= 105
dominoes[i] 为 'L'、'R' 或 '.'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/push-dominoes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>

using namespace std;

string pushDominoes(string dominoes) 
{
    int n = dominoes.size(), i = 0;
    char left = 'L';
    while(i < n)
    {
        int j = i;
        while(j < n && dominoes[j] == '.')
        {
            j++; // 找到连续的一段骨牌范围，这些i到j就是我们要改变状态的骨牌
        }
        char right = j < n ? dominoes[j] : 'R'; // left和right分别就是外围最近的两个骨牌的状态（区间外哦）
        if(left == right) // 外围的两个骨牌状态相同
        {
            while(i < j)
            {
                dominoes[i] = left; // 那么中间的骨牌都要倒向一个方向
                i++;
            }
        }
        else if(left == 'R' && right == 'L') // 外围的两个骨牌方向朝内
        {
            int k = j - 1;
            while(i < k) // 对于内部所有骨牌，除了最中间的那个（所以没取等）
            {
                dominoes[i++] = left; // 都朝各自边界的方向倒
                dominoes[k--] = right;
            }
        } // 外围两个骨牌方向朝外，不改变中间的状态
        i = j + 1; // 开始下一次的寻找
        left = right;
    }
    // 注意上述过程中，left right是在区间外的两个骨牌的状态
    // i 是区间第一个骨牌，j是right对应的骨牌，因此要处理的对象实际上是 [i, j) 这样一个情况
    return dominoes;
}

// 个人最讨厌写的一种题：双指针模拟

// 首先明确一点就是：只有处于 . 状态的才会发生改变，LR均不会改变状态；

// 因此，我们要处理的对象就是 那些连续在一起的 . 骨牌

// 第一步就是用双指针来确定我们要处理的范围，确定后根据最边上的骨牌状态，来实现对中间这些骨牌状态的改变

// 说起来感觉很简单，但实际分析起来还有点抽象，写起来就更不是很好写了

// 这题的区间端点设计，骨牌倒的分类讨论都很经典，可以多写几遍