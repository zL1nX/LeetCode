/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

 

示例 1：

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
 

限制：

0 <= 节点个数 <= 1000

注意：本题与主站 226 题相同：https://leetcode-cn.com/problems/invert-binary-tree/



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int n): val(n), left(nullptr), right(nullptr){}
};

void TreeSwap(TreeNode* node)
{
    if(node == nullptr)
    {
        return;
    }
    TreeNode* temp = node->left; // 直接交换节点而非仅交换节点的值
    node->left = node->right; // 包含了左或右节点为空的情况
    node->right = temp;
    TreeSwap(node->left); // 递归进入下一层
    TreeSwap(node->right);
}

TreeNode* mirrorTree(TreeNode* root) 
{
    if(!root)
    {
        return nullptr;
    }
    TreeSwap(root);
    return root;
}