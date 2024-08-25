#include "Chapter3-StacksAndQueues.hpp"
#include "Chapter2-LinkedLists.hpp"
#include "Utils.hpp"
#include <climits>

struct minInfo
{
    int lastMin = INT_MIN;
    int occurencies = 0;
};

int getSize(MyStack &s1)
{
    Node *n = s1.top;
    int size = 0;
    while (n != nullptr)
    {
        size++;
        n = n->next;
    }

    return size;
}

minInfo findMinimum(MyStack &s1, int lastMin)
{
    int min = INT_MAX;
    Node *n = s1.top;
    int counter = 0;
    while (n != nullptr)
    {
        if (n->data > lastMin)
        {
            if (n->data < min)
            {
                min = n->data;
                counter = 1;
            }
            else if (n->data == min)
            {
                counter++;
            }
        }

        n = n->next;
    }

    return {min, counter};
}

MyStack sortStackWithCopying(MyStack &s1)
{
    MyStack s2;
    int size = getSize(s1);
    int counter = 0;
    minInfo info;
    while (counter < size)
    {
        info = findMinimum(s1, info.lastMin);
        for (int i = 0; i < info.occurencies; i++)
        {
            s2.push(info.lastMin);
        }
        counter += info.occurencies;
    }

    return s2;
}

void sortStack(MyStack &s1)
{
    MyStack s2;

    while (!s1.isEmpty())
    {
        Node &tmp = s1.pop();
        while(!s2.isEmpty() && s2.peek() > tmp.data){
            s1.push(s2.pop());
        }

        s2.push(tmp);
    }

    MyStack s3;
    while (!s2.isEmpty())
    {
        s3.push(s2.pop());
    }

    while(!s3.isEmpty()){
        s1.push(s3.pop());
    }
}