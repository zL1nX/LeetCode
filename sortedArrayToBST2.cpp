/*
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。

高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

 

示例 1：


输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：

示例 2：


输入：nums = [1,3]
输出：[3,1]
解释：[1,3] 和 [3,1] 都是高度平衡二叉搜索树。
 

提示：

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums 按 严格递增 顺序排列
通过次数139,321提交次数186,327

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* construct(vector<int>& nums, int left, int right)
{
    if(left > right) // 注意传入的边界，left==right时其实也是可以的，即构造边界点
    {
        return nullptr;
    }
    int mid = (left + right) / 2; // 每次都取中间的元素作为根节点，这样能保证左右子树的节点数相同，从而递归的保证整棵树是平衡的
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = construct(nums, left, mid - 1);
    root->right = construct(nums, mid + 1, right);
    return root;
}


TreeNode* sortedArrayToBST(vector<int>& nums) 
{
    int n = nums.size();
    return construct(nums, 0, n - 1); // 注意传入的边界
}