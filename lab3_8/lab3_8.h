#pragma once
#include <string>

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *createCircularListFromFile(const std::string &filename);
Node *createCircularListFromArray(const int *arr, int size);
void printCircularList(Node *head);
bool hasEqualNext(Node *head);
void printEqualNextElements(Node *head);
void deleteNode(Node *&head, Node *nodeToDelete);
void deleteWithEqualNeighbors(Node *&head);
void freeCircularList(Node *head);
int countNodes(Node *head);
bool containsValue(Node *head, int value);
