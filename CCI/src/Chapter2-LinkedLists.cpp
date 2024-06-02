#include "Chapter2-LinkedLists.hpp"
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Example from the book
// Node *deleteNode(Node *head, int d)
// {
//     Node *n = head;

//     if (n->data == d)
//     {
//         return head->next; // moved head
//     }

//     while (n->next != nullptr)
//     {
//         if (n->next->data == d)
//         {
//             n->next = n->next->next;
//             return head; // head didn't change
//         }
//         n = n->next;
//     }
//     return head;
// }

// 2.1
// Remove Dups! Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed?
void removeDups(LinkedList &kList)
{
    std::unordered_set<int> set;
    Node *t = kList.head;
    if (t != nullptr)
    {
        set.insert(t->data);
    }
    else
    {
        return;
    }

    while (t->next != nullptr)
    {
        if (set.find(t->next->data) != set.end())
        {
            Node *toDelete = t->next;
            t->next = t->next->next;
            delete toDelete;
        }
        else
        {
            set.insert(t->next->data);
            t = t->next;
        }
    }
}

void removeDupsNoBuffer(LinkedList &kList)
{
    Node *t = kList.head;
    if (t == nullptr)
    {
        return;
    }

    while (t != nullptr)
    {
        Node *runner = t;
        while (runner->next != nullptr)
        {
            if (runner->next->data == t->data)
            {
                Node *toDelete = runner->next;
                runner->next = runner->next->next;
                delete toDelete;
            }
            else
            {
                runner = runner->next;
            }
        }
        t = t->next;
    }
}

Node *returnKthToLast(LinkedList &kList, int idx)
{
    Node *t = kList.head;
    if (t == nullptr)
    {
        return nullptr;
    }

    for (int i = 0; i < idx; i++)
    {
        if (t->next != nullptr)
        {
            t = t->next;
        }
        else
        {
            return nullptr;
        }
    }

    Node *slow = kList.head;
    while (t->next != nullptr)
    {
        t = t->next;
        slow = slow->next;
    }
    return slow;
}

int fillKthToLast(Node *head, int k, int &output)
{
    if (head == nullptr || head->next == nullptr)
    {
        return 0;
    }
    int index = fillKthToLast(head->next, k, output) + 1;
    if (index == k)
    {
        output = head->data;
    }
    return index;
}

bool deleteMiddleNode(Node *n)
{
    if (n == nullptr || n->next == nullptr)
    {
        return false;
    }
    n->data = n->next->data;
    Node *toDelete = n->next;
    n->next = n->next->next;
    delete toDelete;
    return true;
}

bool moveToTail(Node *nodeBefore, Node *&tail)
{
    Node *newTail = nodeBefore->next;
    nodeBefore->next = nodeBefore->next->next;
    tail->next = newTail;
    newTail->next = nullptr;
    tail = newTail;
    return true;
}

bool moveToHead(Node *nodeBefore, Node *&head)
{
    Node *newHead = nodeBefore->next;
    nodeBefore->next = nodeBefore->next->next;
    newHead->next = head;
    head = newHead;
    return true;
}

void partitionLinkedList(LinkedList &iLinkedList, int iX)
{
    Node *&head = iLinkedList.head;
    if (head == nullptr)
    {
        return;
    }

    Node *t = iLinkedList.head;
    while (t->next != nullptr)
    {
        if (t->next->data < iX)
        {
            moveToHead(t, head);
        }
        else
        {
            t = t->next;
        }
    }
}

// void partitionLinkedListCCI(Node *&node, int iX)
// {
//     Node* head = node;
//     Node* tail = node;

//     while(node != nullptr){
//         Node *next = node->next;
//         if(node->data < iX){
//             node->next = head;
//             head = node;
//         } else {
//             tail->next = node;
//             tail = node;
//         }
//         node = next;
//     }
//     tail->next = nullptr;
//     node = head;
// }

