/*
给定一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

 

示例 1：



输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1,2], n = 1
输出：[1]
 

提示：

链表中结点的数目为 sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

进阶：能尝试使用一趟扫描实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/SLwz0R
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    ListNode *fast = head, *slow = head, *prev = head;
    for(int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    while(fast != nullptr)
    {
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }
    if(slow == head) // 这里这个是需要注意的
    {
        head = head->next; // 删除头节点的写法
        return head;
    }
    prev->next = slow->next;
    return head;
}

// 第一眼还以为是要反转链表去了 淦

// 只是删除的话, 直接快慢指针搞定, 但是写的时候有一个技巧用来减少不必要的判断

// 就是时刻保存一个慢指针的前驱节点, 而慢指针本身指向要删除的那个节点, 

// 这样一来如果删除的是头节点, 那么可以直接判断慢指针即可, 就不用考虑其他那些什么空指针怎么写了