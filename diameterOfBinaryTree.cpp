/*
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

 

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

 

注意：两结点之间的路径长度是以它们之间边的数目表示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diameter-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxD = 0;

int maxdepth(TreeNode *node)
{
    if(node == nullptr)
    {
        return 0;
    }
    // 问题的分解, 知道左右子树的节点最大深度, 就知道自己这个节点的最长直径
    int leftMax = maxdepth(node->left);
    int rightMax = maxdepth(node->right);
    int curr = leftMax + rightMax;
    maxD = max(maxD, curr);
    return 1 + max(leftMax, rightMax); // 记得返回当前自己的最大深度, 保持函数完整
}

int diameterOfBinaryTree(TreeNode* root) 
{
    maxdepth(root);
    return maxD;
}

// 和最大节点深度很像的一道题, 因为结点直径, 就是左右子树的最大节点深度之和

// 那么这样一来遍历的思路也明确了, 用后序位置, 得到左右子树的最大节点深度之和, 即当前这个节点的最长直径

// 和一个全局变量的最长直径取最大值, 就能得到最长直径了

// 后序位置的经典题目