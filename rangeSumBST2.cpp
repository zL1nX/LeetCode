/*
给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。

 

示例 1：


输入：root = [10,5,15,3,7,null,18], low = 7, high = 15
输出：32
示例 2：


输入：root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
输出：23
 

提示：

树中节点数目在范围 [1, 2 * 104] 内
1 <= Node.val <= 105
1 <= low <= high <= 105
所有 Node.val 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-of-bst
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

void traverse(TreeNode *node, int& result, int low, int high)
{
    if(node == nullptr)
    {
        return;
    }
    // 可以根据BST的性质进行剪枝，减少递归的层数
    if(node->val < low)
    {
        traverse(node->right, result, low, high);
    }
    else if(node->val > high)
    {
        traverse(node->left, result, low, high);
    }
    else
    {
        result += node->val;
        traverse(node->left, result, low, high);
        traverse(node->right, result, low, high);
    }
    
}

int rangeSumBST(TreeNode* root, int low, int high)
{
    int result = 0;
    // 此处其实可以不单独写一个traverse函数，直接用原来的rangeSumBST也是能写的
    traverse(root, result, low, high);
    return result;
}