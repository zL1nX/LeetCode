#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
{
    if(original == target)
    {
        return cloned;
    }
    if(original->left != nullptr)
    {
        TreeNode* p = getTargetCopy(original->left, cloned->left, target);
        if(p != nullptr)
        {
            return p;
        }
    }
    
    if(original->right != nullptr)
    {
        TreeNode* p = getTargetCopy(original->right, cloned->right, target);
        if(p != nullptr)
        {
            return p;
        }
    }
    return nullptr;
}
