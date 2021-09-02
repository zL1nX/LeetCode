/*
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。

 

示例：

给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.
通过次数223,477提交次数282,037

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getKthFromEnd(ListNode* head, int k) 
{
    int distance = 0;
    ListNode *p = head, *q = head;
    for(int i = 0; i < k && q != nullptr; i++)
    {
        q = q->next;
    }
    while(q != nullptr && p != nullptr){
        p = p->next;
        q = q->next;
    }
    return p;
}

// 快慢指针中间差k个距离即可，这样要比传统的两次遍历更快一些

// 也是简单题，但可以直接写，面试也可能会写