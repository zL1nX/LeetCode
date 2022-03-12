/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
 

限制：

0 <= 链表长度 <= 10000

通过次数402,978提交次数537,409

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

vector<int> res;

vector<int> reversePrint(ListNode* head) 
{
    traverse(head);
    return res;
}

void traverse(ListNode* node)
{
    if(node == nullptr)
    {
        return;
    }
    traverse(node->next);
    res.push_back(node->val);
}

// 用上午的递归的方法，后序遍历链表