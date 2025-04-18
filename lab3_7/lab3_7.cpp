// true — ціле число, false — дійсне
#include <iostream>
#include <iomanip>
using namespace std;

// Структура вузла односпрямованого списку
struct Node
{
    bool isInt;
    union
    {
        int iVal;
        double dVal;
    };
    Node *next;
};

// Додає новий вузол у кінець списку
void AppendNode(Node *&head, bool isInt, int iVal, double dVal)
{
    Node *newNode = new Node;
    newNode->isInt = isInt;
    newNode->next = nullptr;
    if (isInt)
        newNode->iVal = iVal;
    else
        newNode->dVal = dVal;

    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

void PrintList(const Node *head)
{
    const Node *current = head;
    while (current)
    {
        if (current->isInt)
            cout << current->iVal << " ";
        else
            cout << fixed << setprecision(2) << current->dVal << " ";
        current = current->next;
    }
    cout << endl;
}

// Змішує цілі та дійсні числа в один список почергово
Node *MergeAlternating(const int *ints, int intSize, const double *doubles, int doubleSize)
{
    Node *result = nullptr;
    int i = 0, j = 0;
    while (i < intSize || j < doubleSize)
    {
        if (i < intSize)
        {
            AppendNode(result, true, ints[i], 0.0);
            i++;
        }
        if (j < doubleSize)
        {
            AppendNode(result, false, 0, doubles[j]);
            j++;
        }
    }
    return result;
}

// Переміщує останнє ціле число на початок списку
void MoveLastIntToFront(Node *&head)
{
    if (!head || !head->next)
        return;

    Node *prev = nullptr;
    Node *current = head;
    Node *lastInt = nullptr;
    Node *lastIntPrev = nullptr;

    while (current)
    {
        if (current->isInt)
        {
            lastIntPrev = prev;
            lastInt = current;
        }
        prev = current;
        current = current->next;
    }

    if (lastInt && lastInt == prev && lastInt != head)
    {
        lastIntPrev->next = lastInt->next;
        lastInt->next = head;
        head = lastInt;
    }
}

// Видаляє список і звільняє пам'ять
void DeleteList(Node *&head)
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
    int nInt, nDouble;

    cout << "Скільки цілих чисел? ";
    cin >> nInt;
    int *intArr = new int[nInt];
    cout << "Введіть " << nInt << " цілих чисел: ";
    for (int i = 0; i < nInt; ++i)
    {
        cin >> intArr[i];
    }

    cout << "Скільки дійсних чисел? ";
    cin >> nDouble;
    double *doubleArr = new double[nDouble];
    cout << "Введіть " << nDouble << " дійсних чисел: ";
    for (int i = 0; i < nDouble; ++i)
    {
        cin >> doubleArr[i];
    }

    Node *list = MergeAlternating(intArr, nInt, doubleArr, nDouble);

    cout << "\nСписок до змін:\n";
    PrintList(list);

    MoveLastIntToFront(list);

    cout << "\nСписок після переносу останнього цілого на початок:\n";
    PrintList(list);

    DeleteList(list);
    delete[] intArr;
    delete[] doubleArr;
    return 0;
}
#endif
