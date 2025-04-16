#include "lab3_4_rec.h"
#include <cstddef>
#include <iostream>

// Рекурсивна функція для створення кільцевого списку з масиву
Node *CreateCircularListFromArrayRecursive(int arr[], int size, int index, Node *head, Node *current)
{
    if (index >= size)
    {
        if (head)
            current->next = head; // Робимо список кільцевим
        return head;
    }

    Node *newNode = new Node;
    newNode->data = arr[index];
    newNode->next = nullptr;

    if (!head)
    {
        head = newNode;
        current = head;
    }
    else
    {
        current->next = newNode;
        current = current->next;
    }

    return CreateCircularListFromArrayRecursive(arr, size, index + 1, head, current);
}

// Функція для створення кільцевого списку з масиву (виклик рекурсивної функції)
Node *CreateCircularListFromArray(int arr[], int size)
{
    if (size <= 0)
    {
        return nullptr;
    }
    return CreateCircularListFromArrayRecursive(arr, size, 0, nullptr, nullptr);
}

// Рекурсивна функція створення списку
Node *CreateCircularListRecursive(int count, int index, Node *head, Node *prev)
{
    if (count <= 0)
        return nullptr;

    int value;
    std::cout << "Введіть значення " << index << "-го елемента: ";
    std::cin >> value;

    Node *current = new Node;
    current->data = value;
    current->next = nullptr;

    if (index == 1)
    {
        head = current;
    }
    else if (prev)
    {
        prev->next = current;
    }

    if (index == count)
    {
        current->next = head; // Робимо список кільцевим
        return head;
    }

    return CreateCircularListRecursive(count, index + 1, head, current);
}

void PrintCircularListRecursive(Node *current, Node *head, bool firstCall)
{
    if (!current || (!firstCall && current == head))
        return;

    std::cout << current->data << " ";
    PrintCircularListRecursive(current->next, head, false);
}

// Рекурсивна перевірка на дублікати
bool CheckDuplicateRecursive(Node *current, Node *head, Node *checker)
{
    if (!current || current->next == head)
        return false;

    if (checker == head)
        return CheckDuplicateRecursive(current->next, head, current->next->next);

    if (current->data == checker->data)
        return true;

    return CheckDuplicateRecursive(current, head, checker->next);
}

bool ContainsDuplicate(Node *head)
{
    if (!head || head->next == head)
        return false;
    return CheckDuplicateRecursive(head, head, head->next);
}

void DeleteCircularListRecursive(Node *current, Node *head)
{
    if (!current || current->next == head)
    {
        delete current;
        return;
    }

    Node *nextNode = current->next;
    delete current;
    DeleteCircularListRecursive(nextNode, head);
}

void DeleteCircularList(Node *&head)
{
    if (!head)
        return;

    DeleteCircularListRecursive(head->next, head);
    head = nullptr;
}

#ifndef UNIT_TESTING
int main()
{
    int count;
    std::cout << "Скільки елементів у списку? ";
    std::cin >> count;

    Node *list = CreateCircularListRecursive(count);

    std::cout << "Сформований список: ";
    PrintCircularListRecursive(list, list);
    std::cout << std::endl;

    bool hasDuplicates = ContainsDuplicate(list);
    std::cout << "Чи є дублікати у списку? " << (hasDuplicates ? "Так" : "Ні") << std::endl;

    DeleteCircularList(list);

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node *listFromArray = CreateCircularListFromArray(arr, size);
    std::cout << "Список з масиву: ";
    PrintCircularListRecursive(listFromArray, listFromArray);
    std::cout << std::endl;
    DeleteCircularList(listFromArray);

    return 0;
}
#endif