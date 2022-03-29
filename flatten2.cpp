/*
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。
 

示例 1：


输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [0]
输出：[0]
 

提示：

树中结点数在范围 [0, 2000] 内
-100 <= Node.val <= 100
 

进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void flatten(TreeNode* root) 
{
    TreeNode *dummy = new TreeNode(-1), *p = dummy;
    construct(root, p);
    root = dummy->right;
    // 返回类型为void, 很难受
    // 我们无法return给外界, 必须让root指向的这个结构发生根本性变换
    // 如果用额外的存储空间, 新建的内存空间无法return回去, 等于没用
    // 所以必须用一种原地的递归或迭代的方法实现
}

void construct(TreeNode* node, TreeNode *p)
{
    if(node == nullptr)
    {
        return;
    }
    p->right = new TreeNode(node->val);
    p->left = nullptr;
    p = p->right;
    construct(node->left, p);
    construct(node->right, p);
}

// 上面这个写法虽然对, 但是因为是void, 没法return回去新建的链表, 所以不可以这么写

// 所以得用下面的写法, 去修改root节点的指针
void flatten(TreeNode* root) 
{
    if(root == nullptr)
    {
        return;
    }
    // 根据flatten的定义, 我们希望是, 能把子树一层一层由下至上的展开, 那么对于一个节点而言
    // 我们肯定希望先把自己的子树处理完毕, 再去考虑上一层的递归
    // 因此这里是后序的递归位置先处理最下面的节点
    flatten(root->left);
    flatten(root->right);

    // 具体的处理方式就是从这里开始, 递归只是一个路径的入口
    // 设置两个新的指针去指向不同的子树 (或者说, 已经flatten过的子树)
    TreeNode *nleft = root->left, *nright = root->right;

    // 将原左子树的指针置空, 然后右子树指向左子树
    root->left = nullptr;
    root->right = nleft;

    // 再走到当前右子树指针的底部 (其实是遍历到左子树的根部)
    TreeNode *p = root;
    while(p->right != nullptr)
    {
        p = p->right;
    }
    // 把原来的右子树接到原来的左子树后边
    p->right = nright;
    // 这种右子树接到左子树的方式, 其实就是题目要求的前序遍历
}

// 一道经典的递归题目

// 考虑一个递归函数的操作是先做完再返回, 还是先返回再做

// 然后除了递归之外的其他地方就是, 如何做这个题的部分

// 最终将题目简化到只有一个单节点时该如何完成, 剩余的由递归来实现即可