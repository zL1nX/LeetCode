/*
给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。

n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。


示例 1：



输入：root = [1,null,3,2,4,null,5,6]
输出：[1,3,5,6,2,4]
示例 2：



输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：[1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 

提示：

节点总数在范围 [0, 104]内
0 <= Node.val <= 104
n 叉树的高度小于或等于 1000
 

进阶：递归法很简单，你可以使用迭代法完成此题吗?

通过次数106,089提交次数141,206

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal
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
    nodes.push_back(node->val);
    for(auto child : node->children)
    {
        traverse(child, nodes);
    }
}

vector<int> preorder(Node* root) 
{
    vector<int> res;
    traverse(root, res);
    return res;     
}