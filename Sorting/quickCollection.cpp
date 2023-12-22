#include <iostream>
using namespace std;

//constructor for pair
class pair {
    int a, b;
};

class Stack {
private:
    int *s;
    int size;
    int top;

public:
    Stack(int size)
    {
        this->size = size;
        s = (int*)malloc(sizeof(int)*size);
        top = -1;
    }

    ~Stack()
    {
        delete s;
    }

    void push(Stack *st, int x);

    int pop(Stack *st);

    int stackTop(Stack st);

    int isEmpty(Stack st);
};

void Stack::push(Stack *st, int x)
{
    if (st->top == st->size -1)
    {
        cout<<"stack overflow"<<endl;
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int Stack::pop(Stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        cout<<"stack is empty."<<endl;
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }

    return x;
}

int Stack::stackTop(Stack st)
{
    if (st.top == -1)
    {
        return -1;
    }
    else
    {
        return st.s[st.top];
    }
}

int Stack::isEmpty(Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//dynamic array using class Collection
class Collection {
private:
    int* data;
    int size;
    int maxLength;


public:
    Collection()
    {
        data = NULL;
        size = 0;
    }

    Collection(int maxLength = -1)
    {
        this->maxLength = maxLength;
        this->size = 0;

        if (maxLength != -1)
        {
            data = (int*)malloc(sizeof(int)*maxLength);
        }
    }

    ~Collection()
    {
        delete data;
    }

    void insertData(int d);

    void display();

    int &operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return data[index];
        }
        else
        {
            cout<<"index out of bound beh...";
        }
    }
};


void Collection::insertData(int d)
{
    if (maxLength == -1 || size<maxLength)
    {
        data[size] = d;
        size++;
    }
    else
    {
        cout<<"Maximum size of the array reached."<<endl;
    }
}

void Collection::display()
{
    int i;
    for (i=0; i<size; ++i)
    {
        cout<<data[i]<<" ";
    }

    cout<<endl;
}

void quickSort(Collection& A, int n)
{

}

int main()
{
    Collection Arr(6);
    Arr.insertData(4);
    Arr.insertData(1);
    Arr.insertData(3);
    Arr.insertData(6);
    Arr.insertData(5);
    Arr.insertData(9);

    cout<<"Given array is: ";
    Arr.display();

    cout<<"After quick sort: ";
   // quickSort(Arr, 6);
    Arr.display();

    return 0;
}