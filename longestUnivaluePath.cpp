/*
给定一个二叉树的 root ，返回 最长的路径的长度 ，这个路径中的 每个节点具有相同值 。 这条路径可以经过也可以不经过根节点。

两个节点之间的路径长度 由它们之间的边数表示。

 

示例 1:



输入：root = [5,4,5,1,1,5]
输出：2
示例 2:



输入：root = [1,4,5,4,4,5]
输出：2
 

提示:

树的节点数的范围是 [0, 104] 
-1000 <= Node.val <= 1000
树的深度将不超过 1000 
通过次数51,623提交次数112,903

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-univalue-path
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


int maxd = 0;

int longestUnivaluePath(TreeNode* root) 
{
    if(root == nullptr)
    {
        return 0;
    }
    maxdepth(root, root->val);
    return maxd;

}

int maxdepth(TreeNode* node, int parentVal)
{
    if(node == nullptr)
    {
        return 0;
    }
    int leftD = maxdepth(node->left, node->val);
    int rightD = maxdepth(node->right, node->val);
    maxd = max(maxd, leftD + rightD); // 注意这句应该在下面if之前执行
    // 因为此时left和right两条路径的结果都是和node->val相同的, 即确实为有效结果
    // 所以就应该立即更新最终的maxd

    // 而下面的if, 是用来判断, node自己给他的父节点返回时, 是否合法, 因此下面的代码块
    // 是用来收尾整个递归的逻辑, 和上满maxd的计算已经没关系了
    if(node->val != parentVal)
    {
        return 0;
    }
    return 1 + max(leftD, rightD); // 返回node这一支上的最长路径
}   


//687. 最长同值路径

// 与树的最大直径那一题比较像, 但有了附加条件是, 必须节点路径上的值一样

// 而这一点通过后序遍历的技巧可以很妙地解决

// 代码框架依然是最大直径, 但递归是附加一个父节点的值, 从而保证递归上来的这一条路径的值始终多米诺式地和上面保持相等