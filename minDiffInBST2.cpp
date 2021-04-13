/*
给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

注意：本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ 相同

 

示例 1：


输入：root = [4,2,6,1,3]
输出：1
示例 2：


输入：root = [1,0,48,null,null,12,49]
输出：1
 

提示：

树中节点数目在范围 [2, 100] 内
0 <= Node.val <= 105


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void search(vector<int>& vals, TreeNode *node)
{
    if(node==nullptr)
    {
        return;
    }
    search(vals, node->left);
    vals.push_back(node->val);
    search(vals, node->right);
}

int minDiffInBST(TreeNode* root) 
{
    if(root == nullptr)
    {
        return 0;
    }
    vector<int> nodeVals;
    search(nodeVals, root);
    int res = INT_MAX;
    for(int i = 0; i < nodeVals.size() - 1; i++)
    {
        int sub = nodeVals[i + 1] - nodeVals[i];
        if(sub < res)
        {
            res = sub;
        }
    }
    return res;

}

// 利用BST的性质，将其转换为一个升序的vector，这样最小的值肯定某个相邻元素。然后遍历即可。