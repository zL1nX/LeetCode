/*
实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

注意：本题相对原题稍作改动

示例：

输入： 1->2->3->4->5 和 k = 2
输出： 4
说明：

给定的 k 保证是有效的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int kthToLast(ListNode* head, int k) 
{
    ListNode *p1 = head;
    for(int i = 0; i < k; i++)
    {
        p1 = p1->next;
    }
    ListNode* p2 = head;
    while(p1 != nullptr)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2->val;
}

// 双指针的思路,非常直观,一个先走k步,另一个再走

// 这一题和找到链表中点是类似的,也是两个快慢指针,只不过那一题是快指针比慢指针多走一步

// 本来想着能不能用链表后序遍历,然后在递归退栈的时候进行k的计数,但发现这种好难写