#include <iostream>

using namespace std;

// Вузол для списку-множників
struct Node
{
    int data;
    Node *next;
};

// Черга на базі списку
struct Queue
{
    Node *front;
    Node *rear;
};

// Ініціалізація черги
void initQueue(Queue &q)
{
    q.front = nullptr;
    q.rear = nullptr;
}

// Додавання елемента
void enqueue(Queue &q, int value)
{
    Node *newNode = new Node{value, nullptr};
    if (q.rear)
    {
        q.rear->next = newNode;
        q.rear = newNode;
    }
    else
    {
        q.front = q.rear = newNode;
    }
}

// Виведення черги
void printQueue(const Queue &q)
{
    Node *current = q.front;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

// Звільнення пам'яті
void clearQueue(Queue &q)
{
    Node *current = q.front;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    q.front = q.rear = nullptr;
}

// Перевірка, чи число має лише множники 2, 3, 5
bool hasOnly235Factors(int number)
{
    if (number == 1)
        return true;
    while (number % 2 == 0)
        number /= 2;
    while (number % 3 == 0)
        number /= 3;
    while (number % 5 == 0)
        number /= 5;
    return number == 1;
}

// Побудова черги множників для числа
void buildFactorQueue(int number, Queue &factors)
{
    int n = number;
    for (int prime : {2, 3, 5})
    {
        while (n % prime == 0)
        {
            enqueue(factors, prime);
            n /= prime;
        }
    }
}

// Основна функція побудови списку множників для перших n чисел
void generateFactorQueues(Queue *queues[], int n)
{
    int count = 0;
    int current = 1;
    while (count < n)
    {
        if (hasOnly235Factors(current))
        {
            queues[count] = new Queue;
            initQueue(*queues[count]);
            buildFactorQueue(current, *queues[count]);
            count++;
        }
        current++;
    }
}

// Виведення результату
void printFactorQueues(Queue *queues[], int n)
{
    int current = 1;
    for (int i = 0; i < n; ++i)
    {
        cout << current << ": ";
        printQueue(*queues[i]);
        cout << endl;
        current++;
    }
}

// Звільнення пам'яті
void deleteQueues(Queue *queues[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        clearQueue(*queues[i]);
        delete queues[i];
    }
}

// === Головна функція ===
int main()
{
    int n;
    cout << "Введіть n: ";
    cin >> n;

    Queue *factorQueues[n];
    generateFactorQueues(factorQueues, n);
    printFactorQueues(factorQueues, n);
    deleteQueues(factorQueues, n);

    return 0;
}
