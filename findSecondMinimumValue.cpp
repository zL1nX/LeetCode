/*
给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。

更正式地说，root.val = min(root.left.val, root.right.val) 总成立。

给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。

 

示例 1：


输入：root = [2,2,5,null,null,5,7]
输出：5
解释：最小的值是 2 ，第二小的值是 5 。
示例 2：


输入：root = [2,2,2]
输出：-1
解释：最小的值是 2, 但是不存在第二小的值。
 

提示：

树中节点数目在范围 [1, 25] 内
1 <= Node.val <= 231 - 1
对于树中每个节点 root.val == min(root.left.val, root.right.val)
通过次数30,311提交次数64,959

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverse(TreeNode *node, int target, int& second)
{
    if(node == nullptr)
    {
        return;
    }
    // 这个判断是用于检查second值是否更新，以及后面的节点是否需要继续遍历的
    if(second != -1 && second <= node->val) // 后面这个条件多想想
    {
        return;
    }
    // 一旦符合，就马上更新
    if(node->val > target)
    {
        second = node->val;
    }
    traverse(node->left, target, second);
    traverse(node->right, target, second);

}

int findSecondMinimumValue(TreeNode* root) 
{
    if(root == nullptr)
    {
        return -1;
    }
    int minVal = root->val, second = -1;
    traverse(root, minVal, second);
    return second;
}

// 其实题意很好理解，因为根节点必定是树中的最小值，因此每个节点，都是以这个节点为根的树的最小值

// 题意就是转化为，对树进行遍历，找到第一个严格比根节点值大的值（因为左右子节点必定有一个值等于根节点，因此相当于找到某个子节点的值大于根节点即可）

// 那么遍历时需要注意一些细节：节点为空自然就return；此外，如果当前节点的值大于根节点，那么就更新结果值second

// second初始时可设置为-1；因此遍历时一旦second ！=-1 并且 second值不大于当前节点的值（说明second是当前子树的最小值），那么就返回

// 因为是前序遍历（深度优先），因此找到的值必然是第一个大于根节点的值

// 代码和题解写的基本一样，嘿