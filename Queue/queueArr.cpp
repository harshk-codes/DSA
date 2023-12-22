#include <iostream>
#include <stdlib.h>

using namespace std;

struct Queue
{
   int size;
   int F;
   int R;
   int *Q; 
};

void enQueue(Queue *q, int x)
{
    if(q->R == q->size - 1)
    {
        cout<<"Queue is full."<<endl;
    }
    else
    {
        q->R++;
        q->Q[q->R] = x;
    }
}

int deQueue(Queue *q)
{
    int x = -1;
    if(q->F == q->R)
    {
        cout<<"Queue is empty."<<endl;
    }
    else
    {
        q->F++;
        x = q->Q[q->F];
    }

    return x;
}

void display(Queue q)
{
    int i;
    for(i=0; i<q.size; i++)
    {
        cout<<q.Q[i]<<" ";
    }
    cout<<"\t"<<endl;
}

int main()
{
    struct Queue q;
    cout<<"Enter the size: "<<endl;
    cin>>q.size;
    q.Q = (int*)malloc(sizeof(int)*q.size);
    q.F = q.R = -1;

    enQueue(&q, 5);
    enQueue(&q, 3);
    enQueue(&q, 4);
    enQueue(&q, 9);

    display(q);

    cout<<deQueue(&q)<<endl;

    display(q);

    return 0;
}