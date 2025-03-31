#include "lab3_3_rec.h"
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

TEST(DoublyLinkedListRecursiveTest, InsertAtEnd)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 3);

    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(listToVector(head), expected);

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

    head = deleteBeforeValueRecursive(head, head, tail, 3);
    std::vector<int> expected1 = {1, 3, 4, 5};
    EXPECT_EQ(listToVector(head), expected1);

    head = deleteBeforeValueRecursive(head, head, tail, 5);
    std::vector<int> expected2 = {1, 3, 5};
    EXPECT_EQ(listToVector(head), expected2);

    freeListRecursive(head);
}

TEST(DoublyLinkedListRecursiveTest, DeleteBeforeValueRecursiveHead)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 3);

    head = deleteBeforeValueRecursive(head, head, tail, 2);
    std::vector<int> expected = {2, 3};
    EXPECT_EQ(listToVector(head), expected);

    freeListRecursive(head);
}

TEST(DoublyLinkedListRecursiveTest, DeleteBeforeValueRecursiveNoMatch)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 3);

    head = deleteBeforeValueRecursive(head, head, tail, 10);
    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(listToVector(head), expected);

    freeListRecursive(head);
}

TEST(DoublyLinkedListRecursiveTest, DeleteBeforeValueRecursiveEmptyList)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    head = deleteBeforeValueRecursive(head, head, tail, 10);
    std::vector<int> expected = {};
    EXPECT_EQ(listToVector(head), expected);

    freeListRecursive(head);
}

TEST(DoublyLinkedListRecursiveTest, DeleteBeforeValueRecursiveOneElement)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtEnd(head, tail, 1);
    head = deleteBeforeValueRecursive(head, head, tail, 10);
    std::vector<int> expected = {1};
    EXPECT_EQ(listToVector(head), expected);

    freeListRecursive(head);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}