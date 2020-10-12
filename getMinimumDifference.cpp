/*
给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。

 

示例：

输入：

   1
    \
     3
    /
   2

输出：
1

解释：
最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <vector>
#include <math.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> nodes;
void search(TreeNode* node)
{
    if(!node)
    {
        return;
    }
    search(node->left);
    nodes.push_back(node->val);
    search(node->right);
}

int getMinimumDifference(TreeNode* root) 
{
    int diff = INT_MAX;
    search(root);
    for(int i = 0; i < nodes.size() - 1; i++)
    {
        int delta = nodes[i + 1] - nodes[i];
        if(delta < diff)
        {
            diff = delta;
        }
    }
    return diff;
}