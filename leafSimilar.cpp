/*
请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。



举个例子，如上图所示，给定一棵叶值序列为 (6, 7, 4, 9, 8) 的树。

如果有两棵二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。

如果给定的两个根结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。

 

示例 1：



输入：root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
输出：true
示例 2：

输入：root1 = [1], root2 = [1]
输出：true
示例 3：

输入：root1 = [1], root2 = [2]
输出：false
示例 4：

输入：root1 = [1,2], root2 = [2,2]
输出：true
示例 5：



输入：root1 = [1,2,3], root2 = [1,3,2]
输出：false
 

提示：

给定的两棵树可能会有 1 到 200 个结点。
给定的两棵树上的值介于 0 到 200 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/leaf-similar-trees
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

void get_leaf_node(TreeNode* node, vector<int> leaf)
{
    if(node == nullptr)
    {
        return;
    }
    if(node->left == nullptr && node->right == nullptr)
    {
        leaf.push_back(node->val);
    }
    get_leaf_node(node->left, leaf);
    get_leaf_node(node->right, leaf);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) 
{
    vector<int> leaf1,leaf2;
    get_leaf_node(root1, leaf1);
    get_leaf_node(root2, leaf2);
    if(leaf1.size() != leaf2.size())
    {
        return false;
    }
    for(int i = 0; i < leaf1.size(); i++)
    {
        if(leaf1[i] != leaf2[i])
        {
            return false;
        }
    }
    return true;
}

// 直接做就好，思路就是遍历得到叶子节点数组，然后比较数组是否相等

// 注意取叶子节点时的遍历顺序与判断条件究竟如何，