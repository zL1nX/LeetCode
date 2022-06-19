/*
给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。

一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。

 

示例 1：



输入: root = [5,2,-3]
输出: [2,-3,4]
示例 2：



输入: root = [5,2,-5]
输出: [2]
 

提示:

节点数在 [1, 104] 范围内
-105 <= Node.val <= 105
通过次数23,031提交次数32,188

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/most-frequent-subtree-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<int, int> rec;

int dfs(TreeNode* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    int sum = node->val + dfs(node->left) + dfs(node->right);
    rec[sum]++;
    return sum;
}

vector<int> findFrequentTreeSum(TreeNode* root) 
{
    dfs(root);
    vector<int> res;
    int mmax = 0;
    for(auto& [key, val] : rec)
    {
        if(val >= mmax) // 说明要么更新最大值,  要么新加元素
        {
            if(val > mmax)
            {
                res.clear(); // 更新最大值
                mmax = val;
            }
            res.push_back(key);
        }
    }
    return res;
}

// 508-出现次数最多的子树元素和

// 只要掌握了树的遍历套路, 思路应该一下就能写出来, 就是遍历+哈希表即可