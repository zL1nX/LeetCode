/*
如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。

只有给定的树是单值二叉树时，才返回 true；否则返回 false。

 

示例 1：



输入：[1,1,1,1,1,null,1]
输出：true
示例 2：



输入：[2,2,2,5,2]
输出：false
 

提示：

给定树的节点数范围是 [1, 100]。
每个节点的值都是整数，范围为 [0, 99] 。
通过次数46,831提交次数66,748

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/univalued-binary-tree
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

bool traverse(TreeNode* node, int val)
{
    if(node == nullptr)
    {
        return true;
    }
    if(node->val != val)
    {
        return false;
    }
    return traverse(node->left, node->val) && traverse(node->right, node->val);
}

bool isUnivalTree(TreeNode* root) 
{
    if(root == nullptr)
    {
        return true;
    }
    return traverse(root->left, root->val) && traverse(root->right, root->val);
}

// 965. 单值二叉树

// 直接遍历去写即可， 用递归来传递参数的值， 有的写法直接写成一个函数的递归

// 倒也不是不行，但是拆成两个函数把val这个参数分离，写起来更简单一些