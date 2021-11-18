/*
给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。

 

示例 1：



输入：root = [1,null,3,2,4,null,5,6]
输出：3
示例 2：



输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：5
 

提示：

树的深度不会超过 1000 。
树的节点数目位于 [0, 104] 之间。
通过次数67,889提交次数92,777

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree
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

int maxDepth(Node* root) 
{
    if(root == nullptr)
    {
        return 0;
    }
    int maxn = 1; // 当是最后一层子结点时，这个取1就代表一个默认的1层
    for(auto& child : root->children)
    {
        maxn = max(maxn, 1 + maxDepth(child)); // 遍历每个节点然后取最大的，最直接的思路
    }
    return maxn;
}

// 直接dfs即可，做过一遍居然没想起来
// 这种题建议可以面试多做几遍，其实也有BFS的解法，或者DFS不用递归而是用迭代+栈的方法去写