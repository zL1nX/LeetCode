/*
序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。

设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。

编码的字符串应尽可能紧凑。

 

示例 1：

输入：root = [2,1,3]
输出：[2,1,3]
示例 2：

输入：root = []
输出：[]
 

提示：

树中节点数范围是 [0, 104]
0 <= Node.val <= 104
题目数据 保证 输入的树是一棵二叉搜索树。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/serialize-and-deserialize-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Codec 
{
private:
    string stree;
    TreeNode* root;
    int idx = 0;
    void traverse(TreeNode* node)
    {
        if(node == nullptr)
        {
            return; // 
        }
        stree.append(to_string(node->val));
        stree.append(" ");

        traverse(node->left);
        traverse(node->right);
    }

    TreeNode* construct(vector<string>& nodes, int minv, int maxv)
    {
        if(idx >= nodes.size())
        {
            return nullptr;
        }
        int nodeVal = stoi(nodes[idx]);
        if(nodeVal > maxv || nodeVal < minv) // 根据BST的性质, 一棵树的节点值是有一个范围的
        {
            return nullptr;
        }
        idx += 1; // 当符合范围时再移动这个id
        TreeNode* root = new TreeNode(nodeVal);
        root->left = construct(nodes, minv, nodeVal); // 左子树的节点值范围
        root->right = construct(nodes, nodeVal, maxv); // 右子树的节点值范围
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        stree = "";
        traverse(root);
        return stree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<string> nodes;
        stringstream ss(data);
        string node = "";
        while(ss >> node)
        {
            nodes.push_back(node);
        }
        TreeNode* root = construct(nodes, INT_MIN, INT_MAX);
        return root;  
    }
};


// 昨天刚写了序列化与反序列化的题, 今天就出了一个二叉树的变种

// 那么昨天的代码肯定也是能用的, 只不过在BST的情境下可以优化

// 不专门设置空指针, 利用BST节点值大小之间的关系判断当前这个value是不是在这个树中
