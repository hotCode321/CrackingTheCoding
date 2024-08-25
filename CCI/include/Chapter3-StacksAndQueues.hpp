#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Utils.hpp"

class MyStackWithMin : public MyStack
{

public:
    Node *minNode = nullptr;

    MyStackWithMin(const std::vector<int> &iValues)
    {
        int size = iValues.size();
        MyStack::top = new Node(iValues[0]);
        minNode = new Node(*top);

        Node *n = nullptr;
        for (int i = 1; i < size; i++)
        {
            n = new Node(iValues[i]);
            n->next = MyStack::top;
            MyStack::top = n;
            int newMin = std::min(iValues[i], minNode->data);
            if (newMin < minNode->data)
            {
                minNode->next = new Node(*n);
                Node *before = new Node(*minNode);
                minNode = minNode->next;
                minNode->next = before;
            }
        }
    }

    void push(int iValue)
    {
        if (!minNode)
        {
            minNode = new Node(iValue);
        }
        else if (std::min(iValue, minNode->data) < minNode->data)
        {
            minNode->next = new Node(iValue);
            Node *before = new Node(*minNode);
            minNode = minNode->next;
            minNode->next = before;
        }

        MyStack::push(iValue);
    }

    Node &pop()
    {
        Node &popped = MyStack::pop();
        if (popped.data == minNode->data)
        {
            Node *toDelete = minNode;
            minNode = minNode->next;
            delete toDelete;
        }

        return popped;
    }

    int getMin()
    {
        return minNode->data;
    }
};

class MyStackWithMin2 : public MyStack
{

public:
    MyStack sMin;

    MyStackWithMin2(const std::vector<int> &iValues)
    {
        int size = iValues.size();
        top = new Node(iValues[0]);
        sMin.push(top->data);

        Node *n = nullptr;
        for (int i = 1; i < size; i++)
        {
            n = new Node(iValues[i]);
            n->next = top;
            top = n;
            if (iValues[i] <= sMin.peek())
            {
                sMin.push(iValues[i]);
            }
        }
    }

    void push(int iValue)
    {
        if (sMin.isEmpty())
        {
            sMin.push(iValue);
        }
        else if (iValue <= sMin.peek())
        {
            sMin.push(iValue);
        }

        MyStack::push(iValue);
    }

    Node &pop()
    {
        Node &popped = MyStack::pop();
        if (popped.data == sMin.peek())
        {
            sMin.pop();
        }

        return popped;
    }

    int getMin()
    {
        return sMin.peek();
    }
};

class StackWithStacks : public MyStack
{

public:
    std::vector<MyStack> stacks;
    int capacity;
    int counter;

    StackWithStacks(int iCapacity, const std::vector<int> &iValues)
    {
        capacity = iCapacity;
        int size = iValues.size();
        MyStack s = MyStack(iValues[0]);
        counter = 1;

        for (int i = 1; i < size; i++)
        {
            if (counter < capacity)
            {
                s.push(iValues[i]);
                counter++;
            }
            else
            {
                stacks.emplace_back(s);
                s = MyStack(iValues[i]);
                counter = 1;
            }
        }
        stacks.emplace_back(s);
    }

    void push(int value)
    {
        if (!stacks.empty() && counter < capacity)
        {
            stacks.back().push(value);
            counter++;
        }
        else
        {
            stacks.emplace_back(MyStack(value));
            counter = 1;
        }
    }

    void pop()
    {
        if (!stacks.empty())
        {
            stacks.back().pop();
            counter--;
            if (stacks.back().isEmpty())
            {
                stacks.pop_back();
                counter = capacity;
            }
        }
        else
        {
            return;
        }
    }

    int peek()
    {
        if (!stacks.empty())
        {
            return stacks.back().peek();
        }
        else
        {
            throw new EmptyContainerException();
        }
    }

    std::string print()
    {
        std::stringstream ss;
        for (auto &&it = stacks.rbegin(); it != stacks.rend(); it++)
        {
            ss << (*it).print() << " | ";
        }
        std::string output = std::string(ss.str());
        if (output.length() > 2)
        {
            output.pop_back();
            output.pop_back();
            output.pop_back();
        }
        return output;
    }
};

class QueueWith2Stacks
{

public:
    MyStack s1;
    MyStack s2;

    QueueWith2Stacks(const std::vector<int> &iValues)
    {
        s1 = MyStack(iValues);
        fillS2();
    }

    void add(int iValue)
    {
        Node *node = new Node(iValue);
        if (s1.isEmpty())
        {
            s1.top = node;
        }
        else
        {
            node->next = s1.top;
            s1.top = node;
        }
    }

    Node &remove()
    {
        rearrangeIfS2empty();
        return s2.pop();
    }

    int peek()
    {
        rearrangeIfS2empty();
        return s2.peek();
    }

    std::string print()
    {
        std::string firstPart = s2.print();
        std::vector<int> normalOrder;
        Node *n = s1.top;
        while(n != nullptr){
            normalOrder.push_back(n->data);
            n = n->next;
        }

        std::stringstream ss;
        for(auto &&rit = normalOrder.rbegin(); rit != normalOrder.rend(); rit++){
            ss << *rit << " ";
        }
        
        std::string secondPart = std::string(ss.str());
        if (secondPart.length() > 0)
        {
            secondPart.pop_back();
            return firstPart + " " + secondPart;
        } else {
            return firstPart;
        }
    }

    bool isEmpty()
    {
        return s1.isEmpty();
    }

private:
    void rearrangeIfS2empty()
    {
        if (s2.isEmpty())
        {
            if (s1.isEmpty())
            {
                throw new EmptyContainerException();
            }
            else
            {
                fillS2();
            }
        }
    }

    void fillS2()
    {
        while (!s1.isEmpty())
        {
            Node n = s1.pop();
            s2.push(n.data);
        }
    }
};

MyStack sortStackWithCopying(MyStack &s1);
void sortStack(MyStack &s1);