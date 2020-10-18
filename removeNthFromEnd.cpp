/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    ListNode *p = head, *q = head;
    int len = 0, cnt = 0;
    while(p)
    {
        len ++;
        p = p->next;
    }
    if(n == len)
    {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head->next;
        return dummy->next;
    }
    else
    {
        while(q)
        {
            cnt ++;
            if(cnt == len - n)
            {
                q->next = q->next->next;
            }
            q = q->next;
        }
    } 
    return head;
}

/*
一次遍历的方法，定义两个指针，一个指针比另一个超前n个
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
