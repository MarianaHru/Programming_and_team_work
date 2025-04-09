#ifndef LAB3_4_H
#define LAB3_4_H

struct Node
{
    int data;
    Node *next;
};

Node *CreateCircularListFromInput(int count);                // використовує cin
Node *CreateCircularListFromArray(const int *arr, int size); // для тестів
void PrintCircularList(Node *head);
bool ContainsDuplicate(Node *head);
void DeleteCircularList(Node *&head);

#endif // CIRCULAR_LIST_H
