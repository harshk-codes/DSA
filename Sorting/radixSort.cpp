#include <iostream>
#include <stdlib.h>
using namespace std;

// creating a dynamic class collection
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

    void insertData(int d);

    void display();

    //operator overloading
    int& operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return data[index];
        }
        else
        {
            cout<<"index out of bound";
        }
    }
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
        cout << "Maximum array size reached, can't add more data." << endl;
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

// largest element in the array
int Max(Collection& Arr, int n)
{
    int i;
    int max = -32728;
    for (i = 0; i < n; i++)
    {
        if (Arr[i] > max)
        {
            max = Arr[i];
        }
    }

    return max;
}

// Node of a linked list
class Node
{
public:
    int data;
    Node *next;
};

// count no. of digits
int countDigit(int n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

// initializing buckets/bin
void initBins(Node **x, int y)
{
    int i;
    for (i = 0; i < y; i++)
    {
        x[i] = nullptr;
    }
}

// inserting in the buckets
void Insert(Node **bins, int value, int ind)
{
    Node *temp = (Node *)malloc(sizeof(int));
    temp->data = value;
    temp->next = nullptr;

    if (bins[ind] == nullptr)
    {
        bins[ind] = temp;
    }
    else
    {
        Node *p = bins[ind];
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node **bins, int ind)
{
    int x;
    Node *p = bins[ind];
    bins[ind] = bins[ind]->next;
    x = p->data;
    delete p;
    return x;
}

// getting bucket's index
int getBinInd(int x, int n)
{
    int i;
    int pow = 1;
    for (i = 0; i < n; i++)
    {
        pow = pow * 10;
    }
    return (int)(x / pow) % 10;
}

void radixSort(Collection& Arr, int n)
{
    int pass, i, j = 0, k = 0;
    int max = Max(Arr, n);
    int nPass = countDigit(max);

    // creating bins array
    Node **bins = (Node **)malloc(sizeof(Node *) * 10);

    // init bins with nullptr initially
    initBins(bins, 10);

    // update bins and A for nPass times
    for (pass = 0; pass < nPass; pass++)
    {
        // updating bins on values on A
        for (i = 0; i < n; i++)
        {
            int binIn = getBinInd(Arr[i], pass);
            Insert(bins, Arr[i], binIn);
        }

        // Updating A with new sorted elements from the bins
        while (j < 10)
        {
            while (bins[j] != nullptr)
            {
                Arr[k++] = Delete(bins, j);
            }
            j++;
        }

        // init bins with nullptr agian
        initBins(bins, 10);
    }

    // delete heap mem
    delete[] bins;
}

int main()
{
    Collection Arr(12);
    Arr.insertData(5048);
    Arr.insertData(2192);
    Arr.insertData(3267);
    Arr.insertData(4132);
    Arr.insertData(1047);
    Arr.insertData(9894);
    Arr.insertData(1729);
    Arr.insertData(369);
    Arr.insertData(711);
    Arr.insertData(568);
    Arr.insertData(722);
    Arr.insertData(451);

    cout << "The given array is: ";
    Arr.display();

    cout << "After radix sort: ";
    radixSort(Arr, 12);
    Arr.display();

    return 0;
}