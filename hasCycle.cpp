/*
给定一个链表，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

如果链表中存在环，则返回 true 。 否则，返回 false 。

 

进阶：

你能用 O(1)（即，常量）内存解决此问题吗？
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) 
{
    if(head == nullptr)
    {
        return false;
    }    
    ListNode *p = head;
    ListNode *q = head;
    while(q && q->next)
    {
        p = p->next; // the slow pointer
        q = q->next->next; // the fast pointer
        // it's important to make a pointer move faster than another
        if(p == q) // they met 
        {
            return true;
        }
    }
    return false;
    
}