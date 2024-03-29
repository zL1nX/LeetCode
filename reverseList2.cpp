/*
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

 

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
 

限制：

0 <= 节点个数 <= 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) 
{
    ListNode* nhead = reverse(head);
    return nhead;
}

ListNode* reverse(ListNode* node)
{
    if(node == nullptr || node->next == nullptr) // 这里就是为了逮住最后一个节点,所以是node->next
    {
        return node;
    }
    ListNode* last = reverse(node->next);
    node->next->next = node; //连带node算最后一个节点
    node->next = nullptr;
    return last;
}