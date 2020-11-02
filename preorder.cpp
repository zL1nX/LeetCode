/*
给定一个 N 叉树，返回其节点值的前序遍历。

例如，给定一个 3叉树 :


 

返回其前序遍历: [1,3,5,6,2,4]。

 

说明: 递归法很简单，你可以使用迭代法完成此题吗?

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

vector<int> result;
void traverse(Node* node)
{
    if(!node)
    {
        return;
    }
    result.push_back(node->val);
    for(Node* chd : node->children)
    {
        traverse(chd);
    }
}

vector<int> preorder(Node* root) 
{
    if(!root)
    {
        return vector<int>();
    }  
    traverse(root);
    return result;
}

/*
迭代法计算，维护一个栈，节点入栈后，子节点逆序入栈，栈顶是第一个要被遍历的元素，然后循环把每个节点这么加入进去，之后再逐个pop即可
class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        if root is None:
            return []
        
        stack, output = [root, ], []            
        while stack:
            root = stack.pop()
            output.append(root.val)
            stack.extend(root.children[::-1])
                
        return output
*/
