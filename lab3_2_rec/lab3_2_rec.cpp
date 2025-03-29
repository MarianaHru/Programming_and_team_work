#include "lab3_2_rec.h"
#include <iostream>

// Функція для створення нового вузла
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Рекурсивна функція для додавання елемента в кінець списку
void appendNode(Node *&head, int data)
{
    if (!head)
    {
        head = createNode(data);
        return;
    }
    appendNode(head->next, data);
}

// Рекурсивна функція для друку списку
void printList(const Node *head)
{
    if (!head)
    {
        std::cout << "NULL" << std::endl;
        return;
    }
    std::cout << head->data << " -> ";
    printList(head->next);
}

// Рекурсивна функція для обчислення суми парних елементів
int sumEvenElements(const Node *head)
{
    if (!head)
        return 0;
    return (head->data % 2 == 0 ? head->data : 0) + sumEvenElements(head->next);
}

// Рекурсивна функція для очищення пам'яті
void deleteList(Node *&head)
{
    if (!head)
        return;
    Node *temp = head;
    head = head->next;
    delete temp;
    deleteList(head);
}

#ifndef UNIT_TESTING
int main()
{
    Node *head = nullptr;

    // Формування списку
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 4);
    appendNode(head, 5);
    appendNode(head, 6);

    // Вивід списку
    std::cout << "Список: ";
    printList(head);

    // Обчислення суми парних елементів
    int sum = sumEvenElements(head);
    std::cout << "Сума парних елементів: " << sum << std::endl;

    // Очищення пам'яті
    deleteList(head);

    return 0;
}
#endif
