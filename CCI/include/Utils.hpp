#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Node
{
public:
    Node(int iData, Node *iNext = nullptr)
    {
        this->data = iData;
        this->next = iNext;
    }

    Node *next = nullptr;
    int data;

    friend class LinkedList;
    friend class MyStack;
};

template <class T>
class NodeT
{
public:
    NodeT(T iData, NodeT *iNext = nullptr)
    {
        this->data = iData;
        this->next = iNext;
    }

    NodeT *next = nullptr;
    T data;

    friend class LinkedList;
    friend class MyStack;
};

class LinkedList
{

public:
    Node *getLastNode()
    {
        Node *t = head;

        if (t == nullptr)
        {
            return nullptr;
        }

        while (t->next != nullptr)
        {
            t = t->next;
        }
        return t;
    }

    Node *head = nullptr;

    LinkedList(Node *iHead = nullptr)
    {
        this->head = iHead;
    }

    LinkedList(int iData)
    {
        this->head = new Node(iData);
    }

    LinkedList(const std::vector<int> &iNodeValues)
    {
        this->head = new Node(iNodeValues[0]);
        int size = iNodeValues.size();
        Node *t = head;
        for (int i = 1; i < size; i++)
        {
            t->next = new Node(iNodeValues[i]);
            t = t->next;
        }
    }

    void appendToTail(int iData)
    {
        Node *toAdd = new Node(iData);
        Node *lastNode = getLastNode();
        if (lastNode == nullptr)
        {
            head = toAdd;
        }
        else
        {
            lastNode->next = toAdd;
        }
    }

    void insert(int iData, int iIndex)
    {
        Node *toAdd = new Node(iData);

        if (iIndex == 0)
        {
            toAdd->next = head;
            head = toAdd;
            return;
        }

        Node *before = head;
        for (int i = 0; i < iIndex - 1; i++)
        {
            if (before != nullptr && before->next != nullptr)
            {
                before = before->next;
            }
            else
            {
                std::cerr << "Not inserting because out of bounds" << std::endl;
                return;
            }
        }

        toAdd->next = before->next;
        before->next = toAdd;
    }

    void deleteNode(int iData)
    {
        if (head != nullptr)
        {
            if (head->data == iData)
            {
                Node *toDelete = head;
                head = head->next;
                delete toDelete;
                return;
            }

            Node *t = head;
            while (t->next != nullptr)
            {
                if (t->next->data == iData)
                {
                    Node *toDelete = t->next;
                    t->next = t->next->next;
                    delete toDelete;
                    return;
                }
                t = t->next;
            }
        }
    }

    std::string print()
    {
        std::stringstream ss;
        Node *t = head;
        while (t != nullptr)
        {
            ss << t->data << " ";
            t = t->next;
        }
        std::string output = std::string(ss.str());
        if (output.length() > 0)
        {
            output.pop_back();
        }
        return output;
    }
};

class DoubleLinkedList
{

private:
    class Node
    {
    public:
        Node(int iData, Node *iPrevious = nullptr, Node *iNext = nullptr) : data(iData), previous(iPrevious), next(iNext){};

        Node *next = nullptr;
        Node *previous = nullptr;
        int data;
    };

public:
    Node *head = nullptr;
    Node *tail = nullptr;

    DoubleLinkedList(Node *iHead)
    {
        this->head = iHead;
        this->tail = this->head;
    }

    DoubleLinkedList(int iData)
    {
        this->head = new Node(iData);
        this->tail = this->head;
    }

    DoubleLinkedList(const std::vector<int> &iNodeValues)
    {
        if (iNodeValues.size() > 0)
        {
            this->head = new Node(iNodeValues[0]);
            int size = iNodeValues.size();
            Node *t = head;
            for (int i = 1; i < size; i++)
            {
                t->next = new Node(iNodeValues[i], t);
                t = t->next;
            }
            tail = t;
        }
    }

    void appendToTail(int iData)
    {
        Node *toAdd = new Node(iData, tail);
        if (tail == nullptr)
        {
            tail = head = toAdd;
        }
        else
        {
            tail->next = toAdd;
            tail = toAdd;
        }
    }

