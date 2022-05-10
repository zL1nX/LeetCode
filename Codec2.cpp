/*
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

 

示例 1：


输入：root = [1,2,3,null,null,4,5]
输出：[1,2,3,null,null,4,5]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]
示例 4：

输入：root = [1,2]
输出：[1,2]
 

提示：

树中结点数在范围 [0, 104] 内
-1000 <= Node.val <= 1000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/serialize-and-deserialize-binary-tree
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
            stree.append("# ");
            return;
        }
        stree.append(to_string(node->val));
        stree.append(" ");

        traverse(node->left);
        traverse(node->right);
    }

    TreeNode* construct(vector<string>& nodes)
    {
        if(idx >= nodes.size())
        {
            return nullptr;
        }
        string nodeVal = nodes[idx];
        idx += 1;
        if(nodeVal == "#")
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(nodeVal));
        root->left = construct(nodes);
        root->right = construct(nodes);
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
        TreeNode* root = construct(nodes);
        return root;  
    }
};

// 其实本质就是在前序遍历 + 前序构造

// 前序遍历很好理解, 主要是构造. 因为我们用#表示空指针, 因此在遇到#时,就返回nullptr

// 而如何继续往下执行递归呢, 其实这就是交给递归系统来完成, 因为递归时的第一个节点就是根节点, 紧接着的是左节点, 然后是左节点的左节点

// 因此, 可以维护一个全局索引, 每次递归都用这个索引来定位到起始的第一个点, 那么等前序的左子树这半拉到底后, 紧接着的就是最底部的右节点, 这时索引是连续的

// 这也符合我们的递归.