/*
给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

 

示例 1：


输入: root = [5,3,6,2,4,null,7], k = 9
输出: true
示例 2：


输入: root = [5,3,6,2,4,null,7], k = 28
输出: false
 

提示:

二叉树的节点个数的范围是  [1, 104].
-104 <= Node.val <= 104
root 为二叉搜索树
-105 <= k <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst
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

bool findTarget(TreeNode* root, int k) 
{
    vector<int> nodes = convert(root);
    int i = 0, j = nodes.size() - 1, sum = 0;
    while(i < j)
    {
        sum = nodes[i] + nodes[j];
        if(sum < k)
        {
            i++;
        }
        else if(sum > k)
        {
            j--;
        }
        else
        {
            return true;
        }
    }
    return false;
}

vector<int> convert(TreeNode* node)
{
    vector<int> res;
    traverse(node, res);
    return res;
}

void traverse(TreeNode* node, vector<int>& res)
{
    if(node == nullptr)
    {
        return;
    }
    traverse(node->left, res);
    res.push_back(node->val);
    traverse(node->right, res);
}

// 最直观的思路: BST中序遍历得到一个有序数组, 然后利用双指针在有序数组里实现two sum

// 但有没有其他方法呢? 感觉大多都是类似的, 无非是可以直接在BST的递归遍历中顺带实现two sum

// 但总归是一道题目模型非常清晰的题, 好像也没别的太神奇的思路