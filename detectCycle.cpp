/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) 
{
    map<ListNode*, bool> visit;
    if(head == nullptr)
    {
        return nullptr;
    }
    ListNode* p = head;
    while(p && p->next)
    {
        if(visit.size() > 0 && visit.find(p) != visit.end())
        {
            return p;
        }
        else
        {
            visit.insert(pair<ListNode*, bool>(p, true));
        }
        p = p->next;
    }
    return nullptr;
}

/*
ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
        while (head != nullptr) {
            if (visited.count(head)) {
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }

// 其实没必要用map
*/