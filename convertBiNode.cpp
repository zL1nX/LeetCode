/*
二叉树数据结构TreeNode可用来表示单向链表（其中left置空，right为下一个链表节点）。实现一个方法，把二叉搜索树转换为单向链表，要求依然符合二叉搜索树的性质，转换操作应是原址的，也就是在原始的二叉搜索树上直接修改。

返回转换后的单向链表的头节点。

注意：本题相对原题稍作改动

 

示例：

输入： [4,2,5,1,3,null,6,0]
输出： [0,null,1,null,2,null,3,null,4,null,5,null,6]
提示：

节点数量不会超过 100000。
通过次数24,471提交次数38,538

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binode-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *cur = nullptr, *head = nullptr;

TreeNode* convertBiNode(TreeNode* root) 
{
    head = new TreeNode(-1);
    cur = head;
    traverse(root);
    return head->right;
}

void traverse(TreeNode* node)
{
    if(!node)
    {
        return;
    }
    traverse(node->left);
    node->left = nullptr; // 否则最后一个节点的left没被考虑进去, 如果是cur的话, 每次都只是上一个节点的left被置空了
    cur->right = node;
    cur = node;
    traverse(node->right);
}
// 这个题感觉就没表示清楚要做什么

// 应该是, 现有一颗BST, 请按照节点值升序的规则, 将BST原地修改为一个单向链表. 其中原地修改指的是, 将left置为空, right指向下一个节点处

// 这样一来就清楚很多了, 那我们的工作就是对BST中序遍历, 然后修改left与right指针即可

// 那么核心的遍历函数就是一个中序的递归, 在递归的中间, 将当前node节点的left置为空, 然后用上一个节点的right指向当前node节点

