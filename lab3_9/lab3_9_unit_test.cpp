#include "lab3_9.h"
#include <gtest/gtest.h>

TEST(TreeTest, CreateAndCount)
{
    TreeNode *root = nullptr;
    AddNodeBST(root, 10);
    AddNodeBST(root, 5);
    AddNodeBST(root, 15);
    EXPECT_EQ(CountNodes(root), 3);
    ClearTree(root);
}

TEST(TreeTest, DeleteLeaf)
{
    TreeNode *root = nullptr;
    AddNodeBST(root, 10);
    AddNodeBST(root, 5);
    AddNodeBST(root, 15);
    root = DeleteNode(root, 5);
    EXPECT_EQ(CountNodes(root), 2);
    ClearTree(root);
}

TEST(TreeTest, DeleteWithOneChild)
{
    TreeNode *root = nullptr;
    AddNodeBST(root, 10);
    AddNodeBST(root, 5);
    AddNodeBST(root, 2);
    root = DeleteNode(root, 5);
    EXPECT_EQ(CountNodes(root), 2);
    ClearTree(root);
}

TEST(TreeTest, DeleteWithTwoChildren)
{
    TreeNode *root = nullptr;
    AddNodeBST(root, 10);
    AddNodeBST(root, 5);
    AddNodeBST(root, 15);
    AddNodeBST(root, 12);
    AddNodeBST(root, 18);
    root = DeleteNode(root, 15);
    EXPECT_EQ(CountNodes(root), 4);
    ClearTree(root);
}

TEST(TreeTest, ClearTreeTest)
{
    TreeNode *root = nullptr;
    AddNodeBST(root, 1);
    AddNodeBST(root, 2);
    AddNodeBST(root, 3);
    ClearTree(root);
    EXPECT_EQ(root, nullptr);
}

TEST(TreeTest, BalanceTreeTest)
{
    TreeNode *root = nullptr;
    for (int i = 1; i <= 7; ++i)
        AddNodeBST(root, i);
    BalanceTree(root);
    EXPECT_EQ(CountNodes(root), 7);
    ClearTree(root);
}
