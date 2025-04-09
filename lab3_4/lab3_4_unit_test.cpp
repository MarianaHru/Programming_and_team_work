#include "lab3_4.h"
#include <gtest/gtest.h>

TEST(CircularListTest, NoDuplicates)
{
    int arr[] = {1, 2, 3, 4, 5};
    Node *head = CreateCircularListFromArray(arr, 5);

    EXPECT_FALSE(ContainsDuplicate(head));

    DeleteCircularList(head);
    EXPECT_EQ(head, nullptr);
}

TEST(CircularListTest, HasDuplicates)
{
    int arr[] = {1, 2, 3, 2, 5};
    Node *head = CreateCircularListFromArray(arr, 5);

    EXPECT_TRUE(ContainsDuplicate(head));

    DeleteCircularList(head);
    EXPECT_EQ(head, nullptr);
}

TEST(CircularListTest, SingleElementList)
{
    int arr[] = {42};
    Node *head = CreateCircularListFromArray(arr, 1);

    EXPECT_FALSE(ContainsDuplicate(head));

    DeleteCircularList(head);
    EXPECT_EQ(head, nullptr);
}

TEST(CircularListTest, EmptyList)
{
    Node *head = nullptr;

    EXPECT_FALSE(ContainsDuplicate(head));
}
