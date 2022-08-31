/*
给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。

 

示例 1：

输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
示例 2：

输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。
 

提示：

1 <= pushed.length <= 1000
0 <= pushed[i] <= 1000
pushed 的所有元素 互不相同
popped.length == pushed.length
popped 是 pushed 的一个排列
通过次数44,786提交次数68,776

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/validate-stack-sequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <stack>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
{
    stack<int> in;
    int n = pushed.size();
    for(int p = 0, q = 0; p < n; p++)
    {
        in.push(pushed[p]);
        while(!in.empty() && in.top() == popped[q]) // 注意这里是while, 即把符合条件的栈顶元素都pop完再说
        {
            in.pop();
            q++;
        }
    }
    return in.empty();
}

// 本来想着分开双指针弄, 但这样发现不好判断指针的边界情况

// 于是换成这种单个for循环保证全push进去, 里面while循环保证全pop出来

// 据说是408经典题, 需要多看看