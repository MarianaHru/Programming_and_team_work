#include "lab3_3.h"
#include <gtest/gtest.h>
#include <vector>

std::vector<int> listToVector(Node *head)
{
    std::vector<int> result;
    Node *temp = head;
    while (temp)
    {
        result.push_back(temp->data);
        temp = temp->next;
    }
    return result;
}

TEST(DoublyLinkedListTest, InsertAtEnd)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 3);

    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(listToVector(head), expected);

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
    std::vector<int> expected1 = {1, 3, 4, 5};
    EXPECT_EQ(listToVector(head), expected1);

    deleteBeforeValue(head, tail, 5);
    std::vector<int> expected2 = {1, 3, 5};
    EXPECT_EQ(listToVector(head), expected2);

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
    std::vector<int> expected = {2, 3};
    EXPECT_EQ(listToVector(head), expected);

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
    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(listToVector(head), expected);

    freeList(head);
}

TEST(DoublyLinkedListTest, DeleteBeforeValueEmptyList)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    deleteBeforeValue(head, tail, 10);
    std::vector<int> expected = {};
    EXPECT_EQ(listToVector(head), expected);

    freeList(head);
}

TEST(DoublyLinkedListTest, DeleteBeforeValueOneElement)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtEnd(head, tail, 1);
    deleteBeforeValue(head, tail, 10);
    std::vector<int> expected = {1};
    EXPECT_EQ(listToVector(head), expected);

    freeList(head);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}