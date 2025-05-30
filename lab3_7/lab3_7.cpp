#include <iostream>
#include <iomanip>

enum Type
{
    INT,
    DOUBLE
};

struct Node
{
    Type type;
    union
    {
        int intValue;
        double doubleValue;
    };
    Node *next;
};

// Створити новий вузол з int(цілі числа)
Node *createIntNode(int value)
{
    Node *node = new Node;
    node->type = INT;
    node->intValue = value;
    node->next = nullptr;
    return node;
}

// Створити новий вузол з double(дійсні числа)
Node *createDoubleNode(double value)
{
    Node *node = new Node;
    node->type = DOUBLE;
    node->doubleValue = value;
    node->next = nullptr;
    return node;
}

// Додати вузол у кінець списку
void append(Node *&head, const string &word)
{
    Node *newNode = new Node{word, nullptr};
    if (!head)
    {
        head = newNode; // Якщо список порожній — новий вузол стає головою
    }
    else
    {
        Node *current = head;
        while (current->next) // Йдемо до останнього вузла
            current = current->next;
        current->next = newNode; // Додаємо новий вузол у кінець
    }
}

// Вивід списку
void printList(Node *head)
{
    Node *current = head;
    while (current)
    {
        if (current->type == INT)
            std::cout << current->intValue << " ";
        else
            std::cout << std::fixed << std::setprecision(2) << current->doubleValue << " ";
        current = current->next;
    }
    std::cout << "\n";
}

// Перенести останній цілий елемент на початок
void moveLastIntToFront(Node *&head)
{
    if (!head || !head->next)
        return; // список порожній або лише один елемент

    Node *current = head;
    Node *prev = nullptr;

    Node *last = head;
    Node *beforeLast = nullptr;

    // Пошук останнього елемента і його попередника
    while (last->next)
    {
        beforeLast = last;
        last = last->next;
    }

    // Якщо останній вузол — ціле число
    if (last->type == INT)
    {
        // Зберігаємо значення
        int val = last->intValue;

        // Видаляємо останній вузол
        if (beforeLast)
        {
            delete last;
            beforeLast->next = nullptr;
        }

        // Створюємо новий вузол і ставимо на початок
        Node *newNode = createIntNode(val);
        newNode->next = head;
        head = newNode;
    }
}

// Видалити список
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
    int n, m;

    std::cout << "Скільки цілих чисел? ";
    std::cin >> n;
    int *intArr = new int[n];
    std::cout << "Введіть " << n << " цілих чисел: ";
    for (int i = 0; i < n; ++i)
        std::cin >> intArr[i];

    std::cout << "Скільки дійсних чисел? ";
    std::cin >> m;
    double *doubleArr = new double[m];
    std::cout << "Введіть " << m << " дійсних чисел: ";
    for (int i = 0; i < m; ++i)
        std::cin >> doubleArr[i];

    Node *list = nullptr;

    // Чергуємо int і double
    int i = 0, j = 0;
    while (i < n || j < m)
    {
        if (i < n)
            append(list, createIntNode(intArr[i++]));
        if (j < m)
            append(list, createDoubleNode(doubleArr[j++]));
    }

    std::cout << "\nСписок до змін:\n";
    printList(list);

    moveLastIntToFront(list);

    std::cout << "\nСписок після переносу останнього цілого на початок:\n";
    printList(list);

    delete[] intArr;
    delete[] doubleArr;
    deleteList(list);

    return 0;
}
#endif