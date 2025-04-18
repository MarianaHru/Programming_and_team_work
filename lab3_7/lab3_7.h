
#pragma once

struct Node
{
    bool isInt;
    union
    {
        int iVal;
        double dVal;
    };
    Node *next;
};

void AppendNode(Node *&head, bool isInt, int iVal, double dVal);
void PrintList(const Node *head);
Node *MergeAlternating(const int *ints, int intSize, const double *doubles, int doubleSize);
void MoveLastIntToFront(Node *&head);
void DeleteList(Node *&head);
