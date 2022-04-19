/*
给定两个 非空链表 l1和 l2 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

可以假设除了数字 0 之外，这两个数字都不会以零开头。

 

示例1：



输入：l1 = [7,2,4,3], l2 = [5,6,4]
输出：[7,8,0,7]
示例2：

输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[8,0,7]
示例3：

输入：l1 = [0], l2 = [0]
输出：[0]
 

提示：

链表的长度范围为 [1, 100]
0 <= node.val <= 9
输入数据保证链表代表的数字无前导 0
 

进阶：如果输入链表不能修改该如何处理？换句话说，不能对列表中的节点进行翻转。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lMSNwu
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stack>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    stack<int> s1, s2;
    ListNode *p1 = l1, *p2 = l2;
    for(ListNode *p1 = l1; p1 != nullptr; p1=p1->next) 
    {
        s1.push(p1->val);
    }
    for(ListNode *p2 = l2; p2 != nullptr; p2=p2->next) 
    {
        s2.push(p2->val);
    }
    int flag = 0;
    ListNode *cur = nullptr;
    while(!s1.empty() || !s2.empty() || flag != 0)
    {
        int digit = flag;
        if(!s1.empty())
        {
            digit += s1.top();
            s1.pop();
        }
        if(!s2.empty())
        {
            digit += s2.top();
            s2.pop();
        }
        flag = digit / 10;
        ListNode *node = new ListNode(digit % 10);
        node->next = cur;
        cur = node;
    }
    return cur;
}

// 相当于原有两数相加的反着来的版本

// 既然反着来, 那么就要用到栈这个技术了, 因为栈就是一种反着来的数据结构

// 其他步骤都比较类似, 但最后构建新链表时也要反着来, 要实现这一步, 需要从nullptr空指针开始

// 让新节点的next指向cur (正着来的时候就是cur的next指向当前节点)

// 最后返回cur即可

// 总结, 这个题是两个点: 栈用来实现数字相加, node->next=cur用来实现反向链表