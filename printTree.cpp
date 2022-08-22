/*
给你一棵二叉树的根节点 root ，请你构造一个下标从 0 开始、大小为 m x n 的字符串矩阵 res ，用以表示树的 格式化布局 。构造此格式化布局矩阵需要遵循以下规则：

树的 高度 为 height ，矩阵的行数 m 应该等于 height + 1 。
矩阵的列数 n 应该等于 2height+1 - 1 。
根节点 需要放置在 顶行 的 正中间 ，对应位置为 res[0][(n-1)/2] 。
对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，将其左子节点放置在 res[r+1][c-2height-r-1] ，右子节点放置在 res[r+1][c+2height-r-1] 。
继续这一过程，直到树中的所有节点都妥善放置。
任意空单元格都应该包含空字符串 "" 。
返回构造得到的矩阵 res 。

 

 

示例 1：


输入：root = [1,2]
输出：
[["","1",""],
 ["2","",""]]
示例 2：


输入：root = [1,2,3,null,4]
输出：
[["","","","1","","",""],
 ["","2","","","","3",""],
 ["","","4","","","",""]]
 

提示：

树中节点数在范围 [1, 210] 内
-99 <= Node.val <= 99
树的深度在范围 [1, 10] 内
通过次数14,668提交次数23,041

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/print-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <vector>
#include <string>
#include <math.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<vector<string>> printTree(TreeNode* root) 
{
    int m = find_depth(root), n = pow(2, m) - 1;
    vector<vector<string>> res(m, vector<string>(n, ""));
    construct(root, res, m, 0, (n - 1)/2);
    return res;
}

int find_depth(TreeNode* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    return 1 + max(find_depth(node->right), find_depth(node->left));
}

void construct(TreeNode* node, vector<vector<string>>& res, int m, int r, int c)
{
    if(node == nullptr)
    {
        return;
    } // 因为我们的矩阵就是最大限额生成的, 所以肯定不会出现越界的情况
    res[r][c] = to_string(node->val);
    construct(node->left, res, m, r + 1, c - pow(2, m - r - 2));
    construct(node->right, res, m, r + 1, c + pow(2, m - r - 2));
}

// 模拟即可, 题目已经把推导出的位置写出来了, 直接按照题意模拟即可

// 那么就先把树的深度算出来, 然后按DFS前序模拟即可