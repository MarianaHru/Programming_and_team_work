#include "lab3_8.h"
#include <gtest/gtest.h>

TEST(Lab3_8Test, CreateCircularList)
{
    int arr[] = {1, 2, 3};
    Node *head = createCircularListFromArray(arr, 3);
    ASSERT_NE(head, nullptr);
    EXPECT_EQ(countNodes(head), 3);
    freeCircularList(head);
}

TEST(Lab3_8Test, HasEqualNext_True)
{
    int arr[] = {5, 5, 1};
    Node *head = createCircularListFromArray(arr, 3);
    EXPECT_TRUE(hasEqualNext(head));
    freeCircularList(head);
}

TEST(Lab3_8Test, HasEqualNext_False)
{
    int arr[] = {1, 2, 3};
    Node *head = createCircularListFromArray(arr, 3);
    EXPECT_FALSE(hasEqualNext(head));
    freeCircularList(head);
}

TEST(Lab3_8Test, DeleteWithEqualNeighbors)
{
    int arr[] = {1, 2, 1};
    Node *head = createCircularListFromArray(arr, 3);
    deleteWithEqualNeighbors(head);
    EXPECT_EQ(countNodes(head), 1);
    EXPECT_FALSE(containsValue(head, 2));
    freeCircularList(head);
}

TEST(Lab3_8Test, DeleteWithEqualNeighbors_None)
{
    int arr[] = {1, 2, 3};
    Node *head = createCircularListFromArray(arr, 3);
    deleteWithEqualNeighbors(head);
    EXPECT_EQ(countNodes(head), 3);
    freeCircularList(head);
}
