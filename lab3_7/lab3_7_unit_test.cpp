#include "lab3_7.h"
#include <gtest/gtest.h>

TEST(Lab3_7Test, MergeAlternatingWorksCorrectly)
{
    int ints[] = {1, 2};
    double doubles[] = {1.1, 2.2};
    Node *head = MergeAlternating(ints, 2, doubles, 2);

    std::string expected = "1 1.10 2 2.20 ";
    EXPECT_EQ(ListToString(head), expected);

    DeleteList(head);
}

TEST(Lab3_7Test, MoveLastIntToFront_WorksCorrectly)
{
    int ints[] = {10, 20, 30};
    double doubles[] = {0.5, 0.6};
    Node *head = MergeAlternating(ints, 3, doubles, 2);

    std::string before = "10 0.50 20 0.60 30 ";
    EXPECT_EQ(ListToString(head), before);

    MoveLastIntToFront(head);

    std::string after = "30 10 0.50 20 0.60 ";
    EXPECT_EQ(ListToString(head), after);

    DeleteList(head);
}

TEST(Lab3_7Test, HandlesEmptyList)
{
    Node *head = nullptr;
    MoveLastIntToFront(head);
    EXPECT_EQ(head, nullptr);
}
