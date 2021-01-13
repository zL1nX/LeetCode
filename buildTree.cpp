/*
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int root_idx;
unordered_map<int, int> nodePos;

TreeNode* construct(int left_in, int right_in, vector<int>& inorder, vector<int>& postorder)
{
    if(left_in > right_in)
    {
        return nullptr;
    }
    int root_val = postorder[root_idx]; // 当前子树的根节点（后序的性质）
    TreeNode* root = new TreeNode(root_val);
    int root_pos = nodePos[root_val]; // 找到其在中序排列中的位置
    root_idx --; // 在后序中，每个子树的一系列根节点都在最后放着，因此根节点前面那个节点还是某个子树的根
    root->right = construct(root_pos + 1, right_in, inorder, postorder); // 先从右子树开始，因为刚才递减的根节点位置对应的根节点是右边子树的根节点
    root->left = construct(left_in, root_pos - 1, inorder, postorder);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
    root_idx = (int)postorder.size() - 1;
    int idx = 0;
    for(int i = 0; i < inorder.size(); i++)
    {
        nodePos[inorder[i]] = idx++; // 将中序节点的值与位置对应起来，从而能令后序中的节点直接找到在中序中的位置
    }
    return construct(0, (int)inorder.size() - 1, inorder, postorder);
}

// 用后序寻找根节点，用中序作为递归的基（中序能找到左子树和右子树而后序不能）