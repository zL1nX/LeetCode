/*#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *l3,*p1,*p2,*r,*s;
    p1 = l1->next;p2 = l2->next;
    l3 = (struct ListNode*)malloc(sizeof(l3));
    l3->next = NULL;
    r = l3;//larger
    while(p1 && p2)
    {
        if(p1->val <= p2->val)
        {
            s = (struct ListNode*)malloc(sizeof(s));
            s->val = p1->val;
            s->next = r->next;
            r->next = s;
            r = s;
            p1 = p1->next;
        }
        else
        {
            s = (struct ListNode*)malloc(sizeof(s));
            s->val = p2->val;
            s->next = r->next;
            r->next = s;
            r = s;
            p2 = p2->next;
        }
    }
    while(p1)
    {
        s = (struct ListNode*)malloc(sizeof(s));
        s->val = p1->val;
        s->next = r->next;
        r->next = s;
        r = s;
        p1 = p1->next;
    }
    while(p2)
    {
        s = (struct ListNode*)malloc(sizeof(s));
        s->val = p2->val;
        s->next = r->next;
        r->next = s;
        r = s;
        p2 = p2->next;
    }

    return l3;
}

struct ListNode* Create()
{

    int num,node_val,i;
    struct ListNode *Lhead,*r,*s;
    Lhead = (struct ListNode*)malloc(sizeof(struct ListNode*));
    Lhead->next = NULL;
    r = Lhead;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&node_val);
        s = (struct ListNode*)malloc(sizeof(struct ListNode*));
        s->val = node_val;
        if(Lhead == NULL)
        {
            Lhead = s;
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
    while(p)
    {
        printf("%d\n",p->val);
        p = p->next;
    }
}
int main()
{
    struct ListNode *Lhead,*l1,*l2;
    Lhead = (struct ListNode*)malloc(sizeof(struct ListNode*));
    l1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    l2 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    l1 = Create();
    l2 = Create();
    Print(l1->next);
    Print(l2->next);
    Lhead = mergeTwoLists(l1,l2);
    Print(Lhead->next);

    return 0;
}*/
