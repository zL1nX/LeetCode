/*
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

 

示例 1：

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
示例 2：

输入：lists = []
输出：[]
示例 3：

输入：lists = [[]]
输出：[]
 

提示：

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4
通过次数423,126提交次数746,518

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    ListNode *dummy = new ListNode(0), *cur = dummy;
    auto cmp = [](ListNode* a, ListNode *b)
    {
        return a->val > b->val; // 注意这里是> , 和一般的compare刚好相反
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    for(int i = 0; i < lists.size(); i++)
    {
        if(lists[i] != nullptr)
        {
            pq.push(lists[i]);
        }
    }
    // 剩下的就是优先队列的事情了
    while(!pq.empty())
    {
        ListNode* node = pq.top();
        cur->next = node;
        pq.pop();
        if(node->next != nullptr)
        {
            pq.push(node->next);
        }
        cur = cur->next;
    }
    return dummy->next;
}