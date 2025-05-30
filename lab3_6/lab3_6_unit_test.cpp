#include "gtest/gtest.h"
#include "lab3_6.h"

void assertQueueEquals(const Queue &q, const int expected[], int size)
{
    Node *current = q.front;
    for (int i = 0; i < size; ++i)
    {
        ASSERT_NE(current, nullptr);
        EXPECT_EQ(current->data, expected[i]);
        current = current->next;
    }
    EXPECT_EQ(current, nullptr);
}

TEST(HasOnly235FactorsTest, ValidValues)
{
    EXPECT_TRUE(hasOnly235Factors(1));
    EXPECT_TRUE(hasOnly235Factors(2));
    EXPECT_TRUE(hasOnly235Factors(3));
    EXPECT_TRUE(hasOnly235Factors(5));
    EXPECT_TRUE(hasOnly235Factors(6));
    EXPECT_TRUE(hasOnly235Factors(10));
    EXPECT_TRUE(hasOnly235Factors(15));
    EXPECT_TRUE(hasOnly235Factors(30));
    EXPECT_TRUE(hasOnly235Factors(4));
    EXPECT_TRUE(hasOnly235Factors(8));
    EXPECT_TRUE(hasOnly235Factors(9));
    EXPECT_TRUE(hasOnly235Factors(25));
    EXPECT_TRUE(hasOnly235Factors(12));
    EXPECT_TRUE(hasOnly235Factors(18));
    EXPECT_TRUE(hasOnly235Factors(20));
    EXPECT_TRUE(hasOnly235Factors(45));
    EXPECT_TRUE(hasOnly235Factors(50));
    EXPECT_TRUE(hasOnly235Factors(75));
}

TEST(HasOnly235FactorsTest, InvalidValues)
{
    EXPECT_FALSE(hasOnly235Factors(7));
    EXPECT_FALSE(hasOnly235Factors(11));
    EXPECT_FALSE(hasOnly235Factors(13));
    EXPECT_FALSE(hasOnly235Factors(14));
    EXPECT_FALSE(hasOnly235Factors(17));
    EXPECT_FALSE(hasOnly235Factors(21));
    EXPECT_FALSE(hasOnly235Factors(22));
    EXPECT_FALSE(hasOnly235Factors(26));
    EXPECT_FALSE(hasOnly235Factors(28));
    EXPECT_FALSE(hasOnly235Factors(35));
}

TEST(BuildFactorQueueTest, FactorsAreCorrect)
{
    Queue q;
    initQueue(q);
    buildFactorQueue(18, q);
    int expected1[] = {2, 3, 3};
    assertQueueEquals(q, expected1, 3);
    clearQueue(q);

    initQueue(q);
    buildFactorQueue(30, q);
    int expected2[] = {2, 3, 5};
    assertQueueEquals(q, expected2, 3);
    clearQueue(q);

    initQueue(q);
    buildFactorQueue(1, q);
    assertQueueEquals(q, nullptr, 0);
    clearQueue(q);
}

TEST(GenerateFactorQueuesTest, GeneratesCorrectQueues)
{
    const int n = 5;
    int values[n] = {0, 2, 3, 4, 5};
    Queue *factorQueues[n];
    generateFactorQueues(factorQueues, n, values);

    int expected0[] = {};
    int expected1[] = {2};
    int expected2[] = {3};
    int expected3[] = {2, 2};
    int expected4[] = {5};

    assertQueueEquals(*factorQueues[0], expected0, 0);
    assertQueueEquals(*factorQueues[1], expected1, 1);
    assertQueueEquals(*factorQueues[2], expected2, 1);
    assertQueueEquals(*factorQueues[3], expected3, 2);
    assertQueueEquals(*factorQueues[4], expected4, 1);

    deleteQueues(factorQueues, n);
}

TEST(GenerateFactorQueuesTest, GeneratesMoreQueues)
{
    const int n = 7;
    int values[n] = {0, 2, 3, 4, 5, 6, 8};
    Queue *factorQueues[n];
    generateFactorQueues(factorQueues, n, values);

    int expected0[] = {};
    int expected1[] = {2};
    int expected2[] = {3};
    int expected3[] = {2, 2};
    int expected4[] = {5};
    int expected5[] = {2, 3};
    int expected6[] = {2, 2, 2};

    assertQueueEquals(*factorQueues[0], expected0, 0);
    assertQueueEquals(*factorQueues[1], expected1, 1);
    assertQueueEquals(*factorQueues[2], expected2, 1);
    assertQueueEquals(*factorQueues[3], expected3, 2);
    assertQueueEquals(*factorQueues[4], expected4, 1);
    assertQueueEquals(*factorQueues[5], expected5, 2);
    assertQueueEquals(*factorQueues[6], expected6, 3);

    deleteQueues(factorQueues, n);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
