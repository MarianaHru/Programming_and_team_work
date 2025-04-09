#include "lab3_3.h"
#include <gtest/gtest.h>

TEST(DoublyLinkedListTest, InsertAtEnd)
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

    freeList(head);
}

TEST(DoublyLinkedListTest, DeleteBeforeValue)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 3);
    insertAtEnd(head, tail, 4);
    insertAtEnd(head, tail, 5);

    deleteBeforeValue(head, tail, 3);
    EXPECT_EQ(head->data, 1);
    EXPECT_EQ(head->next->data, 3);
    EXPECT_EQ(head->next->next->data, 4);
    EXPECT_EQ(head->next->next->next->data, 5);
    EXPECT_EQ(head->next->next->next->next, nullptr);

    deleteBeforeValue(head, tail, 5);
    EXPECT_EQ(head->data, 1);
    EXPECT_EQ(head->next->data, 3);
    EXPECT_EQ(head->next->next->data, 5);
    EXPECT_EQ(head->next->next->next, nullptr);

    freeList(head);
}

TEST(DoublyLinkedListTest, DeleteBeforeValueHead)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 3);

    deleteBeforeValue(head, tail, 2);
    EXPECT_EQ(head->data, 2);
    EXPECT_EQ(head->next->data, 3);
    EXPECT_EQ(head->next->next, nullptr);

    freeList(head);
}

TEST(DoublyLinkedListTest, DeleteBeforeValueNoMatch)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 3);

    deleteBeforeValue(head, tail, 10);
    EXPECT_EQ(head->data, 1);
    EXPECT_EQ(head->next->data, 2);
    EXPECT_EQ(head->next->next->data, 3);
    EXPECT_EQ(head->next->next->next, nullptr);

    freeList(head);
}

TEST(DoublyLinkedListTest, DeleteBeforeValueEmptyList)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    deleteBeforeValue(head, tail, 10);
    EXPECT_EQ(head, nullptr);
    EXPECT_EQ(tail, nullptr);

    freeList(head);
}

TEST(DoublyLinkedListTest, DeleteBeforeValueOneElement)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtEnd(head, tail, 1);
    deleteBeforeValue(head, tail, 10);
    EXPECT_EQ(head->data, 1);
    EXPECT_EQ(head->next, nullptr);
    EXPECT_EQ(tail->data, 1);
    EXPECT_EQ(tail->prev, nullptr);

    freeList(head);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
