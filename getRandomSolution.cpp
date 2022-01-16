/*
给你一个单链表，随机选择链表的一个节点，并返回相应的节点值。每个节点 被选中的概率一样 。

实现 Solution 类：

Solution(ListNode head) 使用整数数组初始化对象。
int getRandom() 从链表中随机选择一个节点并返回该节点的值。链表中所有节点被选中的概率相等。
 

示例：


输入
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
输出
[null, 1, 3, 2, 2, 3]

解释
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // 返回 1
solution.getRandom(); // 返回 3
solution.getRandom(); // 返回 2
solution.getRandom(); // 返回 2
solution.getRandom(); // 返回 3
// getRandom() 方法应随机返回 1、2、3中的一个，每个元素被返回的概率相等。
 

提示：

链表中的节点数在范围 [1, 104] 内
-104 <= Node.val <= 104
至多调用 getRandom 方法 104 次
 

进阶：

如果链表非常大且长度未知，该怎么处理？
你能否在不使用额外空间的情况下解决此问题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-random-node
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <random>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class getRandomSolution {
public:
    ListNode* head;
public:
    getRandomSolution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        ListNode *p = this->head;
        int res = 0, idx = 0;
        while(p != nullptr)
        {
            idx++;
            if(rand() % idx == 0)
            {
                res = p->val;
            }
            p = p->next;
        }
        return res;
    }
};


// 水塘抽样算法；其实直接整个全都遍历一遍存到vector里然后每次getRandom都随机一个索引返回也不是不行

// 但对于未知规模的大型数据流，这种直接的方法就不行了

// 水塘抽样算法就是为了处理这个情况的一种算法，证明啥的就略过了，因为就是最基本的概率论的东西

// 本质上这一题就是要让 第k个节点被选中，并且后面的节点都没有被选中，第k个节点被选中的概率应该是均匀的 这样一件事

// 而水塘抽样算法就是在遍历这个链表的时候，每次都随机生成一个 0到k的数，如果这个数恰好为0（为0概率是均匀的），那么这个点就可以作为答案，遍历一轮结束后，就返回中间的那些符合条件的点

// 在遍历过程中，res是可以不断更新的，而非遇到一个合适的点就直接return，因为水塘采样中，每次随机数生成都是在当前所有节点数量下的随机，因此特别适用于数据流这种每次都有新元素要加进来的情况

// 在遍历结束时，此时随机出的一个数，就是整个数据流中的一个随机节点，当然即使没有遍历结束，前面设置的那些res值也是符合标准的采样值，这就是在数据流中比较特别的地方：永远都不知道什么时候数据结束，所以要保证每个状态采样的值都符合均匀
// 进一步地，在这道题中，其实暴力模拟是要比水塘采样快的，因为暴力只用在最开始的时候遍历一遍，然后在真正random时直接取元素即可，而水塘采样在每次random都会从头遍历，所以测试的结果会慢
