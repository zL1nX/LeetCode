/*
你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。

空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

示例 1:

输入: 二叉树: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

输出: "1(2(4))(3)"

解释: 原本将是“1(2(4)())(3())”，
在你省略所有不必要的空括号对之后，
它将是“1(2(4))(3)”。
示例 2:

输入: 二叉树: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

输出: "1(2()(4))(3)"

解释: 和第一个示例相似，
除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。
通过次数38,286提交次数64,711

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-string-from-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


string tree2str(TreeNode* root) 
{
    if(root == nullptr)
    {
        return "";
    }
    string res = to_string(root->val);
    if(root->right != nullptr || root->left != nullptr)
    {
        res += '(' + tree2str(root->left) + ')';
    }
    if(root->right != nullptr)
    {
        res += '(' + tree2str(root->right) + ')';
    }
    return res;
}

// 整个括号的本质就是: 如果右子树不为空, 那么左子树的节点必然是双括号, 哪怕是空字符串的括号

// 如果右子树为空, 那就不用管


/*
class Solution {
    // 定义：输入以 root 的二叉树，返回描述该二叉树的字符串
    public String tree2str(TreeNode root) {
        // base case
        if (root == null) return "";
        if (root.left == null && root.right == null) {
            return root.val + "";
        }
        // 递归生成左右子树的字符串
        String leftStr = tree2str(root.left);
        String rightStr = tree2str(root.right);

        // 后序遍历代码位置
        // 根据左右子树字符串组装出前序遍历的顺序
        // 按题目要求处理 root 只有一边有子树的情况
        if (root.left != null && root.right == null) {
            // 省略空的右子树
            return root.val + "(" + leftStr + ")";
        }
        if (root.left == null && root.right != null) {
            // 空的左子树不能省略
            return root.val + "()" + "(" + rightStr + ")";
        }
        // 按题目要求处理 root 左右子树都不空的情况
        return root.val + "(" + leftStr + ")" + "(" + rightStr + ")";
    }
}
*/

// 这还有一种解法, 感觉更为直观一些, 即我们只关心自己这个节点发生了什么然后返回, 剩下的交由递归来做