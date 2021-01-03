/*
给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

 

示例：

输入：head = 1->4->3->2->5->2, x = 3
输出：1->2->2->4->3->5
通过次数64,778提交次数106,856

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* partition(ListNode* head, int x) 
{
    ListNode *p = head;
    ListNode *lessHead = new ListNode(0), *greatHead = new ListNode(0);
    ListNode *l = lessHead, *g = greatHead;
    while(p)
    {    
        if(p->val < x)
        {
            l->next = p;
            l = l->next;
        }
        else
        {
            g->next = g;
            g = g->next;
        }
        p = p->next;
    }
    l->next = greatHead->next;
    g->next = nullptr;
    return lessHead->next;
}

// 注意head是dummy head，即每次都是往next上赋点