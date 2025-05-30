#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

// Створення нового вузла
TreeNode *CreateNode(int value)
{
    TreeNode *node = new TreeNode{value, nullptr, nullptr};
    return node;
}

// Додавання вузла в бінарне дерево (без збереження порядку)
void AddNode(TreeNode *&root, int value)
{
    if (!root)
    {
        root = CreateNode(value);
        return;
    }
    if (rand() % 2 == 0)
        AddNode(root->left, value);
    else
        AddNode(root->right, value);
}

// Додавання у бінарне дерево пошуку
void AddNodeBST(TreeNode *&root, int value)
{
    if (!root)
    {
        root = CreateNode(value);
        return;
    }
    if (value < root->data)
        AddNodeBST(root->left, value);
    else
        AddNodeBST(root->right, value);
}

// Обхід дерева In-order (з відступами)
void PrintTree(TreeNode *root, int depth = 0)
{
    if (!root)
        return;
    PrintTree(root->right, depth + 1);
    cout << string(depth * 4, ' ') << root->data << endl;
    PrintTree(root->left, depth + 1);
}

// Функція рахує кількість вузлів
int CountNodes(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + CountNodes(root->left) + CountNodes(root->right);
}

// Пошук мінімального вузла (для видалення з 2 дітьми)
TreeNode *FindMin(TreeNode *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

// Видалення вузла за значенням (повна реалізація з 3 випадками)
TreeNode *DeleteNode(TreeNode *root, int value)
{
    if (!root)
        return nullptr;
    if (value < root->data)
        root->left = DeleteNode(root->left, value);
    else if (value > root->data)
        root->right = DeleteNode(root->right, value);
    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }
        else if (!root->left || !root->right)
        {
            TreeNode *temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
        else
        {
            TreeNode *minRight = FindMin(root->right);
            root->data = minRight->data;
            root->right = DeleteNode(root->right, minRight->data);
        }
    }
    return root;
}
// Очищення дерева
void ClearTree(TreeNode *&root)
{
    if (!root)
        return;
    ClearTree(root->left);
    ClearTree(root->right);
    delete root;
    root = nullptr;
}

// Видалення гілки дерева (піддерева) показник повертається в корінь
TreeNode *DeleteSubtree(TreeNode *root, int value)
{
    if (!root)
        return nullptr;
    if (value == root->data)
    {
        ClearTree(root);
        return nullptr;
    }
    if (value < root->data)
        root->left = DeleteSubtree(root->left, value); // оце

    else
        root->right = DeleteSubtree(root->right, value);
    return root;
}

// Створення дерева з N випадкових елементів
void CreateRandomTree(TreeNode *&root, int n, bool isBST)
{
    root = nullptr;
    for (int i = 0; i < n; ++i)
    {
        int value = rand() % 100;
        if (isBST)
            AddNodeBST(root, value);
        else
            AddNode(root, value);
    }
}

// Балансування дерева (перетворення у масив, потім з нього — у дерево)
void TreeToArray(TreeNode *root, int *arr, int &index)
{
    if (!root)
        return;
    TreeToArray(root->left, arr, index);
    arr[index++] = root->data;
    TreeToArray(root->right, arr, index);
}

TreeNode *ArrayToBalancedTree(int *arr, int left, int right)
{
    if (left > right)
        return nullptr;
    int mid = (left + right) / 2;
    TreeNode *root = CreateNode(arr[mid]);
    root->left = ArrayToBalancedTree(arr, left, mid - 1);
    root->right = ArrayToBalancedTree(arr, mid + 1, right);
    return root;
}

void BalanceTree(TreeNode *&root)
{
    int count = CountNodes(root);
    int *arr = new int[count];
    int index = 0;
    TreeToArray(root, arr, index);
    ClearTree(root);
    root = ArrayToBalancedTree(arr, 0, count - 1);
    delete[] arr;
}

void Menu()
{
    TreeNode *root = nullptr;
    int choice, value, n;

    do
    {
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Створити бінарне дерево\n";
        cout << "2. Вивести дерево\n";
        cout << "3. Створити бінарне дерево пошуку\n";
        cout << "4. Додати елемент у дерево пошуку\n";
        cout << "5. Збалансувати дерево пошуку\n";
        cout << "6. Видалити елемент без дітей\n";
        cout << "7. Видалити елемент з одним нащадком\n";
        cout << "8. Видалити елемент з двома нащадками\n";
        cout << "9. Видалити гілку (за значенням)\n";
        cout << "10. Порахувати кількість елементів\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Кількість елементів: ";
            cin >> n;
            CreateRandomTree(root, n, false);
            break;
        case 2:
            PrintTree(root);
            break;
        case 3:
            cout << "Кількість елементів: ";
            cin >> n;
            CreateRandomTree(root, n, true);
            break;
        case 4:
            cout << "Введіть значення: ";
            cin >> value;
            AddNodeBST(root, value);
            break;
        case 5:
            BalanceTree(root);
            cout << "Дерево збалансовано.\n";
            break;
        case 6:
        case 7:
        case 8:
            cout << "Введіть значення: ";
            cin >> value;
            root = DeleteNode(root, value);
            break;
        case 9:
            cout << "Введіть значення кореня гілки: ";
            cin >> value;
            root = DeleteSubtree(root, value);
            break;
        case 10:
            cout << "Кількість елементів: " << CountNodes(root) << endl;
            break;
        case 0:
            ClearTree(root);
            break;
        default:
            cout << "Невірний вибір!\n";
        }
    } while (choice != 0);
}
#ifndef UNIT_TESTING
int main()
{
    srand(time(0));
    Menu();
    return 0;
}
#endif