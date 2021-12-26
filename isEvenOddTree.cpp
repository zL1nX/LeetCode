/*
如果一棵二叉树满足下述几个条件，则可以称为 奇偶树 ：

二叉树根节点所在层下标为 0 ，根的子节点所在层下标为 1 ，根的孙节点所在层下标为 2 ，依此类推。
偶数下标 层上的所有节点的值都是 奇 整数，从左到右按顺序 严格递增
奇数下标 层上的所有节点的值都是 偶 整数，从左到右按顺序 严格递减
给你二叉树的根节点，如果二叉树为 奇偶树 ，则返回 true ，否则返回 false 。

 

示例 1：



输入：root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
输出：true
解释：每一层的节点值分别是：
0 层：[1]
1 层：[10,4]
2 层：[3,7,9]
3 层：[12,8,6,2]
由于 0 层和 2 层上的节点值都是奇数且严格递增，而 1 层和 3 层上的节点值都是偶数且严格递减，因此这是一棵奇偶树。
示例 2：



输入：root = [5,4,2,3,3,7]
输出：false
解释：每一层的节点值分别是：
0 层：[5]
1 层：[4,2]
2 层：[3,3,7]
2 层上的节点值不满足严格递增的条件，所以这不是一棵奇偶树。
示例 3：



输入：root = [5,9,1,3,5,7]
输出：false
解释：1 层上的节点值应为偶数。
示例 4：

输入：root = [1]
输出：true
示例 5：

输入：root = [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]
输出：true
 

提示：

树中节点数在范围 [1, 105] 内
1 <= Node.val <= 106
通过次数10,273提交次数18,947

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/even-odd-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isEvenOddTree(TreeNode* root) 
{
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while(!q.empty())
    {
        int size = q.size(), last = level % 2 == 0 ? INT_MIN : INT_MAX;
        for(int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            int value = node->val;
            if(level % 2 == value % 2)
            {
                return false;
            }
            if((level % 2 == 0 && value <= last) || (level % 2 == 1 && value >= last))
            {
                return false;
            }
            last = value;
            if(node->left != nullptr)
            {
                q.push(node->left);
            }
            if(node->right != nullptr)
            {
                q.push(node->right);
            }

        }
        level++;
    }
    return true;
}

// 这道题的题意其实非常清晰，规则比较明确，而且思路上基本就是层序遍历（即BFS）

// 那么这道题的大框架就是一个BFS，即使用一个队列，然后循环出队节点，并将节点的子节点入队

// 那么在出队过程中，就要对其值进行一个判断

// 判断奇偶性与层数之间的关系是否匹配，判断值的大小与前一个节点和层数之间的关系是否匹配

// 第一个条件其实比较好判断，奇偶性相同就return false

// 第二个条件比第一个多了上一个节点的值，这里在处理时，为了能让每一层的第一个节点也比较平滑的实现

// 可以令上一个节点的值初始值为INT_MIN或INT_MAX，这样第一个节点判断时必然是满足条件的

// 其余内容就是往BFS这个框架里填就好了