/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

 

示例 1：


输入：head = [1,2,3,4]
输出：[2,1,4,3]
示例 2：

输入：head = []
输出：[]
示例 3：

输入：head = [1]
输出：[1]
 

提示：

链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100
通过次数410,447提交次数580,540

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* swapPairs(ListNode* head) 
{
    ListNode *dummy = new ListNode(-1), *cur = dummy;
    dummy->next = head;
    ListNode *a, *b, *lat;
    while(cur->next && cur->next->next)
    {
        // 定义一下这三个指针
        a = cur->next;
        b = cur->next->next;
        lat = b->next;

        // 这四句进行交换, 之间没有很trick的依赖关系
        a->next = lat;
        b->next = a;
        cur->next = b;
        cur = a;
        // 仔细想一下其实很简单
    }
    return dummy->next;
}

// 看起来很吓人, 但是只要静下心来仔细想一下其实就很简单

// 除了很常规的dummy cur之外,记得定义一个新的lat来表示下一段新的节点