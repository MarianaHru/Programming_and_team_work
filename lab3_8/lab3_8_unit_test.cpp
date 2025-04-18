#include "lab3_8.h"
#include <gtest/gtest.h>

Node *createCircularListFromArray(const int *arr, int size)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    for (int i = 0; i < size; ++i)
    {
        Node *newNode = new Node{arr[i], nullptr, nullptr};
        if (!head)
        {
            head = newNode;
            tail = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
    }

    return head;
}

int countNodes(Node *head)
{
    if (!head)
        return 0;
    int count = 0;
    Node *current = head;
    do
    {
        ++count;
        current = current->next;
    } while (current != head);
    return count;
}

bool containsValue(Node *head, int value)
{
    if (!head)
        return false;
    Node *current = head;
    do
    {
        if (current->data == value)
            return true;
        current = current->next;
    } while (current != head);
    return false;
}

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
