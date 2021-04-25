/*
给你一棵二叉搜索树，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。

 

示例 1：


输入：root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
示例 2：


输入：root = [5,1,7]
输出：[1,null,5,null,7]
 

提示：

树中节点数的取值范围是 [1, 100]
0 <= Node.val <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/increasing-order-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void collect(TreeNode* node, vector<int>& nodes)
{
    if(node == nullptr)
    {
        return;
    }
    collect(node->left, nodes);
    nodes.push_back(node->val);
    collect(node->right, nodes);
}

TreeNode* construct(vector<int>& nodes)
{
    TreeNode* root = new TreeNode(nodes[0]), *curr = root;
    for(int i = 1; i < nodes.size(); i++)
    {
        TreeNode *next = new TreeNode(nodes[i]);
        curr->right = next;
        curr->left = nullptr;
        curr = next;
    }
    return root;
}
// 其实题意比较好理解，目的就是利用BST的性质得到一系列递增节点，然后用恰当的方式再连接起来

// 此处使用一个中间vector变量存储节点的值，然后for循环新建节点并赋值即可（也可以递归去做）

TreeNode* increasingBST(TreeNode* root)
{
    vector<int> nodes;
    collect(root, nodes);
    TreeNode *new_root = construct(nodes);
    return new_root;
}


