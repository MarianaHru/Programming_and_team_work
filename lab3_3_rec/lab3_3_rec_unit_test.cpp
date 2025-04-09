#include "lab3_3_rec.h"
#include <gtest/gtest.h>

TEST(DoublyLinkedListRecursiveTest, InsertAtEnd)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 3);

    EXPECT_EQ(head->data, 1);
    EXPECT_EQ(head->next->data, 2);
    EXPECT_EQ(head->next->next->data, 3);
    EXPECT_EQ(head->next->next->next, nullptr);
    EXPECT_EQ(tail->data, 3);
    EXPECT_EQ(tail->prev->data, 2);
    EXPECT_EQ(tail->prev->prev->data, 1);
    EXPECT_EQ(tail->prev->prev->prev, nullptr);

    freeListRecursive(head);
}

TEST(DoublyLinkedListRecursiveTest, DeleteBeforeValueRecursive)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 3);
    insertAtEnd(head, tail, 4);
    insertAtEnd(head, tail, 5);

    deleteBeforeValueRecursive(head, head, tail, 3);
    EXPECT_EQ(head->data, 1);
    EXPECT_EQ(head->next->data, 3);
    EXPECT_EQ(head->next->next->data, 4);
    EXPECT_EQ(head->next->next->next->data, 5);
    EXPECT_EQ(head->next->next->next->next, nullptr);

    deleteBeforeValueRecursive(head, head, tail, 5);
    EXPECT_EQ(head->data, 1);
    EXPECT_EQ(head->next->data, 3);
    EXPECT_EQ(head->next->next->data, 5);
    EXPECT_EQ(head->next->next->next, nullptr);

    freeListRecursive(head);
}

TEST(DoublyLinkedListRecursiveTest, DeleteBeforeValueRecursiveHead)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 3);

    deleteBeforeValueRecursive(head, head, tail, 2);
    EXPECT_EQ(head->data, 2);
    EXPECT_EQ(head->next->data, 3);
    EXPECT_EQ(head->next->next, nullptr);

    freeListRecursive(head);
}

TEST(DoublyLinkedListRecursiveTest, DeleteBeforeValueRecursiveNoMatch)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 3);

    deleteBeforeValueRecursive(head, head, tail, 10);
    EXPECT_EQ(head->data, 1);
    EXPECT_EQ(head->next->data, 2);
    EXPECT_EQ(head->next->next->data, 3);
    EXPECT_EQ(head->next->next->next, nullptr);

    freeListRecursive(head);
}

TEST(DoublyLinkedListRecursiveTest, DeleteBeforeValueRecursiveEmptyList)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    deleteBeforeValueRecursive(head, head, tail, 10);
    EXPECT_EQ(head, nullptr);
    EXPECT_EQ(tail, nullptr);

    freeListRecursive(head);
}

TEST(DoublyLinkedListRecursiveTest, DeleteBeforeValueRecursiveOneElement)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtEnd(head, tail, 1);
    deleteBeforeValueRecursive(head, head, tail, 10);
    EXPECT_EQ(head->data, 1);
    EXPECT_EQ(head->next, nullptr);
    EXPECT_EQ(tail->data, 1);
    EXPECT_EQ(tail->prev, nullptr);

    freeListRecursive(head);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
