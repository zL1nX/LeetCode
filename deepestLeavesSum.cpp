/*
给你一棵二叉树的根节点 root ，请你返回 层数最深的叶子节点的和 。

 

示例 1：



输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
输出：15
示例 2：

输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
输出：19
 

提示：

树中节点数目在范围 [1, 104] 之间。
1 <= Node.val <= 100
通过次数31,150提交次数37,013

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/deepest-leaves-sum
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

int maxLevel = -1; // 这样第0层的root可以算上
int sum = 0;

int deepestLeavesSum(TreeNode* root) 
{
    dp(root, 0);
    return sum;   
}

void dp(TreeNode* node, int level)
{
    if(node == nullptr)
    {
        return;
    }
    if(level > maxLevel)
    {
        sum = node->val;
        maxLevel = level;
    }
    else if(level == maxLevel)
    {
        sum += node->val;
    }
    dp(node->left, level + 1);
    dp(node->right, level + 1);
    return;
}

// 如果用BFS那就是最后一层的累加

// 用DFS的话, 那就是维护一个maxLevel, 这样同样是只有最深的递归的节点值才会被算上