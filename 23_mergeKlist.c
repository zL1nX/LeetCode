/*#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
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
    return Lhead->next;

}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    int flag = 0,i;
    struct ListNode *r,*s,new_list;
    new_list.next = NULL;
    s = &new_list;
    while(flag != -1)
    {
        //printf("here2!\n");
        flag = -1;
        int min = 100000;
        for(i=0;i<listsSize;i++)
        {
            //printf("here2.5!\n");
            if(lists[i] != NULL && lists[i]->val <= min)
            {
                min = lists[i]->val;
                flag = i;
                //printf("%d %d\n",flag,min);
            }
        }
        if(flag != -1)
        {
            r = (struct ListNode*)malloc(sizeof(struct ListNode*));
            r->val = min;
            r->next = NULL;
            s->next = r;
            s = r;
            lists[flag] = lists[flag]->next;
        }
    }

    return new_list.next;
}
void Print(struct ListNode* p)
{
    while(p)
    {
        printf("%d ",p->val);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    int list_num,i;
    scanf("%d",&list_num);
    struct ListNode **lists = (struct ListNode**)malloc(sizeof(struct ListNode*)*list_num);
    struct ListNode *res;
    for(i=0;i<list_num;i++)
    {
        //lists[i] = (struct ListNode*)malloc(sizeof(struct ListNode*));
        lists[i] = Create();
        Print(lists[i]);
    }
    res = mergeKLists(lists,list_num);
    printf("out\n");
    Print(res);

    return 0;
}*/
