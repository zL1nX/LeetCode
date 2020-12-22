/*
给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层序遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
    bool turn = true;
    queue<TreeNode*> nodeQue; // 这个是基石，相当于把树的节点进行了一个缓冲，从尾部添加，从头部读取，用size控制下一层的个数
    vector<vector<int>> result;
    if (!root) 
    {
        return result;
    }
    nodeQue.push(root);
    while(!nodeQue.empty())
    {
        int size = nodeQue.size();
        deque<int> level; // 这个很关键，能使我们自由的调整元素添加的相对顺序
        for(int i = 0; i < size; i ++) // 把每个节点的左右孩子都加了进来，size就相当于一层的节点个数
        {
            auto n = nodeQue.front();
            nodeQue.pop();
            if(turn)
            {
                level.push_back(n->val);
            }
            else
            {
                level.push_front(n->val);
            }
            if(n->left)
            {
                nodeQue.push(n->left);
            }
            if(n->right)
            {
                nodeQue.push(n->right);
            }
        }
        result.emplace_back(vector<int>(level.begin(), level.end()));
        turn = !turn;
    }
    return result;
}