#include <iostream>

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void insertAtEnd(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void printListRecursive(Node *node)
{
    if (!node)
    {
        std::cout << std::endl;
        return;
    }
    std::cout << node->data << " ";
    printListRecursive(node->next);
}

void deleteBeforeValueRecursive(Node *&node, Node *&head, Node *&tail, int target)
{
    if (!node || !node->next)
        return;

    if (node->next->data == target)
    {
        Node *toDelete = node;
        node = node->next; // Зміщуємо поточний вузол на наступний
        if (toDelete->prev)
        {
            toDelete->prev->next = node;
        }
        else
        {
            head = node; // Оновлення голови
        }
        node->prev = toDelete->prev;

        delete toDelete;
        deleteBeforeValueRecursive(node, head, tail, target);
    }
    else
    {
        deleteBeforeValueRecursive(node->next, head, tail, target);
    }
}

void freeListRecursive(Node *node)
{
    if (!node)
        return;
    freeListRecursive(node->next);
    delete node;
}

#ifndef UNIT_TESTING
int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 3);
    insertAtEnd(head, tail, 4);
    insertAtEnd(head, tail, 5);
    insertAtEnd(head, tail, 3);
    insertAtEnd(head, tail, 6);
    insertAtEnd(head, tail, 7);

    std::cout << "Initial list: ";
    printListRecursive(head);

    int target;
    std::cout << "Enter the target value: ";
    std::cin >> target;

    deleteBeforeValueRecursive(head, head, tail, target);

    std::cout << "Modified list: ";
    printListRecursive(head);

    freeListRecursive(head);
    return 0;
}
#endif
