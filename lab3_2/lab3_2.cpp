#include <iostream>

struct Node
{
    int data;
    Node *next;
};

// Функція для створення нового вузла
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Функція для додавання елемента в кінець списку
void appendNode(Node *&head, int data)
{
    Node *newNode = createNode(data);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Функція для друку списку
void printList(const Node *head)
{
    const Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}

// Функція для обчислення суми парних елементів
int sumEvenElements(const Node *head)
{
    int sum = 0;
    while (head)
    {
        if (head->data % 2 == 0)
        {
            sum += head->data;
        }
        head = head->next;
    }
    return sum;
}

// Функція для очищення пам'яті
void deleteList(Node *&head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
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
