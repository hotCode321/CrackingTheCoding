#include "Chapter4-TreesAndGraphs.hpp"
#include <unordered_set>
#include "Utils.hpp"
#include <cmath>
#include <climits>
#include <algorithm>

void inOrderTraversal(NodeTree *node, std::vector<int> &output)
{
  if (node != nullptr)
  {
    inOrderTraversal(node->left, output);
    output.push_back(node->value);
    inOrderTraversal(node->right, output);
  }
}

void preOrderTraversal(NodeTree *node, std::vector<int> &output)
{
  if (node != nullptr)
  {
    output.push_back(node->value);
    preOrderTraversal(node->left, output);
    preOrderTraversal(node->right, output);
  }
}

void postOrderTraversal(NodeTree *node, std::vector<int> &output)
{
  if (node != nullptr)
  {
    postOrderTraversal(node->left, output);
    postOrderTraversal(node->right, output);
    output.push_back(node->value);
  }
}

void visit(NodeGraph *node, std::vector<int> &values, std::unordered_set<NodeGraph *> &visited)
{
  if (node != nullptr)
  {
    values.push_back(node->value);
    visited.insert(node);
    for (auto &&child : node->children)
    {
      if (visited.find(child) == visited.end())
      {
        visit(child, values, visited);
      }
    }
  }
}

std::vector<int> myDFSalgo(Graph *graph)
{
  std::unordered_set<NodeGraph *> visited;
  std::vector<int> values;
  NodeGraph *root = graph->nodes.front();
  visit(root, values, visited);
  return values;
}

std::vector<int> myDBSalgo(Graph *graph)
{
  std::unordered_set<NodeGraph *> visited;
  std::vector<int> values;
  NodeGraph *root = graph->nodes.front();

  MyQueue<NodeGraph *> queue;
  queue.add(root);
  values.push_back(root->value);
  visited.insert(root);
  while (!queue.isEmpty())
  {
    NodeGraph *curr = queue.remove().data;
    for (auto &&child : curr->children)
    {
      if (visited.find(child) == visited.end())
      {
        queue.add(child);
        values.push_back(child->value);
        visited.insert(child);
      }
    }
  }

  return values;
}

void visitHasRoute(NodeGraph *node, NodeGraph *start, NodeGraph *end, bool &isStart, bool &result, std::unordered_set<NodeGraph *> &visited, std::vector<int> &values)
{
  if (node != nullptr && !result)
  {
    if (node == start)
    {
      visited.clear();
      values.clear();
      values.push_back(node->value);
      isStart = true;
    }

    if (isStart && node == end)
    {
      result = true;
      values.push_back(node->value);
      return;
    }

    visited.insert(node);
    values.push_back(node->value);
    for (auto &&child : node->children)
    {
      if (visited.find(child) == visited.end())
      {
        visitHasRoute(child, start, end, isStart, result, visited, values);
      }
    }
    if (node == start)
    {
      isStart = false;
    }
  }
}

bool routeBetweenTwoNodes(Graph *directGraph, NodeGraph *start, NodeGraph *end, std::vector<int> &debug)
{
  debug.clear();
  bool result = false;
  NodeGraph *root = directGraph->nodes.front();
  std::unordered_set<NodeGraph *> visited;
  bool isStart = false;
  visitHasRoute(root, start, end, isStart, result, visited, debug);
  return result;
}

void find(NodeGraph *node, NodeGraph *target, bool &found, std::unordered_set<NodeGraph *> &visited, std::vector<int> &values)
{
  if (node != nullptr && !found)
  {
    values.push_back(node->value);
    visited.insert(node);
    if (node == target)
    {
      found = true;
      return;
    }
    for (auto &&child : node->children)
    {
      if (visited.find(child) == visited.end())
      {
        find(child, target, found, visited, values);
      }
    }
  }
}

NodeGraph *findNodeGraph(Graph *graph, NodeGraph *target, std::vector<int> &debug)
{
  debug.clear();
  std::unordered_set<NodeGraph *> visited;
  NodeGraph *root = graph->nodes.front();
  bool found = false;
  find(root, target, found, visited, debug);
  return found ? target : nullptr;
}

void iterate(NodeTree *node, std::vector<int> vec)
{
  if (vec.size() > 1)
  {
    size_t size = vec.size();
    int centerPos = size / 2;

    std::vector<int> left;
    std::vector<int> right;
    for (int i = 0; i < centerPos; i++)
    {
      left.emplace_back(vec[i]);
    }
    for (int i = centerPos + 1; i < size; i++)
    {
      right.emplace_back(vec[i]);
    }

    node->left = !left.empty() ? new NodeTree(left[left.size() / 2]) : nullptr;
    node->right = !right.empty() ? new NodeTree(right[right.size() / 2]) : nullptr;
    iterate(node->left, left);
    iterate(node->right, right);
  }
}

// 0 1 2 3 4 5 6 [7] 8 9 10 11 12 13
NodeTree *minimalTree(std::vector<int> vec)
{
  NodeTree *root = new NodeTree(vec[vec.size() / 2]);
  iterate(root, vec);
  return root;
}

bool isEqual(NodeTree *node1, NodeTree *node2)
{
  if (node1 == node2)
  { // both nullptr
    return true;
  }

  if (node1 && node2) // both not null, check children and value
  {
    return isEqual(node1->left, node2->left) && isEqual(node1->right, node2->right) && (node1->value == node2->value);
  }

  return false; // one is null the other is not
}

