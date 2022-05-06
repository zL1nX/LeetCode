/*
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

 

示例 1:


输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
示例 2:

输入: preorder = [-1], inorder = [-1]
输出: [-1]
 

提示:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder 和 inorder 均 无重复 元素
inorder 均出现在 preorder
preorder 保证 为二叉树的前序遍历序列
inorder 保证 为二叉树的中序遍历序列
通过次数349,671提交次数492,289

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<int, int> loc;

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    for(int i = 0; i < inorder.size();i++)
    {
        loc[inorder[i]] = i;
    }
    
    TreeNode *root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    return root;
}


TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd)
{
    if(preStart > preEnd)
    {
        return nullptr;
    }
    int rootVal = preorder[preStart];
    TreeNode *rootNode = new TreeNode(rootVal);
    int rootId = loc[rootVal], leftSize = rootId - inStart; // size of left sub tree
    rootNode->left = build(preorder, preStart + 1, preStart + leftSize , inorder, inStart, rootId - 1);
    rootNode->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, rootId + 1, inEnd);
    return rootNode;
}

// 105-从前序与中序遍历序列构造二叉树
