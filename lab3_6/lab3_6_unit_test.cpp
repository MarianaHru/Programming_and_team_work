#include "gtest/gtest.h"
#include "lab3_6.h"
#include <vector>
#include <algorithm>

std::vector<int> queueToVector(const Queue &q)
{
    std::vector<int> result;
    Node *current = q.front;
    while (current)
    {
        result.push_back(current->data);
        current = current->next;
    }
    return result;
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
    ASSERT_EQ(queueToVector(q), (std::vector<int>{2, 3, 3}));
    clearQueue(q);

    initQueue(q);
    buildFactorQueue(30, q);
    ASSERT_EQ(queueToVector(q), (std::vector<int>{2, 3, 5}));
    clearQueue(q);

    initQueue(q);
    buildFactorQueue(1, q);
    ASSERT_TRUE(queueToVector(q).empty());
    clearQueue(q);
}

TEST(GenerateFactorQueuesTest, GeneratesCorrectQueues)
{
    const int n = 5;
    Queue *factorQueues[n];
    generateFactorQueues(factorQueues, n);

    ASSERT_NE(factorQueues[0], nullptr);
    EXPECT_EQ(queueToVector(*factorQueues[0]), (std::vector<int>{}));

    ASSERT_NE(factorQueues[1], nullptr);
    EXPECT_EQ(queueToVector(*factorQueues[1]), (std::vector<int>{2}));

    ASSERT_NE(factorQueues[2], nullptr);
    EXPECT_EQ(queueToVector(*factorQueues[2]), (std::vector<int>{3}));

    ASSERT_NE(factorQueues[3], nullptr);
    EXPECT_EQ(queueToVector(*factorQueues[3]), (std::vector<int>{2, 2}));

    ASSERT_NE(factorQueues[4], nullptr);
    EXPECT_EQ(queueToVector(*factorQueues[4]), (std::vector<int>{5}));

    deleteQueues(factorQueues, n);
}

TEST(GenerateFactorQueuesTest, GeneratesMoreQueues)
{
    const int n = 7;
    Queue *factorQueues[n];
    generateFactorQueues(factorQueues, n);

    ASSERT_NE(factorQueues[0], nullptr);
    EXPECT_EQ(queueToVector(*factorQueues[0]), (std::vector<int>{}));

    ASSERT_NE(factorQueues[1], nullptr);
    EXPECT_EQ(queueToVector(*factorQueues[1]), (std::vector<int>{2}));

    ASSERT_NE(factorQueues[2], nullptr);
    EXPECT_EQ(queueToVector(*factorQueues[2]), (std::vector<int>{3}));

    ASSERT_NE(factorQueues[3], nullptr);
    EXPECT_EQ(queueToVector(*factorQueues[3]), (std::vector<int>{2, 2}));

    ASSERT_NE(factorQueues[4], nullptr);
    EXPECT_EQ(queueToVector(*factorQueues[4]), (std::vector<int>{5}));

    ASSERT_NE(factorQueues[5], nullptr);
    EXPECT_EQ(queueToVector(*factorQueues[5]), (std::vector<int>{2, 3}));

    ASSERT_NE(factorQueues[6], nullptr);
    EXPECT_EQ(queueToVector(*factorQueues[6]), (std::vector<int>{2, 2, 2}));

    deleteQueues(factorQueues, n);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}