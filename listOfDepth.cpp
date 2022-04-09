/*
给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含所有深度的链表的数组。

 

示例：

输入：[1,2,3,4,5,null,7,8]

        1
       /  \ 
      2    3
     / \    \ 
    4   5    7
   /
  8

输出：[[1],[2,3],[4,5,7],[8]]
通过次数28,337提交次数35,240

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/list-of-depth-lcci
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

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<ListNode*> listOfDepth(TreeNode* tree) 
{
    if(tree == nullptr)
    {
        return {};
    }
    queue<TreeNode*> q;
    q.push(tree);
    vector<ListNode*> res;
    while (!q.empty())
    {
        int levelSize = q.size();
        ListNode* dummy = new ListNode(-1), *p = dummy;
        for(int i = 0; i < levelSize; i++)
        {
            TreeNode *tnode = q.front();
            q.pop();
            ListNode *node = new ListNode(tnode->val);
            p->next = node;
            p = p->next;
            if(tnode->left != nullptr)
            {
                q.push(tnode->left);
            }
            if(tnode->right != nullptr)
            {
                q.push(tnode->right);
            }
        }
        res.push_back(dummy->next);
    }
    return res;
}

// 广度优先遍历, 记得节点判空, 别的直接套模板即可