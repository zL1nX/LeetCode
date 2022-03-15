/*
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
限制：

0 <= 链表长度 <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    ListNode *dummy = new ListNode(-1), *cur = dummy;
    ListNode *p1 = l1, *p2 = l2;
    while(p1 != nullptr && p2 != nullptr)
    {
        if(p1->val > p2->val)
        {
            cur->next = p2; // 
            p2 = p2->next;
        }
        else
        {
            cur->next = p1;
            p1 = p1->next;
        }
        cur = cur->next;
    }
    if(p1 != nullptr)
    {
        cur->next = p1; //
    }
    else if(p2 != nullptr)
    {
        cur->next = p2;
    }
    return dummy->next;
}

// 合并有序链表, 核心在于两个链表指针和新链表指针之间的关系 (ps. 我们不新建节点,而是只新建指针来构建已有节点之间的关系)

// 如果让cur指向了dummy, 那么注意每次移动时都是让cur->next指向已有的某个指针指向的节点

// 这样一来,cur本身可以无忧无虑地移到了cur->next,就少去了一些判断空节点的麻烦

// 记得最后把cur挂载到那个更长一些的链表上即可

