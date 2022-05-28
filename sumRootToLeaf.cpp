/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int res;
void traverse(TreeNode* node, int val)
{
    if(node == nullptr)
    {
        return;
    }
    val = val * 2 + node->val;
    if(node->left == nullptr && node->right == nullptr)
    {
        res += val;
    }
    traverse(node->left, val);
    traverse(node->right, val);
}

int sumRootToLeaf(TreeNode* root) 
{
    res = 0;
    traverse(root, 0);
    return res;
}


// 直接前序遍历累加结果即可，唯一要注意的是，结束条件的判断，如果到结点为空时才去累加，那么叶子结点就会被累加两次