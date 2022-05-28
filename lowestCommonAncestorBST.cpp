/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */


using namespace std;

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        int val1 = min(p->val, q->val);
        int val2 = max(p->val, q->val);
        return findNode(root, val1, val2);
    }

    TreeNode* findNode(TreeNode *node, int val1, int val2)
    {
        if(node == nullptr)
        {
            return nullptr;
        }
        if(node->val < val1)
        {
            return findNode(node->right, val1, val2);
        }
        if(node->val > val2)
        {
            return findNode(node->left, val1, val2);
        }
        return node;
    }
};


// 235. 二叉搜索树的最近公共祖先

// 显然，直接用原来的代码解决BST的公共祖先，肯定也是可以的，但显然效率不会是最高的

// 根据BST的节点大小的性质可以知道，如果一个节点的大小恰好处于两个查找值的中间，那么从后序遍历的位置上来，这个节点就是满足条件的公共祖先

// 另外，如果当前节点的值均小于val 或均大于val，那么就应该去右子树或左子树去寻找，这就可以用到BST的性质了