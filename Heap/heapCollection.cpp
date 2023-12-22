#include <iostream>
#include <stdlib.h>
using namespace std;

class Collection
{
private:
    int *data;
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
            data = (int *)malloc(sizeof(int) * maxLength);
        }
    }

    ~Collection()
    {
        delete data;
    }

    int &operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return data[index];
        }
        else
        {
            cout << "index out of bound beh...";
        }
    }

    void insertData(int d);

    void display();
};

void Collection::insertData(int d)
{
    if (maxLength == -1 || size < maxLength)
    {
        data[size] = d;
        size++;
    }
    else
    {
        cout << "Maximum size of the array reached." << endl;
    }
}

void Collection::display()
{
    int i;
    for (i = 0; i < size; ++i)
    {
        cout << data[i] << " ";
    }

    cout << endl;
}

void Insert(Collection &A, int n)
{
    int i = n, x;
    x = A[i];
    while (i > 1 && x > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = x;
}

int Delete(Collection &A, int n)
{
    int i, j, t, value;

    value = A[1];
    A[1] = A[n];
    A[n] = value;
    i = 1;
    j = i * 2;
    while (j <= n - 1)
    {
        if (j < n - 1 && A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j])
        {
            t = A[i];
            A[i] = A[j];
            A[j] = t;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    return value;
}

void heapSort(Collection &A, int n)
{
    int i;
    for (i = 1; i <= n; i++)
        Insert(A, i);

    for (i = n; i > 1; i--)
    {
        Delete(A, i);
    }
}

int main()
{
    Collection Arr(8);
    Arr.insertData(0);
    Arr.insertData(14);
    Arr.insertData(15);
    Arr.insertData(5);
    Arr.insertData(20);
    Arr.insertData(30);
    Arr.insertData(8);
    Arr.insertData(40);

    cout << "Initial array is: ";
    Arr.display();

    cout << "Sorted Array after heap sort is: ";
    heapSort(Arr, 7);
    Arr.display();

    cout << endl;
    return 0;
}