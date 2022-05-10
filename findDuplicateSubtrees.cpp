/*
给定一棵二叉树 root，返回所有重复的子树。

对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

如果两棵树具有相同的结构和相同的结点值，则它们是重复的。

 

示例 1：



输入：root = [1,2,3,4,null,2,4,null,null,4]
输出：[[2,4],[4]]
示例 2：



输入：root = [2,1,1]
输出：[[1]]
示例 3：



输入：root = [2,2,2,3,null,3,null]
输出：[[2,3],[3]]
 

提示：

树中的结点数在[1,10^4]范围内。
-200 <= Node.val <= 200

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-duplicate-subtrees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<string, int> rec;
vector<TreeNode*> res;


vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
{
    res.clear(); rec.clear();
    traverse(root);
    return res;
}

string traverse(TreeNode* node)
{
    if(node == nullptr)
    {
        return "#";
    }
    string leftStr = traverse(node->left);
    string rightStr = traverse(node->right);
    string rootStr = leftStr + "," + rightStr + "," + to_string(node->val); // 序列化
    rec[rootStr] += 1;
    if(rec[rootStr] == 2) // 只要在等于2的时候, 也就是真的是两个重复的时候, 才会将res更新, 否则说明之前已经被加过了
    {
        res.push_back(node);
    }
    return rootStr;
}