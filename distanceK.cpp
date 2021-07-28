/*
给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 K 。

返回到目标结点 target 距离为 K 的所有结点的值的列表。 答案可以以任何顺序返回。

 

示例 1：

输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
输出：[7,4,1]
解释：
所求结点为与目标结点（值为 5）距离为 2 的结点，
值分别为 7，4，以及 1



注意，输入的 "root" 和 "target" 实际上是树上的结点。
上面的输入仅仅是对这些对象进行了序列化描述。
 

提示：

给定的树是非空的。
树上的每个结点都具有唯一的值 0 <= node.val <= 500 。
目标结点 target 是树上的结点。
0 <= K <= 1000.
通过次数18,470提交次数32,257

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

unordered_map<int, TreeNode*> parents;
vector<int> ans;

// 父子局反转（树的话，从父到子容易，因此哈希表用来从子到父
void StoreParents(TreeNode *node)
{
    if(node->left != nullptr)
    {
        parents[node->left->val] = node;
        StoreParents(node->left);
    }
    if(node->right != nullptr)
    {
        parents[node->right->val] = node;
        StoreParents(node->right);
    }
}

void findKNode(TreeNode* node, TreeNode* from, int depth, int k)
{
    if(node == nullptr)
    {
        return;
    }
    if(depth == k)
    {
        ans.push_back(node->val);
        return;
    }
    if(node->left != from)
    {
        findKNode(node->left, node, depth + 1, k); 
    }
    if(node->right != from)
    {
        findKNode(node->right, node, depth + 1, k);
    }
    if(parents[node->val] != from)
    {
        findKNode(parents[node->val], node, depth + 1, k); // node father
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
{
    StoreParents(root);
    findKNode(target, nullptr, 0, k); // from target begins
    return ans;
}

// 人已经累麻了

// 从target开始搜素 + 可以用哈希表