    void insert(int iData, int index)
    {
        Node *newNode = new Node(iData);
        if (index == 0)
        {
            newNode->next = head;
            if (head != nullptr)
            {
                head->previous = newNode;
                head = newNode;
                return;
            }
            else
            {
                head = tail = newNode;
                return;
            }
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
        newNode->previous = t;
        if (t->next != nullptr)
        {
            t->next->previous = newNode;
        }
        else
        {
            tail = newNode;
        }
        t->next = newNode;
    }

    void deleteNode(int iData)
    {
        if (head != nullptr)
        {
            Node *t = head;
            Node *toDelete = nullptr;

            if (t->data == iData)
            {
                toDelete = t;
                if (head == tail)
                {
                    tail = head = t->next;
                    delete toDelete;
                    return;
                }
                else
                {
                    t->next->previous = nullptr;
                    head = t->next;
                    delete toDelete;
                    return;
                }
            }

            while (t->next != nullptr)
            {
                if (t->next->data == iData)
                {
                    toDelete = t->next;
                    t->next = t->next->next;
                    if (t->next != nullptr)
                    {
                        t->next->previous = t;
                        return;
                    }
                    else
                    {
                        tail = t;
                        return;
                    }
                }
                t = t->next;
            }
        }
    }

    std::string print()
    {
        std::stringstream ss;
        Node *n = head;
        while (n != nullptr)
        {
            ss << n->data << " ";
            n = n->next;
        }
        std::string output = std::string(ss.str());
        if (output.length() > 0)
        {
            output.pop_back();
        }
        return output;
    }

    std::string printReverse()
    {
        std::stringstream ss;
        Node *n = tail;
        while (n != nullptr)
        {
            ss << n->data << " ";
            n = n->previous;
        }
        std::string output = std::string(ss.str());
        if (output.length() > 0)
        {
            output.pop_back();
        }
        return output;
    }
};

class EmptyContainerException : std::exception
{
public:
    std::string what()
    {
        return "Container is empty";
    }
};

class MyStack
{
public:
    MyStack(Node *iTop = nullptr)
    {
        this->top = iTop;
    }

    MyStack(int t)
    {
        this->top = new Node(t);
    }

    MyStack(const std::vector<int> &iValues)
    {
        int size = iValues.size();
        top = new Node(iValues[0]);

        Node *n = nullptr;
        for (int i = 1; i < size; i++)
        {
            n = new Node(iValues[i]);
            n->next = top;
            top = n;
        }
    }

    Node *top = nullptr;

    Node &pop()
    {
        if (isEmpty())
        {
            throw new EmptyContainerException();
        }

        Node &toReturn = *top;
        top = top->next;
        toReturn.next = nullptr;
        return toReturn;
    }

    void push(int item)
    {
        Node *t = new Node(item);
        t->next = top;
        top = t;
    }

    void push(Node &node)
    {
        node.next = top;
        top = &node;
    }

    int peek()
    {
        if (isEmpty())
        {
            throw new EmptyContainerException();
        }

        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    std::string print()
    {
        std::stringstream ss;
        Node *t = top;
        while (t != nullptr)
        {
            ss << t->data << " ";
            t = t->next;
        }
        std::string output = std::string(ss.str());
        if (output.length() > 0)
        {
            output.pop_back();
        }
        return output;
    }
};

template <class T>
class MyQueue
{
public:
    NodeT<T> *first = nullptr;
    NodeT<T> *last = nullptr;

    MyQueue(NodeT<T> *iFirst = nullptr) : first(iFirst)
    {
        last = first;
    };

    MyQueue(T iFirstValue)
    {
        first = new NodeT<T>(iFirstValue);
        last = first;
    };

    MyQueue(const std::vector<T> &iValues)
    {
        first = new NodeT<T>(iValues[0]);
        int size = iValues.size();
        NodeT<T> *n = first;
        for (int i = 1; i < size; i++)
        {
            n->next = new NodeT<T>(iValues[i]);
            n = n->next;
        }
        last = n;
    }

    void add(T value)
    {
        if (isEmpty())
        {
            first = new NodeT<T>(value);
            last = first;
            return;
        }
        last->next = new NodeT<T>(value);
        last = last->next;
    }

    NodeT<T> &remove()
    {
        if (isEmpty())
        {
            throw new EmptyContainerException();
        }

        NodeT<T> &toRemove = *first;
        first = first->next;
        return toRemove;
    }

    T peek()
    {
        if (isEmpty())
        {
            throw new EmptyContainerException();
        }

        return first->data;
    }

    bool isEmpty()
    {

        return first == nullptr;
    }

    std::string print()
    {
        std::stringstream ss;
        NodeT<T> *t = first;
        while (t != nullptr)
        {
            ss << t->data << " ";
            t = t->next;
        }
        std::string output = std::string(ss.str());
        if (output.length() > 0)
        {
            output.pop_back();
        }
        return output;
    }
};

class NodeTree
{
public:
    int value;
    NodeTree *left;
    NodeTree *right;
    NodeTree *parent;

    NodeTree(int iValue, NodeTree *iLeft = nullptr, NodeTree *iRight = nullptr, NodeTree *iParent = nullptr) : value(iValue), left(iLeft), right(iRight), parent(iParent) {}
};

class NodeGraph
{
public:
    int value;
    std::vector<NodeGraph *> children;
    NodeGraph(int iValue, std::vector<NodeGraph *> iChildren = {}) : value(iValue), children(iChildren) {}
};

class Graph
{
public:
    std::vector<NodeGraph *> nodes;
    Graph(std::vector<NodeGraph *> iNodes) : nodes(iNodes) {}
};
