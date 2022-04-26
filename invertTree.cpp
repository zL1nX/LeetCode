/*



输入：root = [2,1,3]
输出：[2,3,1]
示例 3：

输入：root = []
输出：[]
 

提示：

树中节点数目范围在 [0, 100] 内
-100 <= Node.val <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/invert-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root) 
{
    if(root == nullptr)
    {
        return nullptr;
    }
    TreeNode* nleft = invertTree(root->left);
    TreeNode* nright = invertTree(root->right);
    root->left = nright;
    root->right = nleft;
    return root;
}

// 这个题两种思路都可以, 不论哪一种, 归结到一个节点上

// 都是要把节点的左右子树交换, 然后再去交换别的节点, 再去交换的方向可以向上也可以向下

// 向上就是分解, 向下就是遍历

// 即只用调整交换子树这一操作是在前序位置还是后序位置即可