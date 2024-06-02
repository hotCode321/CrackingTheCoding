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
    // DoubleLinkedList kDoubleLinkedList = DoubleLinkedList({0, 1, 2, 3, 4});
    // DoubleLinkedList kdllNull = DoubleLinkedList(nullptr);
    // DoubleLinkedList kdllOneItem = DoubleLinkedList(0);
};

TEST_F(StackFixture, stack_print)
{
    GTEST_ASSERT_EQ(kStack.print(), "4 3 2 1 0");
    GTEST_ASSERT_EQ(kStackNull.print(), "");
    GTEST_ASSERT_EQ(kllOneItem.print(), "0");
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}