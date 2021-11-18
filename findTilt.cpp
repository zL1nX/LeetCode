/*
给定一个二叉树，计算 整个树 的坡度 。

一个树的 节点的坡度 定义即为，该节点左子树的节点之和和右子树节点之和的 差的绝对值 。如果没有左子树的话，左子树的节点之和为 0 ；没有右子树的话也是一样。空结点的坡度是 0 。

整个树 的坡度就是其所有节点的坡度之和。

 

示例 1：


输入：root = [1,2,3]
输出：1
解释：
节点 2 的坡度：|0-0| = 0（没有子节点）
节点 3 的坡度：|0-0| = 0（没有子节点）
节点 1 的坡度：|2-3| = 1（左子树就是左子节点，所以和是 2 ；右子树就是右子节点，所以和是 3 ）
坡度总和：0 + 0 + 1 = 1
示例 2：


输入：root = [4,2,9,3,5,null,7]
输出：15
解释：
节点 3 的坡度：|0-0| = 0（没有子节点）
节点 5 的坡度：|0-0| = 0（没有子节点）
节点 7 的坡度：|0-0| = 0（没有子节点）
节点 2 的坡度：|3-5| = 2（左子树就是左子节点，所以和是 3 ；右子树就是右子节点，所以和是 5 ）
节点 9 的坡度：|0-7| = 7（没有左子树，所以和是 0 ；右子树正好是右子节点，所以和是 7 ）
节点 4 的坡度：|(3+5+2)-(9+7)| = |10-16| = 6（左子树值为 3、5 和 2 ，和是 10 ；右子树值为 9 和 7 ，和是 16 ）
坡度总和：0 + 0 + 0 + 2 + 7 + 6 = 15
示例 3：


输入：root = [21,7,14,1,1,2,2,3,3]
输出：9
 

提示：

树中节点数目的范围在 [0, 104] 内
-1000 <= Node.val <= 1000
通过次数39,827提交次数63,573

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-tilt
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <math.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int traverse(TreeNode *node)
{
    if(node == nullptr) return 0;
    return traverse(node->left) + traverse(node->right) + node->val;    
}

int findTilt(TreeNode* root) 
{
    if(root == nullptr) return 0;
    return findTilt(root->left) + findTilt(root->right) + abs(traverse(root->left) - traverse(root->right));
}

// 这道题中暗含了两个递归：坡度的递归 + 求和的递归

// 关键的转化在于：一棵树的坡度等价于这样的递归：一个节点自己左子树节点的坡度 + 右自己树节点的坡度 + 自己这个点的坡度

// 因为这样递归后就相当于对所有节点的坡度求和

// 另外，还需要对节点的值求和，这个思路也是一样的，即等价于这样的递归：一个节点自己左子树求和 + 右子树求和 + 自己的val值

// 这样就可以求出 包括这个节点在内的值求和

// 代码精悍，但这么写出来其实非常美，可以多写写

// 诚然，其实有一种单递归的写法（也是我最开始想这么写的）

/*
class Solution {
   int res;

    public int findTilt(TreeNode root) {
        res = 0;
        sum(root);
        return res;
    }

    private int sum(TreeNode node) {
        if (node == null) {
            return 0;
        }
        int sumLeft = sum(node.left);
        int sumRight = sum(node.right);
        res += Math.abs(sumLeft - sumRight); // 全局变量累加得到坡度
        return node.val + sumLeft + sumRight; // sum只返回节点的值累加和
    }
}
*/