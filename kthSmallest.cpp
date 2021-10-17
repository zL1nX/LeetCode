/*
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。

 

示例 1：


输入：root = [3,1,4,null,2], k = 1
输出：1
示例 2：


输入：root = [5,3,6,2,4,null,null,1], k = 3
输出：3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int kthSmallest(TreeNode* root, int k) 
{
    stack<TreeNode*> s;
    while(root != nullptr || s.size() != 0)
    {
        while(root != nullptr)
        {
            s.push(root);
            root = root->left; // 第一个循环就相当于递归方法的第一句，就一直走到底到最小值
        } // 此时栈中就都是左子树节点的值，栈顶就是最小的那个节点
        root = s.top();
        s.pop();
        k--; // k计数以找到第k小的值
        if(k == 0)
        {
            break;
        }
        root = root->right; // 这一句就相当于递归方法的第三句，因为此时（相对地）中间节点已经pop出去了，按照BST的顺序，接下来稍微大一点的应该是其右子树节点，然后对应到循环开始，就又开始了相当于递归的到底
    }
    return root->val;
}

// 因为题目规定了是二叉搜索树，而BST的中序遍历又是有序的，因此不用遍历整棵树再去排序

// 那么问题就归结到了，如何从小到大的遍历一颗BST；通常，直接递归的中序遍历肯定是可以的，但这样可能会爆栈

// 而循环的方法更好一些（也更适合面试啥的），就是循环遍历BST + k计数即可

// 中间BST的迭代式遍历可能很适合面试