#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Node
{
public:
    Node *next = nullptr;
    int data;

    Node(Node *iNext, int iData)
    {
        this->next = iNext;
        data = iData;
    }

    void appendToTail(int d)
    {
        Node *end = new Node(nullptr, d);
        Node *n = this;
        while (n->next != nullptr)
        {
            n = n->next;
        }
        n->next = end;
    }

    void insert(int data, int index)
    {
        Node *newNode = new Node(nullptr, data);
        Node *head = this;

        if (index == 0)
        {
            newNode->next == head;
            head = newNode;
            return;
        }

        Node *t = head;
        for (int i = 0; i < index - 1; i++)
        {
            if (t == nullptr)
            {
                std::cerr << "Error: Index out of range" << std::endl;
                return;
            }
            t = t->next;
        }

        newNode->next = t->next;
        t->next = newNode;
    }

    Node* deleteNode(int d)
    {
        Node* curr = this;
        Node* toDelete = nullptr;

        if (curr->data == d)
        {
            curr = curr->next;
            delete this;
            return curr;
        }

        while (curr->next != nullptr)
        {
            if (curr->next->data == d)
            {
                toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;
                return this; // head didn't change
            }
            curr = curr->next;
        }
        return this;
    }

    std::string print()
    {
        Node *head = this;
        std::stringstream ss;
        Node *n = head;
        while (n != nullptr)
        {
            ss << n->data << " ";
            n = n->next;
        }
        std::string output = std::string(ss.str());
        output.pop_back();
        return output;
    }
};

class NodeD
{
public:
    NodeD *next = nullptr;
    NodeD *previous = nullptr;
    int data;

    NodeD(NodeD *iNext, NodeD *iPrevious, int iData) : next(iNext), previous(iPrevious), data(iData) {}

    void insert(int data, int index)
    {
        NodeD *newNode = new NodeD(nullptr, nullptr, data);
        NodeD *head = this;
        if (index == 0)
        {
            newNode->next == head;
            head = newNode;
            return;
        }

        NodeD *t = head;
        for (int i = 0; i < index - 1; i++)
        {
            if (t == nullptr)
            {
                std::cerr << "Error: Index out of range" << std::endl;
                return;
            }
            t = t->next;
        }

        newNode->next = t->next;
        newNode->previous = t;
        if (t->next != nullptr)
        {
            t->next->previous = newNode;
            t->next = newNode;
        }
    }

    NodeD *deleteNode(int d)
    {
        NodeD *curr = this;
        NodeD* toDelete = nullptr;

        if (curr->data == d)
        {
            curr = curr->next;
            delete this;
            return curr; // moved head
        }

        while (curr->next != nullptr)
        {
            if (curr->next->data == d)
            {
                toDelete = curr->next;
                curr->next = curr->next->next;
                if (curr->next->next != nullptr)
                {
                    curr->next->next->previous = curr;
                }
                return this; // head didn't change
            }
            curr = curr->next;
        }
        return this;
    }

    std::string print()
    {
        NodeD *head = this;
        std::stringstream ss;
        NodeD *n = head;
        while (n != nullptr)
        {
            ss << n->data << " ";
            n = n->next;
        }
        std::string output = std::string(ss.str());
        output.pop_back();
        return output;
    }
};

// void insertAtIdx(Node *head, int data, int index);
Node *makeSingleList(std::vector<int> list);
Node *makeStaticSingleList();
Node *makeStaticSingleList_2();
NodeD *makeDoubleList(std::vector<int> list);
NodeD *makeStaticDoubleList();
void deleteNode(Node *head, int key);
void removeDups(Node *head);