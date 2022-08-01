/*
给你一个二叉树的根节点 root。设根节点位于二叉树的第 1 层，而根节点的子节点位于第 2 层，依此类推。

请返回层内元素之和 最大 的那几层（可能只有一层）的层号，并返回其中 最小 的那个。

 

示例 1：



输入：root = [1,7,0,7,-8,null,null]
输出：2
解释：
第 1 层各元素之和为 1，
第 2 层各元素之和为 7 + 0 = 7，
第 3 层各元素之和为 7 + -8 = -1，
所以我们返回第 2 层的层号，它的层内元素之和最大。
示例 2：

输入：root = [989,null,10250,98693,-89388,null,null,null,-32127]
输出：2
 

提示：

树中的节点数在 [1, 104]范围内
-105 <= Node.val <= 105
通过次数25,511提交次数38,619

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <queue>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxLevelSum(TreeNode* root) 
{
    if(root == nullptr)
    {
        return 0;
    }
    int mmax = INT_MIN, res = 0, level = 1; // 树的元素可能全为负, 我真的谢
    deque<TreeNode*> q;
    q.push_back(root);
    while(!q.empty())
    {
        int sum = 0, num = q.size();
        for(int i = 0; i < num; i++)
        {
            TreeNode *node = q.front();
            q.pop_front();
            if(node->left != nullptr) q.push_back(node->left);
            if(node->right != nullptr) q.push_back(node->right);
            sum += node->val;

        }
        if(sum > mmax)
        {
            mmax = sum;
            res = level;
        }
        level++;
    }
    return res;

}


// 1161. 最大层内元素和

// 套路就是非常传统的BFS记录结果, 整体代码没有太多要注意的

// 唯一一个坑点就是树的元素可能全都是负数, 因此最大值的那个结果要设置成最小值, 而不能设置成0