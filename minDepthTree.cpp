/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。

 

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：2
示例 2：

输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
 

提示：

树中节点数的范围在 [0, 105] 内
-1000 <= Node.val <= 1000
*/

#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int minDepthTree(TreeNode* root) 
{
    if(root == nullptr)
    {
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    int level = 1;

    while(!q.empty())
    {
        int sz = q.size();
        for(int i = 0; i < sz; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left == nullptr && node->right == nullptr)
            {
                return level;
            }
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
        level += 1;
    }
    
    return level;
}