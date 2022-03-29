/*
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

 

示例 1：


输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
示例 2：


输入：head = [0,1,2], k = 4
输出：[2,0,1]
 

提示：

链表中节点的数目在范围 [0, 500] 内
-100 <= Node.val <= 100
0 <= k <= 2 * 109
通过次数236,318提交次数566,605

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) 
{
    int len = 0;
    if(k == 0 || head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *p = head;
    for(; p != nullptr; p=p->next, len++) {}
    int front = len - k % len; // 是从前面这些节点开始看
    p->next = head; // 直接构成环形链表
    for(int i = 0; i < front; i++)
    {
        p = p->next;
    }
    ListNode *newHead = p->next;
    p->next = nullptr;
    return newHead;
}


// 在策略层面, 这种循环移动链表的题目, 肯定是找到最终的状态, 然后直接做几个节点之间的移动即可

// 肯定不能是直接去模拟这个循环k次的行为

// 而在实际写代码的执行层面, 有一些技巧需要注意

// 1. 在将最后的节点next置空时, 可以用最开始获取长度时的指针来直接操作, 就不用重新进行了 (正是因为这一点, 所以要p->next而非p)

// 2. 移动的是前面 len - k % len 这么多个节点, 别算错.

// 最后节点之间next指针的修改, 其实仔细想一下即可, 重点还是前面的地方容易写错.