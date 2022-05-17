/*
给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。

 

示例 1：


输入：root = [4,2,7,1,3], val = 5
输出：[4,2,7,1,3,5]
解释：另一个满足题目要求可以通过的树是：

示例 2：

输入：root = [40,20,60,10,30,50,70], val = 25
输出：[40,20,60,10,30,50,70,null,null,25]
示例 3：

输入：root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
输出：[4,2,7,1,3,5]
 

提示：

树中的节点数将在 [0, 104]的范围内。
-108 <= Node.val <= 108
所有值 Node.val 是 独一无二 的。
-108 <= val <= 108
保证 val 在原始BST中不存在。
通过次数123,142提交次数171,243

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/insert-into-a-binary-search-tree
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

TreeNode* insertIntoBST(TreeNode* root, int val) 
{
    if(root == nullptr)
    {
        return new TreeNode(val);
    }
    if(root->val > val)
    {
        root->left = insertIntoBST(root->left, val); // 因为要原地修改, 所以肯定是需要一个返回值来更新
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}


// 700题是关于寻找的, 这一题701是关于插入的, 那么本质也就是寻找然后加进去

// 寻找本身不难, 依然是BST二分

// 加进去怎么搞捏? 当我们不断地递归找到了某个子树势力范围内可以放这个val的时候, 这个val一定是被放在叶子节点最好的

// (当然你也可以实现一个堆来动态排序)

// 如果是叶子节点的话, 岂不是先得是null才能是叶子节点? 因此, 加的操作就是, 当一个节点为nullptr的时候, 把这个节点接上去

// 其余情况就是二分递归