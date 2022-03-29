/*
给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差不超过 1。

 

示例 1:



输入: head = [-10,-3,0,5,9]
输出: [0,-3,9,-10,null,5]
解释: 一个可能的答案是[0，-3,9，-10,null,5]，它表示所示的高度平衡的二叉搜索树。
示例 2:

输入: head = []
输出: []
 

提示:

head 中的节点数在[0, 2 * 104] 范围内
-105 <= Node.val <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree
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

ListNode *cur;

TreeNode* sortedListToBST(ListNode* head) 
{
    int len = 0;
    for(ListNode* p = head; p!= nullptr; p=p->next)
    {
        len++; // 先获取长度, 从而获得中间的节点
    }
    cur = head;
    TreeNode *root = construct(0, len - 1);
    return root;
}

TreeNode* construct(int lid, int rid)
{
    if(lid > rid)
    {
        return nullptr;
    }
    int mid = lid + (rid - lid) / 2; // 得到中间位置, 这样不断递归下去的话, 就可以逐步逼近最左端的节点
    TreeNode *leftTree = construct(lid, mid - 1);
    TreeNode *root = new TreeNode(cur->val);
    cur = cur->next; // 最开始就是从最左边的节点(即第一个节点开始), 这样以中序遍历的顺序构造, 那么必然是BST的样子
    TreeNode *rightTree = construct(mid + 1, rid); // 逐步逼近最右端的节点
    root->left = leftTree;
    root->right = rightTree; // 构造一层新的子树节点
    return root;
}

// 一道理想的中序递归模板题

// 首先题目有两个地方需要注意: BST 高度平衡

// 对于BST, 那么肯定最好的就是在中序遍历过程中新建节点

// 对于高度平衡, 其实就是从最中间的节点作为遍历的起点, 然后每次都进行相同的左右子树递归操作, 那么最终得到的两边子树节点数目肯定是相同的

// (因为是递归, 而递归每次都是从中间开始, 那么必然是平衡的)

// 需要多写几遍, 非常经典