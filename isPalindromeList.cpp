/*
编写一个函数，检查输入的链表是否是回文的。

 

示例 1：

输入： 1->2
输出： false 
示例 2：

输入： 1->2->2->1
输出： true 
 

进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* left;

bool isPalindrome(ListNode* head) 
{
    left = head;
    return traverse(left);
}

bool traverse(ListNode* right)
{
    if(right == nullptr)
    {
        return true;
    }
    bool lastRes = traverse(right->next);
    lastRes = lastRes && (left->val == right->val);
    left = left->next;
    return lastRes;
}

// 神奇的递归，递归直接导致right节点移到了最后的地方

// 此时，left仍然是第一个节点，对比下left与right就是回文比较开始的地方

// 之后，这一层递归返回上去了，left移到了第二个节点，然而right此时在上一层递归中是倒数第二个节点，那么进行回文的对比

// 以此类推，left每次都会向后移动一个，right在每次递归中都会返回到上一个节点，这样一来就形成了递归

// 真的很巧妙

// 其实，这也体现出了链表是可以后序遍历的