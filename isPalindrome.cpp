/*
示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

*/
using namespace std;
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) 
{
    if(!head)
    {
        return true;
    }
    int len = 0;
    ListNode* p = head;
    vector<int> nodes;
    for(;p;p=p->next,len++)
    {
        nodes.push_back(p->val);
    }
    if(!len)
    {
        return true;
    }

    for(int i = len/2 - 1, j = (len + 1)/2; i >= 0 && j <= len - 1;i--,j++)
    {
        if(nodes[i]!= nodes[j])
        {
            return false;
        }
    }
    return true;
}