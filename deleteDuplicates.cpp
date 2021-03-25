/*
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。

返回同样按升序排列的结果链表。

 

示例 1：


输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
示例 2：


输入：head = [1,1,1,2,3]
输出：[2,3]
 

提示：

链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序排列
通过次数99,234提交次数194,022

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) 
{
    if(!head || !head->next)
    {
        return head; // 返回head而不是null，因为一个节点的话，不能返回null
    }
    ListNode *dummy = new ListNode(-1), *pre = dummy; // 模板式的链表题
    dummy->next = head; // 保留节点作为返回
    while(head && head->next) // 两个都不能少，不然next为null会对内部执行有影响
    {
        if(head->val != head->next->val)
        {
            pre = head; // pre始终指向不重复的节点
            head = head->next;
        }
        else
        {
            while(head && head->next && head->val == head->next->val)
            {
                head = head->next;
            }
            pre->next = head->next;
            head = head->next;
        }
        
    }
    return dummy->next;
}

// 模板题，建议多做几遍