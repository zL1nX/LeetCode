/*
请实现两个函数，分别用来序列化和反序列化二叉树。

你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

 

示例：


输入：root = [1,2,3,null,null,4,5]
输出：[1,2,3,null,null,4,5]
 

注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
        {
            return "";
        }
        queue<TreeNode*> q;
        q.push(root);
        string res = "";
        while(!q.empty())
        {
            TreeNode* curr = q.front(); q.pop();
            if(curr)
            {
                res += to_string(curr->val) + " ";
                q.push(curr->left);
                q.push(curr->right);
            }
            else
            {
                res += "null ";
            }
        }
        res.pop_back(); // last space
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        stringstream ss(data);
        string nodeval;
        vector<string> nodes;
        queue<TreeNode*> q;
        while(ss >> nodeval) {
            nodes.push_back(nodeval);
        }
        TreeNode* root = new TreeNode(atoi(nodes[0].c_str()));
        q.push(root);
        int ind = 1;
        while(!q.empty())
        {
            TreeNode* curr = q.front(); q.pop();
            if(nodes[ind] != "null")
            {
                curr->left = new TreeNode(atoi(nodes[ind].c_str()));
                q.push(curr->left);
            }
            ind += 1;
            if(nodes[ind] != "null")
            {
                curr->right = new TreeNode(atoi(nodes[ind].c_str()));
                q.push(curr->right);
            }
            ind += 1;
        }
        return root;
    }
};

// 就 全是BFS

// 序列化的时候注意res中的格式什么

// 反序列化的时候注意queue的作用（节点暂存），以及如何将queue与vector联动（ind）

// 感觉可以作为一道挺经典的面试题