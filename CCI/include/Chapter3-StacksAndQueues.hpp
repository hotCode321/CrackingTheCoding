#include <iostream>
#include <string>

class EmptyStackException : std::exception
{
public:
    std::string what()
    {
        return "Stack is empty";
    }
};

template <typename T>
class MyStack
{
    class StackNode
    {
    private:
        T *data;
        StackNode *next;
        StackNode *top;

    public:
        StackNode(T *data)
        {
            this->data = data;
        }
    };

    T *pop()
    {
        if (StackNode::top == nullptr)
            throw new EmptyStackException();
        T *item = StackNode::top->data;
        StackNode::top = StackNode::top->next;
        return item;
    }

    void push(T *item)
    {
        StackNode *t = new StackNode(item);
        t->next = StackNode::top;
        StackNode::top = t;
    }

    T peek()
    {
        if (StackNode::top == nullptr)
            throw new EmptyStackException();
        return StackNode::top->data;
    }

    bool isEmpty()
    {
        return StackNode::top == nullptr;
    }
};