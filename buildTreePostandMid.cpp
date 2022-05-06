/*
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

 

示例 1:


输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7]
示例 2:

输入：inorder = [-1], postorder = [-1]
输出：[-1]
 

提示:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder 和 postorder 都由 不同 的值组成
postorder 中每一个值都在 inorder 中
inorder 保证是树的中序遍历
postorder 保证是树的后序遍历
通过次数190,671提交次数263,478

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
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

unordered_map<int, int> rec;

TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd)
{
    if(postStart > postEnd)
    {
        return nullptr;
    }
    int rootVal = postorder[postEnd], rootLoc = rec[rootVal];
    int leftSize = rootLoc - inStart;
    TreeNode *root = new TreeNode(rootVal);
    root->left = build(inorder, inStart, rootLoc - 1, postorder, postStart, postStart + leftSize - 1);
    root->right = build(inorder, rootLoc + 1, inEnd, postorder, postStart + leftSize, postEnd - 1);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
    for(int i = 0; i < inorder.size(); i++)
    {
        rec[inorder[i]] = i;
    }
    TreeNode *root = build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    return root;
}

// 106-从中序与后序遍历序列构造二叉树