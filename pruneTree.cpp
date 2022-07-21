/*
给你二叉树的根结点 root ，此外树的每个结点的值要么是 0 ，要么是 1 。

返回移除了所有不包含 1 的子树的原二叉树。

节点 node 的子树为 node 本身加上所有 node 的后代。

 

示例 1：


输入：root = [1,null,0,0,1]
输出：[1,null,0,null,1]
解释：
只有红色节点满足条件“所有不包含 1 的子树”。 右图为返回的答案。
示例 2：


输入：root = [1,0,1,0,0,0,1]
输出：[1,null,1,null,1]
示例 3：


输入：root = [1,1,0,1,1,0,1,0]
输出：[1,1,0,1,1,null,1]
 

提示：

树中节点的数目在范围 [1, 200] 内
Node.val 为 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/binary-tree-pruning
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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


TreeNode* pruneTree(TreeNode* root) 
{
    if(root == nullptr)
    {
        return nullptr;
    }
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if(root->val == 0 && root->left == nullptr && root->right == nullptr)
    {
        return nullptr;
    }
    return root;
}

// 挺有意思的一道题, 做的时候本质就是在想, 究竟是后序还是先序

// 如果是后序的话, 就是子树的子问题解决了, 我当前这个节点该怎么解决

// 因此, 如果直接用原函数的话, 就是子树如果都被剪枝剪没了, 只要我自己也是0, 那我自己也没了

// 那就直接返回nullptr

// 树的后序, 以及子问题的刻画