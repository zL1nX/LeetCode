/*
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。

返回同样按升序排列的结果链表。

 

示例 1：


输入：head = [1,1,2]
输出：[1,2]
示例 2：


输入：head = [1,1,2,3,3]
输出：[1,2,3]
 

提示：

链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序排列
通过次数206,217提交次数392,048

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
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
    if(!head)
    {
        return head; // 返回head而不是null，因为一个节点的话，不能返回null
    }
    ListNode* curr = head;
    while(curr->next)
    {
        if(curr->val == curr->next->val)
        {
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }   
    }
    return head;
}

// 这道题和昨天的不一样之处在于 这道题要保留一个，昨天无需保留；如果保留的话，可以直接指向当前节点然后改变next即可；但如果删除的话，则需要准备pre节点保存上一个节点

// 昨天那道题使用了dummy，就是因为要删除节点，所以需要提前预判next的值；即pre指向的是不重复的节点，prenext直接飞到了下一个不重复的节点；

// 而今天这个题，不需要全都删除，只需要从重复的第一个节点开始，一直判断，把next飞到下一个不重复的节点为止。