#include "Utils.hpp"
#include "Objects.hpp"

NodeTree *getIncompleteBinaryTree()
{
  NodeTree *n3_1 = new NodeTree(3);
  NodeTree *n3_2 = new NodeTree(7);
  NodeTree *n3_3 = new NodeTree(30);

  NodeTree *n2_1 = new NodeTree(5, n3_1, n3_2);
  NodeTree *n2_2 = new NodeTree(20, nullptr, n3_3);

  NodeTree *n1 = new NodeTree(10, n2_1, n2_2);
  return n1;
}

// From book
NodeTree *getBinarySearchTree()
{
  NodeTree *n3_1 = new NodeTree(2);
  NodeTree *n3_2 = new NodeTree(6);
  NodeTree *n3_3 = new NodeTree(20);

  NodeTree *n2_1 = new NodeTree(4, n3_1, n3_2);
  NodeTree *n2_2 = new NodeTree(10, nullptr, n3_3);

  NodeTree *root = new NodeTree(8, n2_1, n2_2);
}

// From book
NodeTree *getNotABinarySearchTree()
{
  NodeTree *n3_1 = new NodeTree(2);
  NodeTree *n3_2 = new NodeTree(12);
  NodeTree *n3_3 = new NodeTree(20);

  NodeTree *n2_1 = new NodeTree(4, n3_1, n3_2);
  NodeTree *n2_2 = new NodeTree(10, nullptr, n3_3);

  NodeTree *root = new NodeTree(8, n2_1, n2_2);
}

// My version, 10 and 20 are modified
NodeTree *getMyBinarySearchTree()
{
  NodeTree *n3_1 = new NodeTree(2);
  NodeTree *n3_2 = new NodeTree(6);
  NodeTree *n3_3 = new NodeTree(10);

  NodeTree *n2_1 = new NodeTree(4, n3_1, n3_2);
  NodeTree *n2_2 = new NodeTree(20, n3_3, nullptr);

  NodeTree *root = new NodeTree(8, n2_1, n2_2);
}

// My version, 10 and 20 are modified
NodeTree *getUnbalancedBinaryTree()
{
  NodeTree *n4_1 = new NodeTree(9);

  NodeTree *n3_1 = new NodeTree(2);
  NodeTree *n3_2 = new NodeTree(6);
  NodeTree *n3_3 = new NodeTree(10, n4_1);

  NodeTree *n2_1 = new NodeTree(4, n3_1, n3_2);
  NodeTree *n2_2 = new NodeTree(20, n3_3, nullptr);

  NodeTree *root = new NodeTree(8, n2_1, n2_2);
}

Graph *getSimpleGraph()
{
  NodeGraph *n0 = new NodeGraph(0);
  NodeGraph *n5 = new NodeGraph(5);
  NodeGraph *n1 = new NodeGraph(1);
  NodeGraph *n4 = new NodeGraph(4);
  NodeGraph *n2 = new NodeGraph(2);
  NodeGraph *n3 = new NodeGraph(3);
  n0->children = {n1, n4, n5};
  n1->children = {n3, n4};
  n3->children = {n2, n4};
  n2->children = {n1};
  std::vector<NodeGraph *> nodes = {n0};
  return new Graph(nodes);
}

NodeTree *getMediumBST()
{
  NodeTree *n5_1 = new NodeTree(42);
  NodeTree *n5_2 = new NodeTree(62);
  NodeTree *n5_3 = new NodeTree(64);

  NodeTree *n4_1 = new NodeTree(25);
  NodeTree *n4_2 = new NodeTree(46, n5_1);
  NodeTree *n4_3 = new NodeTree(55);
  NodeTree *n4_4 = new NodeTree(63, n5_2, n5_3);
  NodeTree *n4_5 = new NodeTree(70);

  NodeTree *n3_1 = new NodeTree(16, nullptr, n4_1);
  NodeTree *n3_2 = new NodeTree(53, n4_2, n4_3);
  NodeTree *n3_3 = new NodeTree(65, n4_4, n4_5);

  NodeTree *n2_1 = new NodeTree(41, n3_1, n3_2);
  NodeTree *n2_2 = new NodeTree(74, n3_3);

  NodeTree *n1 = new NodeTree(60, n2_1, n2_2);

  n2_1->parent = n1;
  n2_2->parent = n1;

  n3_1->parent = n2_1;
  n3_2->parent = n2_1;
  n3_3->parent = n2_2;

  n4_1->parent = n3_1;
  n4_2->parent = n3_2;
  n4_3->parent = n3_2;
  n4_4->parent = n3_3;
  n4_5->parent = n3_3;

  n5_1->parent = n4_2;
  n5_2->parent = n4_4;
  n5_3->parent = n4_4;

  return n1;
}