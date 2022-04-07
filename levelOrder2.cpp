/*
给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。

树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。

 

示例 1：



输入：root = [1,null,3,2,4,null,5,6]
输出：[[1],[3,2,4],[5,6]]
示例 2：



输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
 

提示：

树的高度不会超过 1000
树的节点总数在 [0, 10^4] 之间
通过次数84,126提交次数117,190

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


vector<vector<int>> levelOrder(Node* root) 
{
    queue<Node*> q;
    if(root == nullptr)
    {
        return {}; // 我真的是服了
    }
    q.push(root);
    vector<vector<int>> res;
    while(!q.empty())
    {
        int levelSize = q.size();
        vector<int> levelNodes;
        for(int i = 0; i < levelSize; i++)
        {
            Node *curr = q.front(); // 由于是队列, 所以记得是front
            q.pop();
            levelNodes.push_back(curr->val);
            for(Node* n : curr->children)
            {
                q.push(n);
            }
        }
        res.push_back(levelNodes);
    }
    return res;
}

// 一看到层序遍历,就要想到BFS的模板

// 更进一步地, 要想到当前队列中元素的数目, 就是这一层BFS的节点数目 (以此来进行二维数组的分割)

// 别的就是直接按照模板框架写即可