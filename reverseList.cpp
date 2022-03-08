/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 

示例 1：


输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
示例 2：


输入：head = [1,2]
输出：[2,1]
示例 3：

输入：head = []
输出：[]
 

提示：

链表中节点的数目范围是 [0, 5000]
-5000 <= Node.val <= 5000
 

进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 最傻瓜，最好写的，就是借用外部空间来存储节点，在新建一个新的链表
ListNode* reverseList(ListNode* head) 
{
    ListNode* p = head;
    vector<int> nodes;
    while(p != nullptr)
    {
        nodes.push_back(p->val);
        p = p->next;
    }
    ListNode* dummy = new ListNode(0), *q = dummy;
    for(int i = nodes.size() - 1; i >= 0; i--)
    {
        q->next = new ListNode(nodes[i]);
        q = q->next;
    }
    return dummy->next;
}

// 递归的方式写起来要非常的简洁，而且很有分而治之的思维
ListNode* reverseList(ListNode* head) 
{
    ListNode* nhead = partialReverse(head);
    return nhead;
}

ListNode* partialReverse(ListNode* node)
{
    if(node == nullptr || node->next == nullptr)
    {
        return node;
    }
    ListNode* last = partialReverse(node->next); // the rest of the list except the first node;
    // 这里要把问题简化，即递归下去，其实就相当于每次把除了node结点外的剩余节点翻转
    // 此时last是翻转后的头部，原来的node->next就成了最后一个节点
    node->next->next = node;
    // 所以这里就相当于把node作为了最后一个节点加入了
    node->next = nullptr;
    // 记得把最后一个节点的next置空
    return last;
}

// 递归这个写起来还真的很简洁，reverse递归那一步要想清楚是怎么实现的翻转。
