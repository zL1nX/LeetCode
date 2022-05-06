/*
给定两个整数数组，preorder 和 postorder ，其中 preorder 是一个具有 无重复 值的二叉树的前序遍历，postorder 是同一棵树的后序遍历，重构并返回二叉树。

如果存在多个答案，您可以返回其中 任何 一个。

 

示例 1：



输入：preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
输出：[1,2,3,4,5,6,7]
示例 2:

输入: preorder = [1], postorder = [1]
输出: [1]
 

提示：

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
preorder 中所有值都 不同
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
postorder 中所有值都 不同
保证 preorder 和 postorder 是同一棵二叉树的前序遍历和后序遍历
通过次数23,966提交次数35,476

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<int, int> rec;


TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd)
{
    if(preStart > preEnd)
    {
        return nullptr;
    }
    else if(preStart == preEnd) // 这里的意义在于后面需要取preStart + 1 的元素, 如果相等的话,可以直接判定
    {
        return new TreeNode(preorder[preStart]);
    }
    int rootVal = preorder[preStart], rootLoc = rec[rootVal]; // 套路还是一样的, 先找根节点
    int leftRootVal = preorder[preStart + 1], leftRootLoc = rec[leftRootVal]; // 然后定位到潜在的左子树根节点 (只是潜在的, 可能没有左子树)
    int leftSize = leftRootLoc - postStart + 1; // 整个左子树的节点数量
    
    TreeNode *root = new TreeNode(rootVal);
    root->left = build(preorder, preStart + 1, preStart + leftSize, postorder, postStart, leftRootLoc); // 左子树根节点在后序遍历中, 是处于左子树节点序列中的最后一个位置的
    root->right = build(preorder, preStart + leftSize + 1, preEnd, postorder, leftRootLoc + 1, postEnd);
    return root;

}

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
{
    for(int i = 0; i < postorder.size();i++)
    {
        rec[postorder[i]] = i;
    }
    TreeNode *root = build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    return root;
}