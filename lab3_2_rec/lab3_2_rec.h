#ifndef LAB3_2_H
#define LAB3_2_H

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data);
void appendNode(Node *&head, int data);
void printList(const Node *head);
int sumEvenElements(const Node *head);
void deleteList(Node *&head);

#endif