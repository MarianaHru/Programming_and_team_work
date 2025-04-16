#ifndef LAB3_5_H
#define LAB3_5_H

#include <iostream>
#include <fstream>

struct Node
{
    int data;
    Node *next;
};

void Push(Node *&top, int value);
bool Pop(Node *&top, int &value);
void PrintStack(const Node *top);
void ClearStack(Node *&top);
void CreateInvertedStack(const Node *sourceTop, Node *&invertedTop);

bool InputFromFile(Node *&top, const std::string &filename);
void DeleteStack(Node *&top);

#endif