void partitionLinkedListCCI(Node *&node, int iX)
{
    Node *head = node;
    Node *tail = node;

    node = node->next;
    while (node != nullptr)
    {
        Node *next = node->next;
        if (node->data < iX)
        {
            node->next = head;
            head = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        node = next;
    }
    tail->next = nullptr;
    node = head;
}

LinkedList sumLists(LinkedList &l1, LinkedList &l2)
{
    Node *n1 = l1.head;
    Node *n2 = l2.head;
    LinkedList output = LinkedList(0);
    Node *r = output.head;

    int carry = 0;
    while (n1 != nullptr || n2 != nullptr)
    {
        int value = carry;
        if (n1 != nullptr)
        {
            value += n1->data;
            n1 = n1->next;
        }
        if (n2 != nullptr)
        {
            value += n2->data;
            n2 = n2->next;
        }

        if (value > 9)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        r->data = value % 10;
        if (n1 != nullptr || n2 != nullptr)
        {
            r->next = new Node(0);
            r = r->next;
        }
    }
    return output;
}

LinkedList sumListsReverse(LinkedList &l1, LinkedList &l2)
{
    Node *n1 = l1.head;
    Node *n2 = l2.head;
    Node *nr1 = nullptr;
    Node *nr2 = nullptr;

    while (n1 != nullptr && n2 != nullptr)
    {
        if (n1 != nullptr)
        {
            Node *next1 = n1->next;
            n1->next = nr1;
            nr1 = n1;
            n1 = next1;
        }
        else if (n2 != nullptr)
        {
            nr1->next = new Node(0);
            nr1 = nr1->next;
        }

        if (n2 != nullptr)
        {
            Node *next2 = n2->next;
            n2->next = nr2;
            nr2 = n2;
            n2 = next2;
        }
        else if (n1 != nullptr)
        {
            nr2->next = new Node(0);
            nr2 = nr2->next;
        }
    }

    l1.head = nr1;
    l2.head = nr2;

    return sumLists(l1, l2);
}

void reverseList(LinkedList &l1)
{
    Node *n1 = l1.head;
    Node *chain = nullptr;
    Node *next = nullptr;

    while (n1 != nullptr)
    {
        next = n1->next;
        n1->next = chain;
        chain = n1;
        n1 = next;
    }
    l1.head = chain;
}

void bubbleHeadToTail(LinkedList &l1)
{

    LinkedList output = LinkedList(0);
    output.head->next = l1.head;
    Node *n1 = output.head;

    while (n1->next->next != nullptr)
    {
        Node *lost = n1->next->next->next;
        n1->next->next->next = n1->next;
        n1->next = n1->next->next;
        n1->next->next->next = lost;
        n1 = n1->next;
    }
    l1.head = output.head->next;
}

void popTail(LinkedList &stack)
{
    Node *n1 = stack.head;
    if (n1->next == nullptr)
    {
        n1 == nullptr;
        return;
    }

    while (n1->next->next != nullptr)
    {
        n1 = n1->next;
    }

    n1->next = n1->next->next;
}

void appendToTail(LinkedList &stack, Node *node)
{
    Node *n1 = stack.head;

    while (n1->next != nullptr)
    {
        n1 = n1->next;
    }

    n1->next = node;
}

bool isPalindrome_Stack1(LinkedList &l1)
{
    int size = 1;
    for (Node *n1 = l1.head; n1->next != nullptr; n1 = n1->next)
    {
        size += 1;
    }

    int half = size / 2;
    bool isOdd = size % 2;
    int counter = 1;
    LinkedList stack = LinkedList(l1.head);
    Node *n1 = l1.head;
    while (n1 != nullptr)
    {
        Node *next = n1->next;
        if (counter < half)
        {
            n1 = next;
        }
        else if (counter == half)
        {
            n1->next = nullptr;
            if (isOdd)
            {
                n1 = next->next;
            }
            else
            {
                n1 = next;
            }
        }
        else if (stack.getLastNode()->data == n1->data)
        {
            Node *hs = stack.head;
            if (hs->next == nullptr)
            {
                return true;
            }
            while (hs->next->next != nullptr)
            {
                hs = hs->next;
            }

            hs->next = hs->next->next; //to nullptr
            n1 = next;
        }
        else
        {
            return false;
        }
        counter++;
    }

    return true;
}

bool isPalindromeRecurse(LinkedList &l1)
{
    bool isPalindrome = true;
    int size = 1;
    for (Node *n1 = l1.head; n1->next != nullptr; n1 = n1->next)
    {
        size++;
    }
    recurse(l1.head, size, isPalindrome);
    return isPalindrome;
}

Node *recurse(Node *n, int size, bool &isPalindrome)
{
    if (size == 1)
    {
        return n->next;
    }
    else if (size == 0)
    {
        return n;
    }

    Node *next = recurse(n->next, size - 2, isPalindrome);
    // cout << "f: " << &n << " " << n->data << endl;
    // cout << "b: " << &next->data << " " << next->data << endl;
    if (n->data != next->data)
    {
        isPalindrome = false;
    }
    return next->next;
}

bool isPalindromeSlowRunner(LinkedList &l1)
{
    Node *slow = l1.head;
    Node *fast = l1.head;
    Node *chain = nullptr;
    Node *next = nullptr;

    while (fast != nullptr && fast->next != nullptr)
    {
        next = slow->next;
        fast = fast->next->next;
        slow->next = chain;
        chain = slow;
        slow = next;
    }

    if (fast != nullptr)
    { // its odd list
        slow = slow->next;
    }

    while (chain != nullptr)
    {
        if (chain->data != slow->data)
        {
            return false;
        }
        else
        {
            slow = slow->next;
            chain = chain->next;
        }
    }

    return true;
}

Node *popHead(LinkedList &l1)
{
    Node *n1 = l1.head;
    if (n1->next == nullptr)
    {
        l1.head = nullptr;
    }
    else
    {
        l1.head = n1->next;
    }

    return n1;
}

Node *firstInterSectionNode_Set(LinkedList &l1, LinkedList &l2)
{
    std::unordered_set<Node *> l1Nodes;
    std::unordered_set<Node *> l2Nodes;

    Node *n1 = l1.head;
    Node *n2 = l2.head;

    while (n1 != nullptr || n2 != nullptr)
    {
        if (l1Nodes.find(n2) != l1Nodes.end())
        {
            return n2;
        }
        else if (l2Nodes.find(n1) != l2Nodes.end())
        {
            return n1;
        }

        if (n1 != nullptr)
        {
            l1Nodes.insert(n1);
            n1 = n1->next;
        }
        if (n2 != nullptr)
        {
            l2Nodes.insert(n2);
            n2 = n2->next;
        }
    }
    return nullptr;
}

Node *firstInterSectionNode_Chop(LinkedList &l1, LinkedList &l2)
{
    Node *n1 = l1.head;
    Node *n2 = l2.head;
    int sizel1 = 1;
    int sizel2 = 1;

    while (n1->next != nullptr || n2->next != nullptr)
    {
        if (n1->next != nullptr)
        {
            sizel1++;
            n1 = n1->next;
        }

        if (n2->next != nullptr)
        {
            sizel2++;
            n2 = n2->next;
        }
    }

    if (n1 != n2)
    {
        return nullptr;
    }

    Node *startl1 = l1.head;
    Node *startl2 = l2.head;
    if (sizel1 > sizel2)
    {
        int diff = sizel1 - sizel2;
        for (int i = 0; i < diff; i++)
        {
            startl1 = startl1->next;
        }
    }
    else if (sizel2 > sizel1)
    {
        int diff = sizel2 - sizel1;
        for (int i = 0; i < diff; i++)
        {
            startl2 = startl2->next;
        }
    }

    while (startl1 != nullptr)
    { // or startl2
        if (startl1 == startl2)
        {
            return startl1;
        }
        else
        {
            startl1 = startl1->next;
            startl2 = startl2->next;
        }
    }

    return nullptr;
}

Node *loopDetection_Set(LinkedList &l1)
{
    std::unordered_set<Node *> nodes;

    Node *n1 = l1.head;
    while (n1 != nullptr)
    {
        if (nodes.find(n1) != nodes.end())
        {
            return n1;
        }
        else
        {
            nodes.insert(n1);
        }
        n1 = n1->next;
    }
    return nullptr;
}

Node *returnTail(LinkedList &l1){
    Node *n1 = l1.head;
    if(n1 == nullptr){
        return nullptr;
    }

    while(n1 != nullptr){
        if(n1->next == nullptr){
            return n1;
        }
        n1 = n1->next;
    }

    return nullptr;
}

Node *loopDetectionSlowRunner(LinkedList &l1)
{
    Node *slow = l1.head;
    Node *fast = l1.head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }

    if(fast == nullptr || fast->next == nullptr){
        return nullptr; // no loop
    }

    slow = l1.head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
