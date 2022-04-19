/*
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

 L0 → L1 → … → Ln-1 → Ln 
请将其重新排列后变为：

L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例 1:



输入: head = [1,2,3,4]
输出: [1,4,2,3]
示例 2:



输入: head = [1,2,3,4,5]
输出: [1,5,2,4,3]
 

提示：

链表的长度范围为 [1, 5 * 104]
1 <= node.val <= 1000
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/LGjMqU
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) 
{
    vector<ListNode*> nodes;
    ListNode* p = head;
    while(p != nullptr)
    {
        nodes.push_back(p);
        p = p->next;
    }
    int left = 0, right = nodes.size() - 1;
    while(left < right)
    {
        nodes[left]->next = nodes[right];
        left++; // 这个写法很巧, 可以直接在一次循环里构建好新节点
        nodes[right]->next = nodes[left];
        right--;
    }
    nodes[left]->next = nullptr;
}

// 早说可以用线性表

// 原地直接排, 好像还真不太好写, 又是得找中点, 倒序啥的, 引入一个线性表直接解决

// 注意线性表最后完了的中间那个结点的next得置空