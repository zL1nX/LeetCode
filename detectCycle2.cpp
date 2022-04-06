/*
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。

 

示例 1：



输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：



输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：



输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。
 

提示：

链表中节点的数目范围在范围 [0, 104] 内
-105 <= Node.val <= 105
pos 的值为 -1 或者链表中的一个有效索引
 

进阶：你是否可以使用 O(1) 空间解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *detectCycle(ListNode *head) 
{
    ListNode *fast = head, *slow = head;
    while(fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            break;
        }
    }
    if(fast == nullptr || fast->next == nullptr)
    {
        return nullptr;
    }
    fast = head;
    while(fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

// 如果不要求O(1)的空间 那么直接用map存遍历过的每个节点即可, 然后同时看这个节点之前是否出现过

// 原地的话, 首先就是判断链表中是否有环, 这一点可以用快慢指针, 快指针每次走两步, 慢指针每次走一步, 最终二者一定能相交 (相当于把环展开若干次的中点)

// 此时两指针的相遇点并不一定是环的起点, 要找环的起点, 此时要让fast或slow从链表的起点开始, 继续一起走, 相遇时即为环的起点

// 因为相遇点既然是环展开的全局的中点, 因此从头开始到环起点的距离, 和从相遇点开始到环起点的距离, 都是一样的 (画图)

// 经典问题 多做几遍