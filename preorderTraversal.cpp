/*
给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
using namespace std;

vector<int> nodes;
void traverse(TreeNode* node)
{
    if(node == nullptr)
    {
        return;
    }
    nodes.push_back(node->val);
    traverse(node->left);
    traverse(node->right);

}
vector<int> preorderTraversal(TreeNode* root) 
{
    traverse(root);
    return nodes;
}