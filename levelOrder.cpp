/*
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层序遍历结果：

[
  [3],
  [9,20],
  [15,7]
]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
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


vector<vector<int>> levelOrder(TreeNode* root) 
{
    vector<vector<int>> result;
    queue<TreeNode*> nodeQue;
    if(!root)
    {
        return result;
    }
    nodeQue.push(root);
    while(!nodeQue.empty())
    {
        vector<int> level;
        int size = nodeQue.size(); // 这是必须的，否则size是动态变化的；
        for(int i = 0; i < size; i++)
        {
            auto node = nodeQue.front();
            nodeQue.pop();
            level.push_back(node->val);
            if(node->left)
            {
                nodeQue.push(node->left);
            }
            if(node->right)
            {
                nodeQue.push(node->right);
            }
        }  
        result.push_back(level);   
    }
    return result;
    
        
}