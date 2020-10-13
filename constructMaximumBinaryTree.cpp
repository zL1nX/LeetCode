/*
给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点。

 

示例 ：

输入：[3,2,1,6,0,5]
输出：返回下面这棵树的根节点：

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
 
*/
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* makeTree(int start, int end, vector<int>& nums)
{
    if(start == end)
    {
        return new TreeNode(nums[start]);
    }
    if(start >= end)
    {
        return nullptr;
    }
    int root_index = start;
    for(int i = start + 1; i <= end; i++)
    {
        if(nums[i] > nums[start])
        {
            root_index = i;
        }
    }
    TreeNode* root = new TreeNode(nums[root_index]);
    root->left = makeTree(start, root_index - 1, nums);
    root->right = makeTree(root_index + 1, end, nums);
    return root;
}

// 原先的思路：用迭代器代替下标进行遍历，但问题是迭代器无法表示超出[begin, end]范围的地方，因此当start与end相等的情况执行完毕后，
// 再继续下一步就会发生堆栈溢出。所以用整数索引进行表示是正确且更灵活的方法
TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
{
    TreeNode* root = makeTree(0, nums.size(), nums);
    return root;
}