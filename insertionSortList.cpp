/*
插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

 

插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

示例 1：

输入: 4->2->1->3
输出: 1->2->3->4
示例 2：

输入: -1->5->3->4->0
输出: -1->0->3->4->5

*/
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* insertionSortList(ListNode* head) 
{
        ListNode* dummy=new ListNode(-1);
        while(head){
            ListNode* p=dummy;
            while(p->next && p->next->val<head->val) p=p->next;
            ListNode* q=head;
            head=head->next;
            
            q->next=p->next;
            p->next=q;
        }
        return dummy->next;
}

/*

void insertion_sort(int arr[],int len){
        for(int i=1;i<len;i++){
                int key=arr[i];
                int j=i-1;
                while((j>=0) && (key<arr[j])){
                        arr[j+1]=arr[j];
                        j--;
                }
                arr[j+1]=key;
        }
}
*/
