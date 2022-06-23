/*
给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。

 

示例1：



输入: root = [1,3,2,5,3,null,9]
输出: [1,3,9]
示例2：

输入: root = [1,2,3]
输出: [1,3]
 

提示：

二叉树的节点个数的范围是 [0,104]
-231 <= Node.val <= 231 - 1
 

通过次数69,044提交次数104,588

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-largest-value-in-each-tree-row
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> largestValues(TreeNode* root) 
{
    if(root == nullptr) // 无聊不无聊
    {
        return {};
    }
    queue<TreeNode*> q;
    q.push(root);
    vector<int> res;
    while(!q.empty())
    {
        int lsize = q.size(), mmax = INT_MIN; // node值可能有负数
        for(int i = 0; i < lsize; i++)
        {
            TreeNode* node = q.front();
            mmax = max(node->val, mmax);
            q.pop();
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
        res.push_back(mmax);
    }
    return res;
}

// 看完题目应该就能知道最直接的BFS层序遍历找最大值

// 所以就直接写即可