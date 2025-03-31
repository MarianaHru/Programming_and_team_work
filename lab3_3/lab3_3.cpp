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

void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
void deleteBeforeValue(Node *&head, Node *&tail, int target)
{
    if (!head || !head->next)
        return; // Якщо список пустий або має 1 елемент

    Node *current = head->next; // Починаємо з другого елемента

    while (current)
    {
        if (current->data == target)
        {
            Node *toDelete = current->prev;
            if (!toDelete)
                return; // Якщо перед target немає елемента

            // Оновлення голови списку
            if (toDelete == head)
            {
                head = current;
                head->prev = nullptr;
            }
            else
            {
                toDelete->prev->next = current;
                current->prev = toDelete->prev;
            }

            delete toDelete;
            return; // Видаляємо лише один елемент
        }
        current = current->next;
    }
}

void freeList(Node *&head)
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
    printList(head);

    int target;
    std::cout << "Enter the target value: ";
    std::cin >> target;

    deleteBeforeValue(head, tail, target);

    std::cout << "Modified list: ";
    printList(head);

    freeList(head);
    return 0;
}
#endif
