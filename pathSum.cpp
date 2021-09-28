/*
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

 

示例 1：



输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。
示例 2：

输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：3
 

提示:

二叉树的节点个数的范围是 [0,1000]
-109 <= Node.val <= 109 
-1000 <= targetSum <= 1000 
通过次数103,223提交次数181,491


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-iii
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

void search(TreeNode *node, int currentSum, int target, int& count)
{
    if(currentSum == target)
    {
        count++;
    }
    if(node->left) search(node->left, currentSum + node->left->val, target, count); // dfs内的这个dfs就是每次都会累加值，即传统的搜索
    if(node->right) search(node->right, currentSum + node->right->val, target, count);
}

void dfs(TreeNode *node, int target, int& count)
{
    if(node == nullptr)
    {
        return;
    }
    search(node, node->val, count, target); // 注意此处是从node->val开始累加的，也就是search函数时从起点开始搜索
    dfs(node->left, count, target);  // 然后继续dfs，每次dfs内都会对search开始，即又已当前节点为起点开始搜索
    dfs(node->right, count, target);
    
}

int pathSum(TreeNode* root, int targetSum) 
{
    int res = 0, sum = 0;
    dfs(root, targetSum, res);
    return res;
}

// 暴力解法就是dfs内套一个dfs，外层dfs用来对每个节点开启搜索，内层的dfs用来从当前节点开始，查找路径和为target的数目