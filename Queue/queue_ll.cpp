#include <iostream>
#include <stdlib.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    //used member initializer
    Node(int value) : data(value), next(NULL) {}
};

class Queue {
private:
    Node* f;
    Node* r;

public:
    Queue() : f(NULL), r(NULL) {}

    bool is_empty()
    {
        return f == NULL;
    }

    void enqueue(int val)
    {
        Node* newNode = new Node(val);

        if (r == NULL)
        {
            f = r = newNode;
        }
        else
        {
            r->next = newNode;
            r = newNode;
        }
    }

    int dequeue()
    {
        if (is_empty())
        {
            cout<<"Queue is empty."<<endl;
            return -1;
        }

        Node* temp = f;
        int val = temp->data;
        f = r->next;

        if (f==NULL)
        {
            r = NULL;
        }

        delete temp;
        return val;
    }

    ~Queue()
    {
        while(!is_empty())
        {
            dequeue();
        }
    }
};

int main()
{
    Queue kyu;
    kyu.enqueue(4);
    kyu.enqueue(5);
    kyu.enqueue(6);

    cout<<"Dequeued items: "<<kyu.dequeue() <<"\n";

    kyu.enqueue(9);
    cout<<"Dequeued item: "<<kyu.dequeue() <<"\n";

    return 0;
}