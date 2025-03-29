// lab3_2_test.cpp
#include "lab3_2.h"
#include <gtest/gtest.h>

// Тест створення та додавання елементів
TEST(LinkedListTest, AppendNode)
{
    Node *head = nullptr;
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);

    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->data, 1);
    EXPECT_EQ(head->next->data, 2);
    EXPECT_EQ(head->next->next->data, 3);
    EXPECT_EQ(head->next->next->next, nullptr);

    deleteList(head);
}

// Тест суми парних елементів
TEST(LinkedListTest, SumEvenElements)
{
    Node *head = nullptr;
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 4);
    appendNode(head, 5);
    appendNode(head, 6);

    EXPECT_EQ(sumEvenElements(head), 2 + 4 + 6);

    deleteList(head);
}

// Тест очищення списку
TEST(LinkedListTest, DeleteList)
{
    Node *head = nullptr;
    appendNode(head, 10);
    appendNode(head, 20);
    appendNode(head, 30);

    deleteList(head);
    EXPECT_EQ(head, nullptr);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
