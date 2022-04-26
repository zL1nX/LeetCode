/*
给你 root1 和 root2 这两棵二叉搜索树。请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.

 

示例 1：



输入：root1 = [2,1,4], root2 = [1,0,3]
输出：[0,1,1,2,3,4]
示例 2：



输入：root1 = [1,null,8], root2 = [8,1]
输出：[1,1,8,8]
 

提示：

每棵树的节点数在 [0, 5000] 范围内
-105 <= Node.val <= 105
通过次数21,378提交次数28,034

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees
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

void traverse(TreeNode* node, vector<int>& nodes)
{
    if(node == nullptr)
    {
        return;
    }
    traverse(node->left, nodes);
    nodes.push_back(node->val);
    traverse(node->right, nodes);
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
{
    vector<int> nodes1, nodes2;
    traverse(root1, nodes1);
    traverse(root2, nodes2);
    int m = nodes1.size(), n = nodes2.size();
    int p = 0, q = 0;
    vector<int> res;
    while(p < m && q < n)
    {
        if(nodes1[p] < nodes2[q])
        {
            res.push_back(nodes1[p]);
            p++;
        }
        else
        {
            res.push_back(nodes2[q]);
            q++;
        }
    }
    while(p < m)
    {
        res.push_back(nodes1[p++]);
    }
    while(q < n)
    {
        res.push_back(nodes2[q++]);
    }
    return res;
}


// 一眼中序, 然后归并