/*
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 

示例 1：


输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]
示例 2：

输入：head = [5], left = 1, right = 1
输出：[5]
 

提示：

链表中节点数目为 n
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

进阶： 你可以使用一趟扫描完成反转吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode * firstNode = nullptr;

ListNode* reverseBetween(ListNode* head, int left, int right) 
{
    if(left == 1)
    {
        return reverseFirstN(head, right);
    }
    head->next = reverseBetween(head->next, left - 1, right - 1);
    return head;
}

ListNode* reverseFirstN(ListNode* head, int n)
{
    if(n == 1)
    {
        firstNode = head->next; // firstNode是不在反转部分里的第一个节点
        return head;
    }
    ListNode *last = reverseFirstN(head->next, n - 1);
    head->next->next = head;
    head->next = firstNode; // 原来是把null接上, 现在是接上那个没被反转的第一个节点
    return last;
}

//  核心在于如何反转前N个节点