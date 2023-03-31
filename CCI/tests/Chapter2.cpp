#include "../include/Chapter2-LinkedLists.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <gtest/gtest.h>

namespace
{
}

// TEST(Chapter1, insertSingleList)
// {

//     std::string initialList = node1->print();
//     node1->insert(4, 1);
//     std::string outputList = node1->print();

//     GTEST_ASSERT_EQ(initialList, "1 2 3 4 5");
//     GTEST_ASSERT_EQ(outputList, "1 4 2 3 4 5");
// }

// TEST(Chapter1, insertDoubleList)
// {

//     std::string initialList = nodeD1->print();
//     nodeD1->insert(4, 1);
//     std::string outputList = nodeD1->print();

//     GTEST_ASSERT_EQ(initialList, "1 2 3 4 5");
//     GTEST_ASSERT_EQ(outputList, "1 4 2 3 4 5");
// }

// TEST(Chapter1, deleteSingleList)
// {
//     Node *staticNode1 = makeStaticSingleList();
//     std::string initialList = staticNode1->print();
//     auto &&deletedNode = staticNode1->next;
//     staticNode1->deleteNode(2);
//     std::string outputList = staticNode1->print();

//     GTEST_ASSERT_FALSE(deletedNode->data == 2);
//     GTEST_ASSERT_EQ(initialList, "1 2 3 4 5");
//     GTEST_ASSERT_EQ(outputList, "1 3 4 5");
// }

// TEST(Chapter1, deleteDoubleList)
// {
//     NodeD *staticNodeD1 = makeStaticDoubleList();
//     std::string initialList = staticNodeD1->print();
//     auto &&deletedNode = staticNodeD1->next;
//     staticNodeD1->deleteNode(3);
//     std::string outputList = staticNodeD1->print();

//     GTEST_ASSERT_FALSE(deletedNode->data == 3);
//     GTEST_ASSERT_EQ(initialList, "1 2 3 4 5");
//     GTEST_ASSERT_EQ(outputList, "1 2 4 5");
// }

TEST(Chapter1, removeDups)
{
    Node *staticNode1 = makeStaticSingleList_2();
    std::string initialList = staticNode1->print();
    removeDups(staticNode1);
    std::string outputList = staticNode1->print();

    GTEST_ASSERT_EQ(initialList, "1 2 2 4 5 5");
    GTEST_ASSERT_EQ(outputList, "1 2 4 5");
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}