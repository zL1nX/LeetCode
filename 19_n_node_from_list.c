/*#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* Create(int node_num)
{
    int i,node_val;
    struct ListNode *r,*s;
    struct ListNode *Lhead = (struct ListNode*)malloc(sizeof(struct ListNode*));
    Lhead->next = NULL;
    r = Lhead;
    for(i=0;i<node_num;i++)
    {
        scanf("%d",&node_val);
        s = (struct ListNode*)malloc(sizeof(struct ListNode*));
        s->val = node_val;
        if(Lhead == NULL)
        {
             Lhead = s;
             printf("hahah:%d\n",Lhead->val);
        }
        else
        {
            s->next = r->next;
            r->next = s;
            r = s;
        }
    }
    return Lhead;

}
void Print(struct ListNode* p)
{
    printf("in!\n");
    while(p)
    {
        printf("%d\n",p->val);
        p = p->next;
    }
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if(n<1) return NULL;
    int i;
    struct ListNode *fast,*slow;
    fast = head;slow = head;
    for(i=0;i<n;i++)
    {
        fast = fast->next;
        if(fast == NULL)
        {
            printf("yes\n");
            return head->next;
        }

    }

    while(fast->next!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}
int main()
{
    int node_num,n;
    scanf("%d %d",&node_num,&n);
    struct ListNode *Lhead = (struct ListNode*)malloc(sizeof(struct ListNode*));
    Lhead = Create(node_num);

    Print(Lhead->next);
    Lhead = removeNthFromEnd(Lhead,n);
    if(Lhead->next)
        Print(Lhead->next);
    return 0;
}*/
