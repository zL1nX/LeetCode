/*
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

 

示例 1：


输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
示例 2：


输入：head = [0,1,2], k = 4
输出：[2,0,1]
 

提示：

链表中节点的数目在范围 [0, 500] 内
-100 <= Node.val <= 100
0 <= k <= 2 * 109
通过次数126,957提交次数310,794

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) 
{
    if(!head)
    {
        return head;
    }
    ListNode *p = head;
    int len = 0;
    while(p->next != nullptr)
    {
        p = p->next;
        len++;
    }
    int rot = len - k % len, count = 0;
    p->next = head;
    for(int i = 0; i < rot;i++)
    {
        p = p->next;
    }
    ListNode *new_list = p->next;
    p->next = nullptr;
    return new_list;
    

}


// 说是循环旋转，但其实本质上是将尾部向前数第K个元素作为头，原来的头接到原来的尾上

