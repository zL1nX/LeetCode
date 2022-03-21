/*
给定单链表的头节点 head ，请反转链表，并返回反转后的链表的头节点。

 

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
链接：https://leetcode-cn.com/problems/UHnkqh
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* reverseList(ListNode* head) 
{
    ListNode* nhead = reverse(head);
    return nhead;
}

ListNode* reverse(ListNode* node)
{
    if(node == nullptr || node->next == nullptr)
    {
        return node;
    }
    ListNode* last = reverse(node->next);
    node->next->next = node; // 记住此时返回的last是首节点, node->next指向的节点目前是最后一个节点
    node->next = nullptr;
    return last;
}

// 从最后一个递归的栈开始想, 也就是只有最后两个结点时, 该如何反转两个结点的顺序, 然后不断递归上去即可