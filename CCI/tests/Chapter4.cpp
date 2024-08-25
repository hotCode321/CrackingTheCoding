#include <iostream>
#include <sstream>
#include <algorithm>
#include <gtest/gtest.h>
#include "Chapter4-TreesAndGraphs.hpp"
#include "Objects.hpp"

using namespace std;

class TreeFixture : public testing::Test
{
public:
    NodeTree *kIncBinaryTree = getIncompleteBinaryTree();
};

class GraphFixture : public testing::Test
{
public:
    Graph *kSimpleGraph = getSimpleGraph();
};

TEST_F(TreeFixture, inOrderTraversal)
{
    std::vector<int> values;
    inOrderTraversal(kIncBinaryTree, values);
    std::vector<int> expected = {3, 5, 7, 10, 20, 30};
    GTEST_ASSERT_EQ(values, expected);
}

TEST_F(TreeFixture, preOrderTraversal)
{
    std::vector<int> values;
    preOrderTraversal(kIncBinaryTree, values);
    std::vector<int> expected = {10, 5, 3, 7, 20, 30};
    GTEST_ASSERT_EQ(values, expected);
}

TEST_F(TreeFixture, postOrderTraversal)
{
    std::vector<int> values;
    postOrderTraversal(kIncBinaryTree, values);
    std::vector<int> expected = {3, 7, 5, 30, 20, 10};
    GTEST_ASSERT_EQ(values, expected);
}

TEST_F(GraphFixture, myDFSalgo)
{
    std::vector<int> values = myDFSalgo(kSimpleGraph);
    std::vector<int> expected = {0, 1, 3, 2, 4, 5};
    GTEST_ASSERT_EQ(values, expected);
}

TEST_F(GraphFixture, myDBSalgo)
{
    std::vector<int> values = myDBSalgo(kSimpleGraph);
    std::vector<int> expected = {0, 1, 4, 5, 3, 2};
    GTEST_ASSERT_EQ(values, expected);
}

TEST_F(GraphFixture, routeBetweenTwoNodes)
{
    NodeGraph *n0 = kSimpleGraph->nodes.front();
    NodeGraph *n1 = n0->children.at(0);
    NodeGraph *n4 = n0->children.at(1);
    NodeGraph *n5 = n0->children.at(2);
    NodeGraph *n3 = n1->children.at(0);
    NodeGraph *n2 = n3->children.at(0);

    std::vector<int> debugValues;
    GTEST_ASSERT_EQ(n3->value, 3);
    GTEST_ASSERT_EQ(n4->value, 4);
    bool result = routeBetweenTwoNodes(kSimpleGraph, n3, n4, debugValues);
    GTEST_ASSERT_TRUE(result);

    GTEST_ASSERT_EQ(n5->value, 5);
    GTEST_ASSERT_FALSE(routeBetweenTwoNodes(kSimpleGraph, n3, n5, debugValues));
    GTEST_ASSERT_TRUE(routeBetweenTwoNodes(kSimpleGraph, n0, n4, debugValues));
    GTEST_ASSERT_TRUE(routeBetweenTwoNodes(kSimpleGraph, n2, n1, debugValues));
}

TEST_F(GraphFixture, findNodeGraph)
{
    NodeGraph *n0 = kSimpleGraph->nodes.front();
    NodeGraph *n1 = n0->children.at(0);
    NodeGraph *n4 = n0->children.at(1);
    std::vector<int> debug;
    std::vector<int> expected;
    GTEST_ASSERT_EQ(findNodeGraph(kSimpleGraph, n1, debug), n1);
    expected = {0, 1};
    GTEST_ASSERT_EQ(debug, expected);

    GTEST_ASSERT_EQ(findNodeGraph(kSimpleGraph, n4, debug), n4);
    expected = {0, 1, 3, 2, 4};
    GTEST_ASSERT_EQ(debug, expected);
}

TEST_F(GraphFixture, routeBetweenTwoNodesWithFind){
    NodeGraph *n0 = kSimpleGraph->nodes.front();
    NodeGraph *n1 = n0->children.at(0);
    NodeGraph *n4 = n0->children.at(1);
    NodeGraph *n5 = n0->children.at(2);
    NodeGraph *n3 = n1->children.at(0);
    NodeGraph *n2 = n3->children.at(0);

    std::vector<int> debug;
    Graph *g4 = new Graph({n4});
    Graph *g3 = new Graph({n3});
    Graph *g0 = new Graph({n0});
    Graph *g2 = new Graph({n2});

    GTEST_ASSERT_TRUE(findNodeGraph(g3, n4, debug));
    GTEST_ASSERT_FALSE(findNodeGraph(g3, n5, debug));
    GTEST_ASSERT_TRUE(findNodeGraph(g0, n4, debug));
    GTEST_ASSERT_TRUE(findNodeGraph(g2, n1, debug));
}

TEST_F(TreeFixture, minimalTree){
    std::vector<int> vec = {2, 4, 6, 8, 10, 20};
    NodeTree* myTree = minimalTree(vec);
    NodeTree* binarySearchTree = getMyBinarySearchTree();
    GTEST_ASSERT_TRUE(isEqual(myTree, binarySearchTree));

    NodeTree *bookTree = createMinimalBST(vec);
    GTEST_ASSERT_TRUE(isEqual(bookTree, binarySearchTree));
}

TEST_F(TreeFixture, listOfDepths){
    NodeTree* myBinarySearchTree = getMyBinarySearchTree();
    std::vector<LinkedList *> list = listOfDepths(myBinarySearchTree);
    GTEST_ASSERT_EQ(list[0]->print(), "8");
    GTEST_ASSERT_EQ(list[1]->print(), "4 20");
    GTEST_ASSERT_EQ(list[2]->print(), "2 6 10");
}

TEST_F(TreeFixture, checkBalanced){
    NodeTree* myBinarySearchTree = getMyBinarySearchTree();
    GTEST_ASSERT_TRUE(checkBalanced(myBinarySearchTree));
    GTEST_ASSERT_TRUE(isBalanced(myBinarySearchTree));

    NodeTree* unbalancedBinaryTree = getUnbalancedBinaryTree();
    GTEST_ASSERT_FALSE(checkBalanced(unbalancedBinaryTree));
    GTEST_ASSERT_FALSE(isBalanced(unbalancedBinaryTree));
}

TEST_F(TreeFixture, isBST){
    GTEST_ASSERT_TRUE(isBinarySearchTree(getMyBinarySearchTree()));
    GTEST_ASSERT_FALSE(isBinarySearchTree(getNotABinarySearchTree()));
    GTEST_ASSERT_TRUE(isBSTOrderTraversal(getMyBinarySearchTree()));
    GTEST_ASSERT_FALSE(isBSTOrderTraversal(getNotABinarySearchTree()));
    GTEST_ASSERT_TRUE(isBSTMinMax(getMyBinarySearchTree()));
    GTEST_ASSERT_FALSE(isBSTMinMax(getNotABinarySearchTree()));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}