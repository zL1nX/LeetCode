/*#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
struct ListNode{
    int val;
    struct ListNode *next;
};
struct ListNode* Create()
{
    int nodeNum,i,nodeVal;
    scanf("%d",&nodeNum);
    struct ListNode *Lhead,*r,*s;
    Lhead = (struct ListNode*)malloc(sizeof(struct ListNode*));
    Lhead->next = NULL;
    r = Lhead;
    for(i=0;i<nodeNum;i++)
    {
        scanf("%d",&nodeVal);
        s = (struct ListNode*)malloc(sizeof(struct ListNode*));
        s->val = nodeVal;
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
struct ListNode* addTwoNumbers(struct ListNode *l1,struct ListNode *l2)
{

    int z = 0;
    struct ListNode *l3,*p;
    l3 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    l3->next = NULL;
    p = l3;
    while(l1 || l2)
    {
        //printf("%d %d\n",l1->val,l2->val);
        int current_val1 = l1 ? l1->val : 0;
        int current_val2 = l2 ? l2->val : 0;
        //printf("%d %d\n",current_val1,current_val2);
        int sum = current_val1 + current_val2 + z;
        z = sum / 10;
        struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode*));
        new_node->val = sum % 10;
        new_node->next = p->next;
        p->next = new_node;
        p = new_node;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if(z > 0)
    {
        struct ListNode *another_node = (struct ListNode*)malloc(sizeof(struct ListNode*));
        another_node->val = z;
        another_node->next = p->next;
        p->next = another_node;
        p = another_node;
    }
    return l3->next;
}
void Print(struct ListNode *p)
{
    while(p)
    {
        printf("%d\n",p->val);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    struct ListNode *l1,*l2,*l3;
    l1 = Create();
    l2 = Create();
    Print(l1->next);
    Print(l2->next);
    l3 = addTwoNumbers(l1->next,l2->next);
    Print(l3);
    return 0;
}*/
