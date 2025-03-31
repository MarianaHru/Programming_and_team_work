#ifndef LAB3_3_REC_H
#define LAB3_3_REC_H

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void insertAtEnd(Node *&head, Node *&tail, int value);
void printListRecursive(Node *node);
Node *deleteBeforeValueRecursive(Node *node, Node *&head, Node *&tail, int target);
void freeListRecursive(Node *node);

#endif