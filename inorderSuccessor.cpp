/*
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。

如果指定节点没有对应的“下一个”节点，则返回null。

示例 1:

输入: root = [2,1,3], p = 1

  2
 / \
1   3

输出: 2
示例 2:

输入: root = [5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /   
1

输出: null
通过次数30,057提交次数50,136

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/successor-lcci
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


TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
{
    int target = p->val;
    TreeNode *prev = nullptr, *cur = root;
    while(cur != nullptr)
    {
        if(cur->val > target) // 只有跑到左子树去遍历时, 才需要考虑更新prev的事情, 因为后继节点一定是个中或者左
        {
            prev = cur;
            cur=cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
    return prev;
}

// 二分搜索的树版本, 不过要注意, 目标节点的后继节点是最近的上层的某个左子树根节点

// 当前节点如果是个左子树节点, 那么就是他的父节点, 如果是个右子树节点, 那么就是他的父节点的父节点

// 所以在递归的时候, 只有当我们要去左子树递归的时候才需要更新prev, 如果targt值太大, 需要去右子树找, 此时是不用更新prev的

