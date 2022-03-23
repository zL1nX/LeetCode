/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例 1：


输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]
 

提示：

两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列
通过次数924,123提交次数1,385,672

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    ListNode *p1 = list1, *p2 = list2;
    ListNode *dummy = new ListNode(0), *cur = dummy; // 记得这是直接用dummy 而非dummy->next
    while(p1 != nullptr && p2 != nullptr)
    {
        if(p1->val < p2->val)
        {
            cur->next = p1;
            p1 = p1->next;
        }
        else // 记得这没有if 否则就少个点
        {
            cur->next = p2;
            p2 = p2->next;
        }
        cur = cur->next;
    }
    if(p1 != nullptr)
    {
        cur->next = p1;
    }
    if(p2 != nullptr)
    {
        cur->next = p2;
    }
    return dummy->next;
}