NodeTree *createMinimalBST(std::vector<int> vec, int start, int end)
{
  if (end < start)
  {
    return nullptr;
  }

  int mid = std::ceil(((float)start + end) / 2);
  NodeTree *n = new NodeTree(vec[mid]);
  n->left = createMinimalBST(vec, start, mid - 1);
  n->right = createMinimalBST(vec, mid + 1, end);
  return n;
}

NodeTree *createMinimalBST(std::vector<int> vec)
{
  return createMinimalBST(vec, 0, vec.size() - 1);
}

void listOfDepthsIt(NodeTree *node, std::vector<LinkedList *> &list, int depth)
{
  if (node)
  {
    if (list.size() > depth)
    {
      list[depth]->appendToTail(node->value);
    }
    else
    {
      list.push_back(new LinkedList(node->value));
    }

    depth++;
    listOfDepthsIt(node->left, list, depth);
    listOfDepthsIt(node->right, list, depth);
  }
}

std::vector<LinkedList *> listOfDepths(NodeTree *node)
{
  std::vector<LinkedList *> list;
  listOfDepthsIt(node, list, 0);
  return list;
}

int checkDepth(NodeTree *node, int depth, bool &isBalanced)
{
  if (!isBalanced)
  {
    return -1;
  }

  if (node)
  {
    depth++;
    int left = checkDepth(node->left, depth, isBalanced);
    int right = checkDepth(node->right, depth, isBalanced);
    if (std::abs(left - right) > 1)
    {
      isBalanced = false;
    }
    return left > right ? left : right;
  }

  return depth;
}

bool checkBalanced(NodeTree *node)
{
  bool isBalanced = true;
  checkDepth(node, 0, isBalanced);
  return isBalanced;
}

int checkHeight(NodeTree *node)
{
  if (node == nullptr)
  {
    return -1;
  }

  int leftHeight = checkHeight(node->left);
  if (leftHeight == INT_MIN)
  {
    return INT_MIN;
  }

  int rightHeight = checkHeight(node->right);
  if (rightHeight == INT_MIN)
  {
    return INT_MIN;
  }

  if (std::abs(leftHeight - rightHeight) > 1)
  {
    return INT_MIN;
  }
  else
  {
    int max = leftHeight > rightHeight ? leftHeight : rightHeight;
    return max + 1;
  }
}

bool isBalanced(NodeTree *node)
{
  return checkHeight(node) != INT_MIN;
}

struct minMax
{
  int min = INT_MAX;
  int max = INT_MIN;
  bool validated = false;
};

minMax validate(NodeTree *node, bool &stop)
{
  if (stop)
  {
    return {INT_MIN, INT_MAX, false};
  }

  if (node)
  {
    minMax leftData = validate(node->left, stop);
    if (!leftData.validated)
    {
      stop = true;
    }
    minMax rightData = validate(node->right, stop);
    minMax nodeData;
    std::cout << node->value << " " << std::endl;
    nodeData.max = std::max(node->value, rightData.max);
    nodeData.min = std::min(node->value, leftData.min);
    nodeData.validated = node->value >= leftData.max && node->value < rightData.min;
    if (!nodeData.validated)
    {
      stop = true;
    }
    return nodeData;
  }
  else
  {
    return {INT_MAX, INT_MIN, true};
  }
}

// TODO check if in case false, early stoppage is assured
bool isBinarySearchTree(NodeTree *node)
{
  if (node)
  {
    bool stop = false;
    return validate(node, stop).validated;
  }
  return false;
}

bool orderTraverse(NodeTree *node, int &lastPrinted)
{
  if (!node)
  {
    return true;
  }
  if (!orderTraverse(node->left, lastPrinted))
  {
    return false;
  }

  if (lastPrinted != INT_MAX && lastPrinted > node->value)
  {
    return false;
  }

  lastPrinted = node->value;

  if (!orderTraverse(node->right, lastPrinted))
  {
    return false;
  }

  return true;
}

bool isBSTOrderTraversal(NodeTree *node)
{
  if (node)
  {
    int lastPrinted(INT_MAX);
    return orderTraverse(node, lastPrinted);
  }
  return false;
}

bool bstMinMaxTraverse(NodeTree *node, int min, int max){
  if(!node){
    return true;
  }

  if(node->value < min || node->value > max){
    return false;
  }

  if(!bstMinMaxTraverse(node->left, min, node->value)){
    return false;
  }

  if(!bstMinMaxTraverse(node->right, node->value, max)){
    return false;
  }

  return true;
}

bool isBSTMinMax(NodeTree *node)
{
  if (node)
  {
    int min = INT_MIN;
    int max = INT_MAX;
    return bstMinMaxTraverse(node, min, max);
  }
  return false;
}

NodeTree *leftMostChild(NodeTree *n)
{
  if (!n)
  {
    return nullptr;
  }
  while (n->left)
  {
    n = n->left;
  }
  return n;
}

NodeTree *successor(NodeTree *n)
{
  if (!n)
  {
    return nullptr;
  }

  if (n->right)
  {
    return leftMostChild(n->right);
  }
  else
  {
    NodeTree *head = n;
    NodeTree *parent = n->parent;
    while (parent && parent->left != head)
    {
      head = parent;
      parent = head->parent;
    }
    return parent;
  }
}