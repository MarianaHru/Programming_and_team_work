// #ifdef UNIT_TESTING
// #include "lab3_2.h"
// #include <gtest/gtest.h>

// TEST(LinkedListTest, SumEvenElements)
// {
//     Node *head = nullptr;
//     appendNode(head, 1);
//     appendNode(head, 2);
//     appendNode(head, 3);
//     appendNode(head, 4);
//     appendNode(head, 5);
//     appendNode(head, 6);
//     EXPECT_EQ(sumEvenElements(head), 12);
//     deleteList(head);
// }

// TEST(LinkedListTest, EmptyList)
// {
//     Node *head = nullptr;
//     EXPECT_EQ(sumEvenElements(head), 0);
// }

// TEST(LinkedListTest, OnlyOddNumbers)
// {
//     Node *head = nullptr;
//     appendNode(head, 1);
//     appendNode(head, 3);
//     appendNode(head, 5);
//     EXPECT_EQ(sumEvenElements(head), 0);
//     deleteList(head);
// }

// TEST(LinkedListTest, OnlyEvenNumbers)
// {
//     Node *head = nullptr;
//     appendNode(head, 2);
//     appendNode(head, 4);
//     appendNode(head, 6);
//     EXPECT_EQ(sumEvenElements(head), 12);
//     deleteList(head);
// }

// int main(int argc, char **argv)
// {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
// #endif

#include "lab3_2.h"
#include <gtest/gtest.h>

TEST(LinkedListTest, AppendAndPrint)
{
    Node *head = nullptr;
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);

    testing::internal::CaptureStdout();
    printList(head);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 -> 2 -> 3 -> NULL\n");

    deleteList(head);
}

TEST(LinkedListTest, SumEvenElements)
{
    Node *head = nullptr;
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 4);
    appendNode(head, 5);
    appendNode(head, 6);

    EXPECT_EQ(sumEvenElements(head), 12);

    deleteList(head);
}

TEST(LinkedListTest, EmptyList)
{
    Node *head = nullptr;
    EXPECT_EQ(sumEvenElements(head), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}