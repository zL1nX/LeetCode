/*
给定一个链表的 头节点 head ，请判断其是否为回文链表。

如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。

 

示例 1：



输入: head = [1,2,3,3,2,1]
输出: true
示例 2：



输入: head = [1,2]
输出: false
 

提示：

链表 L 的长度范围为 [1, 105]
0 <= node.val <= 9
 

进阶：能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/aMhZSa
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *left;

bool isPalindrome(ListNode* head) 
{
    left = head;
    bool flag = traveseStep(left);
    return flag;
}

bool traveseStep(ListNode* node)
{
    if(node == nullptr) // 这样最后一个节点开始算的时候先返回一个基础的true
    {
        return true;
    }
    bool thisStep = traveseStep(node->next);
    thisStep = thisStep && (left->val == node->val); // 也是从最后一个节点开始与第一个left开始比
    left = left->next;
    return thisStep;
}