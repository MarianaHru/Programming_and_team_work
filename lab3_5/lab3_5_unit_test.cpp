#include <gtest/gtest.h>
#include "lab3_5.h"

// Перевірка операції Push і Pop
TEST(StackTest, PushPopWorksCorrectly)
{
    Node *stack = nullptr;
    Push(stack, 10);
    Push(stack, 20);
    Push(stack, 30);

    int value;
    EXPECT_TRUE(Pop(stack, value));
    EXPECT_EQ(value, 30);

    EXPECT_TRUE(Pop(stack, value));
    EXPECT_EQ(value, 20);

    EXPECT_TRUE(Pop(stack, value));
    EXPECT_EQ(value, 10);

    EXPECT_FALSE(Pop(stack, value));

    ClearStack(stack);
}

TEST(StackTest, InversionWorksCorrectly)
{
    Node *original = nullptr;
    Push(original, 1);
    Push(original, 2);
    Push(original, 3);

    Node *inverted = nullptr;
    CreateInvertedStack(original, inverted);

    int value;
    EXPECT_TRUE(Pop(inverted, value));
    EXPECT_EQ(value, 1);

    EXPECT_TRUE(Pop(inverted, value));
    EXPECT_EQ(value, 2);

    EXPECT_TRUE(Pop(inverted, value));
    EXPECT_EQ(value, 3);

    EXPECT_FALSE(Pop(inverted, value));

    ClearStack(original);
    ClearStack(inverted);
}
TEST(StackTest, FileInputWorks)
{
    Node *stack = nullptr;

    std::ofstream out("test_input.txt");
    out << "5 10 15";
    out.close();

    ASSERT_TRUE(InputFromFile(stack, "test_input.txt"));

    int value;
    EXPECT_TRUE(Pop(stack, value));
    EXPECT_EQ(value, 15);

    EXPECT_TRUE(Pop(stack, value));
    EXPECT_EQ(value, 10);

    EXPECT_TRUE(Pop(stack, value));
    EXPECT_EQ(value, 5);

    ClearStack(stack);
}
