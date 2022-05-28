/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

 

示例 1：


输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
示例 2：


输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
示例 3：

输入：root = [1,2], p = 1, q = 2
输出：1
 

提示：

树中节点数目在范围 [2, 105] 内。
-109 <= Node.val <= 109
所有 Node.val 互不相同 。
p != q
p 和 q 均存在于给定的二叉树中。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    return findNode(root, p->val, q->val);
}

TreeNode* findNode(TreeNode* node, int val1, int val2) 
{
    if(node == nullptr)
    {
        return nullptr;
    }
    if(node->val == val1 || node->val == val2) // 前序位置
    {
        return node;
    }
    
    TreeNode* left = findNode(node->left, val1, val2);
    TreeNode* right = findNode(node->right, val1, val2);
    
    if(left != nullptr && right != nullptr)// 后序位置
    {
        return node;
    }
    return left != nullptr ? left : right; // 注意这块比较精髓，如果有一方为空，那么只返回那个非空的
}

// 第一下还不是太好理解， 这种解法需要分成两个位置去看，前序位置的操作 和 后序位置的操作

// 直觉上，如果左右两个子树递归的能找到相应的节点，即左右递归均不为空，那么说明此时节点是一个祖先节点

// 不过，要保证是最近的祖先，就需要在后序位置进行判断，这也符合这种解法的逻辑，只要后续位置上判定了左右子树有效，那么当前节点就一定是最近的公共祖先

// 另外，对于某个节点本身就是祖先的情况，此时应该直接返回它本身即可。这个时候，另外那个节点会在这个祖先节点的树底下，那么对于上一层递归而言，另外一个子分支的递归一定只能返回null，因为两个节点都在我这个分支下面，此时这个分支返回的结果就是祖先节点本身直接return上来的

// 因此，前序位置保证了，如果真的存在这种一个节点本身就是祖先节点的情况，那么因为在子递归有一方为空的条件下返回那个非空的，就会使得自身的这个节点被一步步返回上去，这下就只等另一个分支了，要是另一个分支也碰上了，那就成前面那种后序的判断了

// 所以，前序位置要执行这种判断来尽早的返回目标节点