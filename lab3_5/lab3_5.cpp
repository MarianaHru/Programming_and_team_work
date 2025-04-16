#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Вузол стеку
struct Node
{
    int data;
    Node *next;
};

// Додати елемент у стек
void Push(Node *&top, int value)
{
    Node *newNode = new Node{value, top};
    top = newNode;
}

// Видалити елемент із стеку
bool Pop(Node *&top, int &value)
{
    if (!top)
        return false;
    value = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    return true;
}

// Функція, яка створює стек з клавіатури
void CreateStackFromInput(Node *&top)
{
    int value;
    cout << "Введіть цілі числа (0 — завершити): ";
    while (cin >> value && value != 0)
    {
        Push(top, value);
    }
}

// Функція, яка створює стек з файлу
bool CreateStackFromFile(Node *&top, const string &filename)
{
    ifstream inFile(filename);
    if (!inFile.is_open())
        return false;

    int value;
    while (inFile >> value)
    {
        Push(top, value);
    }
    inFile.close();
    return true;
}

// Функція, яка створює інверсію стеку
void CreateInvertedStack(const Node *sourceTop, Node *&invertedTop)
{
    invertedTop = nullptr;
    const Node *current = sourceTop;
    while (current)
    {
        Push(invertedTop, current->data); // одразу інвертуємо
        current = current->next;
    }
}

// Функція, яка виводить стек
void PrintStack(const Node *top)
{
    const Node *current = top;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Функція, яка очищує стек
void ClearStack(Node *&top)
{
    int val;
    while (Pop(top, val))
        ;
}

// Функція для зчитування стеку з файлу
bool InputFromFile(Node *&top, const string &filename)
{
    ifstream inFile(filename);
    if (!inFile.is_open())
    {
        return false;
    }

    int value;
    while (inFile >> value)
    {
        Push(top, value);
    }
    return true;
}

// Функція для видалення всіх елементів стеку
void DeleteStack(Node *&top)
{
    int val;
    while (Pop(top, val))
        ;
}

#ifndef UNIT_TESTING
int main()
{
    Node *inputStack = nullptr;
    Node *invertedStack = nullptr;

    cout << "Оберіть спосіб введення (1 — з клавіатури, 2 — з файлу): ";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        CreateStackFromInput(inputStack);
    }
    else if (choice == 2)
    {
        string filename;
        cout << "Введіть ім'я файлу: ";
        cin >> filename;
        if (!CreateStackFromFile(inputStack, filename))
        {
            cerr << "Не вдалося відкрити файл!" << endl;
            return 1;
        }
    }
    else
    {
        cout << "Неправильний вибір!" << endl;
        return 1;
    }

    cout << "Початковий стек: ";
    PrintStack(inputStack);

    CreateInvertedStack(inputStack, invertedStack);
    cout << "Інверсований стек: ";
    PrintStack(invertedStack);

    ClearStack(inputStack);
    ClearStack(invertedStack);
    return 0;
}
#endif
