#ifndef LAB3_4_REC_H
#define LAB3_4_REC_H

#include <cstddef>

struct Node
{
    int data;
    Node *next;
};

Node *CreateCircularListFromArray(int arr[], int size);
Node *CreateCircularListRecursive(int count, int index = 1, Node *head = nullptr, Node *prev = nullptr);
void PrintCircularListRecursive(Node *current, Node *head, bool firstCall = true);
bool ContainsDuplicate(Node *head);
void DeleteCircularList(Node *&head);

#endif