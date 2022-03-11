/*
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
示例2:

 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]
提示：

链表长度在[0, 20000]范围内。
链表元素在[0, 20000]范围内。
进阶：

如果不得使用临时缓冲区，该怎么解决？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicate-node-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* removeDuplicateNodes(ListNode* head) 
{
    if(head == nullptr)
    {
        return nullptr;
    }
    unordered_map<int, int> rec;
    ListNode *p = head;
    rec[p->val] = 1;
    while(p->next != nullptr)
    {
        ListNode *cur = p->next;
        if(rec[cur->val] == 0)
        {
            p = p->next;
            rec[cur->val] = 1;
        }
        else
        {
            p->next = p->next->next; // 删除cur，是在前一个节点上进行删除

        }
    }
    return head;
}

// 这道题看着简单，写起来还真的非常容易写错

    // 注意头节点为空时直接返回

    // 注意哈希表只要出现了一次其实就算是出现（因此这里判断时就有点trick）

    // 注意删除节点时，必须每次遍历的是next才可以，否则无法实现节点的删除

    // 注意要提前把head节点的值也存下来，这样就不会漏判

// 本质上哈希表去重就可以

// 这道题细节还挺烦，注意可以多写几遍