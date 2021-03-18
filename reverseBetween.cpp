/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
通过次数114,230提交次数217,174

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) 
{
    if(left >= right)
    {
        return head;
    }
    ListNode* dummy = new ListNode(-1), *pre = dummy;
    dummy->next = head;
    for(int i = 0; i < left - 1;i++)
    {
        pre = pre->next;
    }
    ListNode *curr = pre->next, *next = nullptr;
    for(int i = 0; i < right - left; i++)
    {
        next = curr->next;
        curr->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    return dummy->next;
}

// 淦 好绕；不看题解真不会，感觉这个就是那种得背下来的题了