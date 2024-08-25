#include "../include/Chapter2-LinkedLists.hpp"
#include "../include/Chapter3-StacksAndQueues.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

class StackFixture : public testing::Test
{
public:
    MyStack kStack = MyStack({0, 1, 2, 3, 4});
    MyStack kStackNull = MyStack(nullptr);
    MyStack kllOneItem = MyStack(0);

    MyStackWithMin kStackWithMin = MyStackWithMin({0, 1, 2, 3, 4});
    MyStackWithMin2 kStackWithMin2 = MyStackWithMin2({0, 1, 2, 3, 4});
};

class QueueFixture : public testing::Test
{
public:
    MyQueue<int> kQueue = MyQueue<int>({0, 1, 2, 3, 4});
    MyQueue<int> kQueueNull = MyQueue<int>(nullptr);
    MyQueue<int> kQueueOneItem = MyQueue<int>(0);

    QueueWith2Stacks kQueue2 = QueueWith2Stacks({0, 1, 2, 3, 4});
    // QueueWith2Stacks kQueueNull2 = QueueWith2Stacks({nullptr});
    // QueueWith2Stacks kQueue2OneItem = QueueWith2Stacks({0});
};

TEST_F(StackFixture, stack_print)
{
    GTEST_ASSERT_EQ(kStack.print(), "4 3 2 1 0");
    GTEST_ASSERT_EQ(kStackNull.print(), "");
    GTEST_ASSERT_EQ(kllOneItem.print(), "0");
}

TEST_F(StackFixture, pop_push_peek_isEmpty)
{
    GTEST_ASSERT_EQ(kStack.print(), "4 3 2 1 0");
    kStack.push(5);
    GTEST_ASSERT_EQ(kStack.print(), "5 4 3 2 1 0");
    kStack.pop();
    GTEST_ASSERT_EQ(kStack.print(), "4 3 2 1 0");
    GTEST_ASSERT_EQ(kStack.peek(), 4);
    kStack.pop();
    kStack.pop();
    kStack.pop();
    kStack.pop();
    kStack.pop();
    GTEST_ASSERT_EQ(kStack.isEmpty(), true);
}

TEST_F(QueueFixture, remove_add_peek_isEmpty)
{
    GTEST_ASSERT_EQ(kQueue.print(), "0 1 2 3 4");
    kQueue.add(5);
    GTEST_ASSERT_EQ(kQueue.print(), "0 1 2 3 4 5");
    kQueue.remove();
    GTEST_ASSERT_EQ(kQueue.print(), "1 2 3 4 5");
    GTEST_ASSERT_EQ(kQueue.peek(), 1);
    kQueue.remove();
    kQueue.remove();
    kQueue.remove();
    kQueue.remove();
    kQueue.remove();
    GTEST_ASSERT_EQ(kQueue.isEmpty(), true);
}

TEST_F(StackFixture, stackWithMin)
{
    kStackWithMin.push(5);
    GTEST_ASSERT_EQ(kStackWithMin.print(), "5 4 3 2 1 0");
    kStackWithMin.pop();
    GTEST_ASSERT_EQ(kStackWithMin.print(), "4 3 2 1 0");
    GTEST_ASSERT_EQ(kStackWithMin.peek(), 4);
    kStackWithMin.pop();
    kStackWithMin.pop();
    kStackWithMin.pop();
    kStackWithMin.pop();
    kStackWithMin.pop();
    GTEST_ASSERT_EQ(kStackWithMin.isEmpty(), true);
    kStackWithMin.push(5);
    GTEST_ASSERT_EQ(kStackWithMin.getMin(), 5);
    kStackWithMin.push(3);
    GTEST_ASSERT_EQ(kStackWithMin.getMin(), 3);
    kStackWithMin.push(7);
    GTEST_ASSERT_EQ(kStackWithMin.getMin(), 3);

    kStackWithMin2.push(5);
    GTEST_ASSERT_EQ(kStackWithMin2.print(), "5 4 3 2 1 0");
    kStackWithMin2.pop();
    GTEST_ASSERT_EQ(kStackWithMin2.print(), "4 3 2 1 0");
    GTEST_ASSERT_EQ(kStackWithMin2.peek(), 4);
    kStackWithMin2.pop();
    kStackWithMin2.pop();
    kStackWithMin2.pop();
    kStackWithMin2.pop();
    kStackWithMin2.pop();
    GTEST_ASSERT_EQ(kStackWithMin2.isEmpty(), true);
    kStackWithMin2.push(5);
    GTEST_ASSERT_EQ(kStackWithMin2.getMin(), 5);
    kStackWithMin2.push(3);
    GTEST_ASSERT_EQ(kStackWithMin2.getMin(), 3);
    kStackWithMin2.push(7);
    GTEST_ASSERT_EQ(kStackWithMin2.getMin(), 3);
}

TEST_F(StackFixture, stackWithStacks_print_push_pop_peek)
{
    StackWithStacks stack = StackWithStacks(3, {0, 1, 2, 3, 4, 5, 6, 7});
    GTEST_ASSERT_EQ(stack.print(), "7 6 | 5 4 3 | 2 1 0");
    stack.push(5);
    GTEST_ASSERT_EQ(stack.print(), "5 7 6 | 5 4 3 | 2 1 0");
    stack.pop();
    GTEST_ASSERT_EQ(stack.print(), "7 6 | 5 4 3 | 2 1 0");
    GTEST_ASSERT_EQ(stack.peek(), 7);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    GTEST_ASSERT_EQ(stack.isEmpty(), true);
}

TEST_F(QueueFixture, QueueWith2Stacks){
   GTEST_ASSERT_EQ(kQueue2.print(), "0 1 2 3 4");
    kQueue2.add(5);
    kQueue2.add(6);
    GTEST_ASSERT_EQ(kQueue2.print(), "0 1 2 3 4 5 6");
    kQueue2.remove();
    GTEST_ASSERT_EQ(kQueue2.print(), "1 2 3 4 5 6");
    GTEST_ASSERT_EQ(kQueue2.peek(), 1);
    kQueue2.remove();
    kQueue2.remove();
    kQueue2.remove();
    kQueue2.remove();
    kQueue2.remove();
    kQueue2.remove();
    GTEST_ASSERT_EQ(kQueue2.isEmpty(), true);
}

TEST_F(StackFixture, sortStackCopying)
{
    MyStack s1 = MyStack({2, 1, 4, 1, 2, 3});
    MyStack s2 = sortStackWithCopying(s1);
    GTEST_ASSERT_EQ(s2.print(), "4 3 2 2 1 1");
}

TEST_F(StackFixture, sortStack)
{
    MyStack s1 = MyStack({2, 1, 4, 1, 2, 3});
    sortStack(s1);
    GTEST_ASSERT_EQ(s1.print(), "4 3 2 2 1 1");
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}