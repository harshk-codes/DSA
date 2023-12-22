#include <iostream>
#include <stdlib.h>
using namespace std;

struct Book
{
    int isbn;
    char title[50];
    float price;

    Book()
    {
        isbn = 0;
        title[0] = '\0';
        price = 0.0;
    }

    Book(int isbn, char title[], float price)
    {
        int i;
        struct Book book;
        this->isbn = isbn;
        this->price = price;

        for (i = 0; i < 50; i++)
        {
            if (title[i] != '\0')
            {
                this->title[i] = title[i];
            }
            else
            {
                this->title[i] = '\0'; // if the string is shorter than 50 then fill with '\0'
            }
        }
    }

    ~Book()
    {
        
    }

    // operator overloading = and >
    bool operator>(const Book &obj)
    {
        if(this->isbn > obj.isbn)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Book &operator=(const Book &obj)
    {
        // overloading assignment to copy one book to another
        if (this != &obj)
        {
            int i;
            this->isbn = obj.isbn;

            for (i = 0; i < 50; i++)
            {
                this->title[i] = obj.title[i];
            }

            this->price = obj.price;
        }
        return *this;
    }

    friend ostream& operator<<( ostream& output, const struct Book &object )
    {
        output <<"ISBN: "<<object.isbn<<", "<<"Title: "<<object.title<<", "<<"Price: "<<object.price<<endl;
        return output;
    }

};

    // code for a dynamic array class
    class Collection
    {
    private:
        struct Book *data;
        int size;
        int maxLength;

    public:
        // Collection()
        // {
        //     data = NULL;
        //     size = 0;
        // }

        Collection(int maxLength = -1)
        {
            this->maxLength = maxLength;
            this->size = 0;

            if (maxLength != -1)
            {
                data = (struct Book *)malloc((sizeof(struct Book)) * maxLength);
            }
        }

        ~Collection()
        {
            delete[] data;
        }

        friend ostream &operator<<(ostream &output, const Collection &Book)
        {
            output << Book.data;
            return output;
        }

        friend istream &operator>>(istream &input, Collection &obj)
        {
            input >> obj.size;
            return input;
        }

        int &operator[](int index)
        {
            if (index >= 0 && index < size)
            {
                return data[index].isbn;
            }
            else
            {
                cout << "index out of bound.";
            }
        }

        Collection &operator=(const Collection &obj)
        {
            if (this != &obj)
            { // Checking for self-assignment and deleting current data if exist
                delete data;

                // Copying the size and maxLength
                this->size = obj.size;
                this->maxLength = obj.maxLength;

                // Allocating new memory for the data array and copy the contents
                if (maxLength != -1)
                {
                    data = (struct Book *)malloc(sizeof(struct Book) * maxLength);
                    for (int i = 0; i < size; i++)
                    {
                        data[i] = obj.data[i];
                    }
                }
                else
                {
                    data = NULL; //If maxLength is -1, data should be NULL
                }
            }
            return *this;
        }

        bool operator>(const Collection &obj) 
        {
            return this->data > obj.data;
        }

        void insertData(int isbn, char title[], float price)
        {
            struct Book book;
            if (maxLength == -1 || size < maxLength)
            {
                data[size] = Book(isbn, title, price);
                size++;
            }
            else
            {
                cout << "Maximum size of the array reached." << endl;
            }
        }

        void display()
        {
            int i;
            for (i = 0; i < size; ++i)
            {
                cout << "["<<data[i].isbn << ", " << data[i].title << ", " << data[i].price<<"]";
            }
            cout << endl;
        }
    };

    // inserting in a heap
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

    // deleting from a heap
    int Delete(Collection &A, int n)
    {
        // deleting the root element which is largest
        // then pushing it in the last of array
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
            if (A[j] > A[i])
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

    // heap sort code
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
        int i, n;
        cout << "Enter the no of books: ";
        cin >> n;
        // the number of book should be >=1
        if (n < 1)
        {
            cout << "Invalid number of books" << endl;
            cout << "Enter again: ";
            cin >> n;
        }

        // initialize collection with that no. of books
        Collection Arr(n);

        int isbn;
        char title[50];
        float price;

        for (i=1; i <= n; i++)
        {
            cout<<"Enter book"<<i<<" isbn: ";
            cin>>isbn;

            cout<<"Enter book"<<i<<" title: ";
            cin>>title;

            cout<<"Enter book"<<i<<" price: ";
            cin>>price;
            Arr.insertData(isbn, title, price);
        }

        heapSort(Arr, n);

        cout<<"After Heap sort: "<<endl;
        Arr.display();

        return 0;
    }