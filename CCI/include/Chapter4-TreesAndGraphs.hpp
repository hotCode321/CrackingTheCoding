#include <vector>
#include "Utils.hpp"

void inOrderTraversal(NodeTree *node, std::vector<int> &output);
void preOrderTraversal(NodeTree *node, std::vector<int> &output);
void postOrderTraversal(NodeTree *node, std::vector<int> &output);
std::vector<int> myDFSalgo(Graph *graph);
std::vector<int> myDBSalgo(Graph *graph);
// 4.1
bool routeBetweenTwoNodes(Graph *directGraph, NodeGraph *start, NodeGraph *end, std::vector<int> &debug);
NodeGraph *findNodeGraph(Graph *graph, NodeGraph *target, std::vector<int> &debug);
// 4.2
NodeTree* minimalTree(std::vector<int> vec);
bool isEqual(NodeTree *node1, NodeTree *node2);
NodeTree *createMinimalBST(std::vector<int> vec);
// 4.3
std::vector<LinkedList *> listOfDepths(NodeTree *node);
// 4.4
bool checkBalanced(NodeTree *node); // My solution
bool isBalanced(NodeTree *node); // Their solution
// 4.5
bool isBinarySearchTree(NodeTree *node); // My solution
bool isBSTOrderTraversal(NodeTree *node); // Their solution number 1
bool isBSTMinMax(NodeTree *node); // Their solution number 2
// 4.6
