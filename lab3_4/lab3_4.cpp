#include <iostream>

// Структура вузла кільцевого однонаправленого списку
struct Node
{
    int data;
    Node *next;
};

// Функція, яка створює кільцевий список з введення користувача
Node *CreateCircularListFromInput(int count)
{
    if (count <= 0)
        return nullptr;

    int value;
    std::cout << "Введіть значення 1-го елемента: ";
    std::cin >> value;

    Node *head = new Node;
    head->data = value;
    head->next = nullptr;

    Node *current = head;
    for (int i = 1; i < count; ++i)
    {
        std::cout << "Введіть значення " << i + 1 << "-го елемента: ";
        std::cin >> value;

        current->next = new Node;
        current = current->next;
        current->data = value;
        current->next = nullptr;
    }

    current->next = head; // Робимо список кільцевим
    return head;
}

// Функція, яка виводить список
void PrintCircularList(Node *head)
{
    if (!head)
        return;

    Node *current = head;
    do
    {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
}

// Функція, яка перевіряє, чи є дублікати у списку
bool ContainsDuplicate(Node *head)
{
    if (!head || head->next == head)
        return false;

    Node *current = head;
    do
    {
        Node *checker = current->next;
        while (checker != head)
        {
            if (current->data == checker->data)
            {
                return true;
            }
            checker = checker->next;
        }
        current = current->next;
    } while (current != head);

    return false;
}

// Функція, яка звільняє пам’ять списку
void DeleteCircularList(Node *&head)
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
    head = nullptr;
}

// Додаткова функція тільки для юніт-тестів
Node *CreateCircularListFromArray(const int *arr, int size)
{
    if (size <= 0)
        return nullptr;

    Node *head = new Node{arr[0], nullptr};
    Node *current = head;

    for (int i = 1; i < size; ++i)
    {
        current->next = new Node{arr[i], nullptr};
        current = current->next;
    }

    current->next = head;
    return head;
}
#ifndef UNIT_TESTING
int main()
{
    int count;
    std::cout << "Скільки елементів у списку? ";
    std::cin >> count;

    Node *list = CreateCircularListFromInput(count);

    std::cout << "Сформований список: ";
    PrintCircularList(list);

    bool hasDuplicates = ContainsDuplicate(list);
    std::cout << "Чи є дублікати у списку? " << (hasDuplicates ? "Так" : "Ні") << std::endl;

    DeleteCircularList(list);
    return 0;
}
#endif