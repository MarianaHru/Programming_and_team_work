#ifndef LAB3_3_H
#define LAB3_3_H

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void insertAtEnd(Node *&head, Node *&tail, int value);
void printList(Node *head);
void deleteBeforeValue(Node *&head, Node *&tail, int target);
void freeList(Node *&head);

#endif