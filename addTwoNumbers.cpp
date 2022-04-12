/*
给定两个用链表表示的整数，每个节点包含一个数位。

这些数位是反向存放的，也就是个位排在链表首部。

编写函数对这两个整数求和，并用链表形式返回结果。

 

示例：

输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
输出：2 -> 1 -> 9，即912
进阶：思考一下，假设这些数位是正向存放的，又该如何解决呢?

示例：

输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
输出：9 -> 1 -> 2，即912
通过次数46,886提交次数100,582

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-lists-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode *p = l1, *q = l2, *dummy = new ListNode(-1), *nList = dummy;
    int flag = 0;
    while(p != nullptr || q != nullptr || flag != 0)
    {
        int cur = flag;
        if(p != nullptr)
        {
            cur += p->val;
            p = p->next;
        }
        if(q != nullptr)
        {
            cur += q->val;
            q = q->next;
        }
        nList->next = new ListNode(cur % 10);
        nList = nList->next;
        flag = cur / 10;
    }
    return dummy->next;
}

// 逐位加法运算的典型例子, 只不过是以链表形式

// 设置两个指针, 分别指向两个链表, 再设置一个进位, 然后类似于合并链表那样逐个操作即可