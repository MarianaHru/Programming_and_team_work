#ifndef LAB3_6_H
#define LAB3_6_H

#include <iostream>

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    Node *front;
    Node *rear;
};

void initQueue(Queue &q);

void enqueue(Queue &q, int value);

void printQueue(const Queue &q);

void clearQueue(Queue &q);

bool hasOnly235Factors(int number);

void buildFactorQueue(int number, Queue &factors);

void generateFactorQueues(Queue *queues[], int n);

void printFactorQueues(Queue *queues[], int n);

void deleteQueues(Queue *queues[], int n);

#endif