/*
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。

 

示例 1:



输入: root = [2,1,3]
输出: 1
示例 2:



输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7
 

提示:

二叉树的节点个数的范围是 [1,104]
-231 <= Node.val <= 231 - 1 
通过次数98,846提交次数134,689

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-bottom-left-tree-value
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

int maxdepth = 0;
int currdepth = 0;
TreeNode* res = nullptr;

int findBottomLeftValue(TreeNode* root) 
{
    traverse(root);
    return res->val;
}

void traverse(TreeNode* node)
{
    if(node == nullptr)
    {
        return;
    }
    currdepth ++; //
    if(maxdepth < currdepth)
    {
        res = node;
        maxdepth = currdepth;
    }
    traverse(node->left); // 继续递归往下走, 先走的左子树, 因此如果碰到了最大, 一定是最左边的节点
    traverse(node->right);
    currdepth--; // 回溯, 防止深度计算错误
}

// 513. 找树左下角的值

// 递归 + 回溯, 就前序的遍历去走到每一个节点, 期间顺便记录下当前节点的深度, 并更新最大深度

// 同时因为dfs完了还要到兄弟级别的节点遍历, 所以要记得回溯
