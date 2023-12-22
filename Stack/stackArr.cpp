#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *s;
};

void push(Stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(Stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }

    return x;
}

int peek(Stack *st, int pos)
{
    int x = -1;
    if (st->top - pos + 1 < 0)
    {
        cout << "Invalid position." << endl;
    }
    else
    {
        x = st->s[st->top - pos + 1];
    }

    return x;
}

int stackTop(Stack st)
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

int isEmpty(Stack st)
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

int isFull(Stack st)
{
    if (st.top == st.size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display(struct Stack st)
{
    int i;
    for(i=st.top; i>=0; i--)
    {
        cout<<st.s[i]<<" ";
    }
}

int main()
{
    struct Stack st;
    cout << "Enter the size of stack: " << endl;
    cin >> st.size;

    st.s = (int *)malloc(sizeof(int) * st.size);
    st.top = -1;

    push(&st, 6);
    push(&st, 3);
    push(&st, 5);
    push(&st, 21);

    display(st);

    cout<<pop(&st)<<endl;
    cout<<pop(&st)<<endl;

    cout<<peek(&st, 1)<<endl;
    
    return 0;
}

// we take parameter as pass by reference(means as a pointer) only when we need to modify it else we take pass by value.