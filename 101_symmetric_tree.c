#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool isSymmetric(struct TreeNode* root)
{
    return false;
}
void Print(struct TreeNode* node)
{
    if(node == NULL)
        return;
    printf("%d ",node->val);
    Print(node->left);
    Print(node->right);
}
void construct_tree(struct TreeNode** node)
{
    int value;
    if(scanf("%d",&value) && value == -1);
        return;
    *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    (*node)->val = value;
    printf("left\n");
    construct_tree(&((*node)->left));
    printf("right\n");
    construct_tree(&((*node)->right));

}
int main()
{
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
    construct_tree(&(root));
    Print(root);
    return 0;
}
