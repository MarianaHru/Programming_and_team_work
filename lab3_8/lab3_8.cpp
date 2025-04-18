#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

// Функція створення кільцевого двонаправленого списку з файлу
Node *createCircularListFromFile(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Не вдалося відкрити файл: " << filename << endl;
        return nullptr;
    }

    Node *head = nullptr;
    Node *tail = nullptr;
    int value;

    while (file >> value)
    {
        Node *newNode = new Node{value, nullptr, nullptr};
        if (!head)
        {
            head = newNode;
            tail = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
    }

    file.close();
    return head;
}

void printCircularList(Node *head)
{
    if (!head)
    {
        cout << "Список порожній." << endl;
        return;
    }

    Node *current = head;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

// Функція, яка повертає true, якщо є хоч один елемент, що дорівнює наступному по колу
bool hasEqualNext(Node *head)
{
    if (!head)
        return false;

    Node *current = head;
    do
    {
        if (current->data == current->next->data)
        {
            return true;
        }
        current = current->next;
    } while (current != head);

    return false;
}

// Функція виводу елементів, які дорівнюють наступному по колу
void printEqualNextElements(Node *head)
{
    if (!head)
        return;

    bool found = false;
    Node *current = head;
    do
    {
        if (current->data == current->next->data)
        {
            cout << "Знайдено: " << current->data << endl;
            found = true;
        }
        current = current->next;
    } while (current != head);

    if (!found)
    {
        cout << "Елементів, що дорівнюють наступному по колу, не знайдено." << endl;
    }
}

// Функція видалення вузла
void deleteNode(Node *&head, Node *nodeToDelete)
{
    if (!head || !nodeToDelete)
        return;

    if (nodeToDelete->next == nodeToDelete)
    {
        delete nodeToDelete;
        head = nullptr;
        return;
    }

    if (nodeToDelete == head)
    {
        head = head->next;
    }

    nodeToDelete->prev->next = nodeToDelete->next;
    nodeToDelete->next->prev = nodeToDelete->prev;
    delete nodeToDelete;
}

// Функція видалення всіх елементів з однаковими сусідами
void deleteWithEqualNeighbors(Node *&head)
{
    if (!head || head->next == head)
        return;

    bool changed = true;

    while (changed)
    {
        changed = false;
        Node *current = head;
        Node *start = head;

        do
        {
            if (!current || current->next == current)
                return; // список порожній або з одним елементом

            Node *prev = current->prev;
            Node *next = current->next;

            if (prev->data == next->data)
            {
                if (current == head)
                    head = head->next; // оновлюємо head, якщо треба

                Node *toDelete = current;
                current = current->next;
                deleteNode(head, toDelete);

                // Перевірка, чи список став порожнім
                if (!head || head->next == head)
                    return;

                changed = true;
                break;
            }
            else
            {
                current = current->next;
            }
        } while (current != start);
    }
}

// Функція звільнення пам'яті
void freeCircularList(Node *head)
{
    if (!head)
        return;

    Node *current = head->next;
    while (current != head)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
}
#ifndef UNIT_TESTING
int main()
{
    string filename = "data.txt";
    Node *list = createCircularListFromFile(filename);

    cout << "Початковий список: ";
    printCircularList(list);

    cout << "\nЕлементи, що дорівнюють наступному по колу:" << endl;
    printEqualNextElements(list);

    cout << "\nВидалення елементів з однаковими сусідами..." << endl;
    deleteWithEqualNeighbors(list);

    cout << "Список після видалення: ";
    printCircularList(list);

    freeCircularList(list);
    return 0;
}
#endif
