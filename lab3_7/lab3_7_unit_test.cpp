

#include "lab3_7.h"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <iomanip>

int *CreateIntArray(std::initializer_list<int> values)
{
    int *arr = new int[values.size()];
    int i = 0;
    for (int val : values)
    {
        arr[i++] = val;
    }
    return arr;
}

double *CreateDoubleArray(std::initializer_list<double> values)
{
    double *arr = new double[values.size()];
    int i = 0;
    for (double val : values)
    {
        arr[i++] = val;
    }
    return arr;
}

std::string ListToString(const Node *head)
{
    std::ostringstream out;
    while (head)
    {
        if (head->isInt)
            out << head->iVal << " ";
        else
            out << std::fixed << std::setprecision(2) << head->dVal << " ";
        head = head->next;
    }
    return out.str();
}

TEST(Lab3_7Test, MergeAlternatingWorksCorrectly)
{
    int *ints = CreateIntArray({1, 2});
    double *doubles = CreateDoubleArray({1.1, 2.2});
    Node *head = MergeAlternating(ints, 2, doubles, 2);

    std::string expected = "1 1.10 2 2.20 ";
    EXPECT_EQ(ListToString(head), expected);

    DeleteList(head);
    delete[] ints;
    delete[] doubles;
}

TEST(Lab3_7Test, MoveLastIntToFront_WorksCorrectly)
{
    int *ints = CreateIntArray({10, 20, 30});
    double *doubles = CreateDoubleArray({0.5, 0.6});
    Node *head = MergeAlternating(ints, 3, doubles, 2);

    std::string before = "10 0.50 20 0.60 30 ";
    EXPECT_EQ(ListToString(head), before);

    MoveLastIntToFront(head);

    std::string after = "30 10 0.50 20 0.60 ";
    EXPECT_EQ(ListToString(head), after);

    DeleteList(head);
    delete[] ints;
    delete[] doubles;
}

TEST(Lab3_7Test, HandlesEmptyList)
{
    Node *head = nullptr;
    MoveLastIntToFront(head);
    EXPECT_EQ(head, nullptr);
}
