#include "Chapter2-LinkedLists.hpp"
#include <iostream>
#include <algorithm>
#include <unordered_set>

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

void deleteNode(Node *head, int key)
{
    if (head == nullptr)
    {
        return;
    }

    Node *temp = head;
    Node *prev = nullptr;

    if (temp->data == key)
    {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != nullptr && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        return;
    }

    prev->next = temp->next;
    delete temp;
}

Node *makeSingleList(std::vector<int> list)
{
    Node *slow = nullptr;
    Node *fast = nullptr;
    for (int i = list.size() - 1; i >= 0; i--)
    {
        fast = new Node(slow, list[i]);
        slow = fast;
    }
    return fast;
}

Node *makeStaticSingleList()
{
    static Node *node5 = new Node(nullptr, 5);
    static Node *node4 = new Node(node5, 4);
    static Node *node3 = new Node(node4, 3);
    static Node *node2 = new Node(node3, 2);
    static Node *staticNode1 = new Node(node2, 1);
    return staticNode1;
}

Node *makeStaticSingleList_2()
{
    static Node *node6 = new Node(node6, 5);
    static Node *node5 = new Node(node6, 5);
    static Node *node4 = new Node(node5, 4);
    static Node *node3 = new Node(node4, 2);
    static Node *node2 = new Node(node3, 2);
    static Node *staticNode1 = new Node(node2, 1);
    return staticNode1;
}

NodeD *makeStaticDoubleList()
{
    static NodeD *nodeD2 = new NodeD(nullptr, nullptr, 2);
    static NodeD *nodeD3 = new NodeD(nullptr, nullptr, 3);
    static NodeD *nodeD4 = new NodeD(nullptr, nullptr, 4);
    static NodeD *nodeD5 = new NodeD(nullptr, nullptr, 5);
    static NodeD *staticNodeD1 = new NodeD(nodeD2, nullptr, 1);

    nodeD2->next = nodeD3;
    nodeD2->previous = staticNodeD1;
    nodeD3->next = nodeD4;
    nodeD3->previous = nodeD2;
    nodeD4->next = nodeD5;
    nodeD4->previous = nodeD3;
    nodeD5->next = nullptr;
    nodeD5->previous = nodeD4;
    return staticNodeD1;
}

NodeD *makeDoubleList(std::vector<int> list)
{
    NodeD *current = nullptr;
    NodeD *previous = nullptr;
    for (int i = 0; i < list.size(); i++)
    {
        current = new NodeD(nullptr, previous, list[i]);
        previous = current;
    }

    NodeD *next = nullptr;
    for (int i = list.size() - 1; i >= 0; i--)
    {
        current->next = next;
        next = current;
        if (current->previous)
        {
            current = current->previous;
        }
    }

    return current;
}

// 2.1
// Remove Dups! Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed?
void removeDups(Node *head)
{
    std::unordered_set<int> set;
    Node *curr = head;
    Node *previous = nullptr;
    // Node *toDelete = nullptr;
    while (curr)
    {
        if (set.find(curr->data) != set.end())
        {
            previous->next = curr->next;
            delete curr;
            curr = previous->next;
        }
        else
        {
            set.insert(curr->data);
            previous = curr;
            curr = curr->next;
        }
    }
}