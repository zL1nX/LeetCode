/*
105. 从前序与中序遍历序列构造二叉树
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
通过次数142,324提交次数206,921
*/

#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int root_idx = 0;
unordered_map<int, int> nodePos;

TreeNode* construct(int leftin, int rightin, vector<int>& preorder, vector<int>& inorder)
{
    if(leftin > rightin)
    {
        return nullptr;
    }
    int root_val = preorder[root_idx];
    int root_pos = nodePos[root_val];
    TreeNode* root = new TreeNode(root_val);
    root_idx ++;
    root->left = construct(leftin, root_pos - 1, preorder, inorder);
    root->right = construct(root_pos + 1, rightin, preorder, inorder);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    int idx = 0;
    root_idx = 0;
    for(int i = 0; i < inorder.size(); i ++)
    {
        nodePos[inorder[i]] = idx++;
    }
    return construct(0, (int)inorder.size() - 1, preorder, inorder);
}