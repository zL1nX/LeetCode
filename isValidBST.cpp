/*
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
 

示例 1：


输入：root = [2,1,3]
输出：true
示例 2：


输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。
 

提示：

树中节点数目范围在[1, 104] 内
-231 <= Node.val <= 231 - 1
通过次数507,337提交次数1,407,434

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/validate-binary-search-tree
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

bool isValid(TreeNode* node, TreeNode* minn, TreeNode* maxn)
{
    if(node == nullptr)
    {
        return true;
    }
    if(minn != nullptr && node->val <= minn->val)
    {
        return false;
    }
    if(maxn != nullptr && node->val >= maxn->val)
    {
        return false;
    }
    return isValid(node->left, minn, node) && isValid(node->right, node, maxn);
}

bool isValidBST(TreeNode* root) 
{
    return isValid(root, nullptr, nullptr);
}

// 加函数签名 maxn与minn来表示当前这个势力范围内, 的最大最小节点

// 没有这一点的话, 可能会直接去判断单个节点的left与right是否符合大小关系, 但这样只对单个节点有效, 对于整个左右子树范围内的大小是没法判断的

// 所以就前序位置, 判断当前节点的合法性, 然后更新maxn和minn(为当前节点), 再去递归的去看左右子树

// 后序位置的话, 在判断单个节点时, 还是需要考虑当前节点在势力范围内是否符合, 递归位置其实不重要