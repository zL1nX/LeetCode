/*
给定一个 N 叉树，返回其节点值的后序遍历。

例如，给定一个 3叉树 :

 



 

返回其后序遍历: [5,6,3,2,4,1].

 

说明: 递归法很简单，你可以使用迭代法完成此题吗?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
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

void traverse(Node* node, vector<int>& nodes)
{
    if(node == nullptr)
    {
        return;
    }
    for(int i = 0;i < node->children.size(); i++)
    {
        traverse(node->children[i], nodes);
    }
    nodes.push_back(node->val);
}

vector<int> postorder(Node* root) 
{
    if(root == nullptr)
    {
        return {};
    }  
    vector<int> nodes;
    traverse(root, nodes);
    return nodes;
}