/*
给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。

示例:
给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

          0 
         / \ 
       -3   9 
       /   / 
     -10  5 
通过次数23,497提交次数29,631

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-height-tree-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* construct(vector<int>& nums, int begin , int end)
    {
        if(begin <= end)
        {
            int mid = (begin + end) / 2;
            TreeNode* new_root = new TreeNode(nums[mid]);
            new_root->left = construct(nums, begin, mid - 1);
            new_root->right = construct(nums, mid + 1, end);
            return new_root;
        }
        return NULL;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        int n = nums.size();
        if(!n)
        {
            return NULL;
        }
        return construct(nums, 0, n - 1);
    }

// 本质上就是不断找根节点就行，BST的核心就是根节点