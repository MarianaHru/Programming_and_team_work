#include "lab3_4_rec.h"
#include <gtest/gtest.h>

TEST(CircularListTest, NoDuplicates)
{
    int arr[] = {1, 2, 3, 4, 5};
    Node *head = CreateCircularListFromArray(arr, 5);

    // Перевіряємо, що дублікатів НЕМАЄ, тому очікуємо FALSE
    EXPECT_FALSE(ContainsDuplicate(head));

    DeleteCircularList(head);
    EXPECT_EQ(head, nullptr);
}

TEST(CircularListTest, HasDuplicates)
{
    int arr[] = {1, 2, 3, 2, 5};
    Node *head = CreateCircularListFromArray(arr, 5);

    // Перевіряємо, що ДУБЛІКАТИ Є, тому очікуємо TRUE
    EXPECT_TRUE(ContainsDuplicate(head));

    DeleteCircularList(head);
    EXPECT_EQ(head, nullptr);
}

TEST(CircularListTest, SingleElementList)
{
    int arr[] = {42};
    Node *head = CreateCircularListFromArray(arr, 1);

    // Перевіряємо, що дублікатів НЕМАЄ, тому очікуємо FALSE
    EXPECT_FALSE(ContainsDuplicate(head));

    DeleteCircularList(head);
    EXPECT_EQ(head, nullptr);
}

TEST(CircularListTest, EmptyList)
{
    Node *head = nullptr;

    // Перевіряємо, що дублікатів НЕМАЄ (бо список порожній), тому очікуємо FALSE
    EXPECT_FALSE(ContainsDuplicate(head));
}