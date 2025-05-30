#ifndef LAB3_9_H
#define LAB3_9_H

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *CreateNode(int value);
void AddNode(TreeNode *&root, int value);
void AddNodeBST(TreeNode *&root, int value);
void PrintTree(TreeNode *root, int depth = 0);
int CountNodes(TreeNode *root);
TreeNode *FindMin(TreeNode *root);
TreeNode *DeleteNode(TreeNode *root, int value);
TreeNode *DeleteSubtree(TreeNode *root, int value);
void ClearTree(TreeNode *&root);
void TreeToArray(TreeNode *root, int *arr, int &index);
TreeNode *ArrayToBalancedTree(int *arr, int left, int right);
void BalanceTree(TreeNode *&root);

#endif
