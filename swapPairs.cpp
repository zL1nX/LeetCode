/*

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) 
{
    ListNode *h = new ListNode(-1);
    h->next = head;
    ListNode *pre = h, *a, *b, *lat;
    while(pre->next && pre->next->next)
    {
        a = pre->next;
        b = a->next;
        lat = b->next;

        pre->next = b;
        b->next = a;
        a->next = lat;
        pre = a;
    }
    return h->next;
    // return head 则会从第二个节点给return  
}