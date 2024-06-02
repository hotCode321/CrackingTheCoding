#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Utils.hpp"


void removeDups(LinkedList &iLinkedList);

void removeDupsNoBuffer(LinkedList &kList);

Node *returnKthToLast(LinkedList &kList, int idx);

int fillKthToLast(Node *iNode, int k, int &output); // recursive

bool deleteMiddleNode(Node *n);

// bool moveToTheEnd(LinkedList &iLinkedList, Node *iNode);

void partitionLinkedList(LinkedList &iLinkedList, int iX);

void partitionLinkedListCCI(Node *&node, int iX);

LinkedList sumLists(LinkedList &l1, LinkedList &l2);

LinkedList sumListsReverse(LinkedList &l1, LinkedList &l2);

void bubbleHeadToTail(LinkedList &l1);

void reverseList(LinkedList &l1);

Node *recurse(Node *n, int size, bool &isPalindrome);
bool isPalindromeRecurse(LinkedList &l1);

bool isPalindrome_Stack1(LinkedList &l1);

bool isPalindromeSlowRunner(LinkedList &l1);

Node *firstInterSectionNode_Set(LinkedList &l1, LinkedList &l2);
Node *firstInterSectionNode_Chop(LinkedList &l1, LinkedList &l2);
Node *popHead(LinkedList &l1);
Node *loopDetection_Set(LinkedList &l1);
Node *loopDetectionSlowRunner(LinkedList &l1);
Node *returnTail(LinkedList &l1);