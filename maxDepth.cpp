/*
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

例如：

给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

 

提示：

节点总数 <= 10000
注意：本题与主站 104 题相同：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int n): val(n), left(nullptr), right(nullptr){}
};

int traverse(TreeNode* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    return max(traverse(node->left), traverse(node->right)) + 1;
}

int maxDepth(TreeNode* root) 
{
    if(root == nullptr)
    {
        return 0;
    }
    int depth = traverse(root);
    return depth;
}

int maxDepth(TreeNode* root) 
{
    if(root == nullptr)
    {
        return 0;
    }
    queue<TreeNode*> Q;
    Q.push(root);
    int depth = 0;
    while(!Q.empty())
    {
        int size = Q.size();
        while(size > 0)
        {
            TreeNode* node = Q.front();
            Q.pop();
            size -= 1; // 一个父节点被遗弃了
            if(node->left) Q.push(node->left); // 每次把这一层的下面的节点放进来
            if(node->right) Q.push(node->right);
        }
        depth += 1; // 这层的父节点都被遗弃后，层数++
    }
    return depth;
}