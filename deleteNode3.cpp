/*
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。

注意：此题对比原题有改动

示例 1:

输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
示例 2:

输入: head = [4,5,1,9], val = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
 

说明：

题目保证链表中节点的值互不相同
若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteNode(ListNode* head, int val) 
{
    ListNode *dummy = new ListNode(-1), *p=dummy;
    dummy->next = head;
    while(p->next) // 如果p->next指向的是最后一个节点, 那么这就是最后一个循环
    {
        if(p->next->val == val)
        {
            p->next = p->next->next;
            break; // 记得删完后立即退出
        }
        p = p->next;
    }
    return dummy->next;
}

// 链表节点的删除, 看似简单, 但写的时候依然要注意dummy的区别

// dummy head和p->next就不说了,这肯定不会写错

// 注意的是删完之后要break, 否则在末尾节点时, 就会导致去访问一个nullptr的next, 自然就会报错了