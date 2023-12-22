#include <iostream>
#include <stdlib.h>
using namespace std;

class Collection {
private:
    int* data;
    int size;
    int maxLength;

public:
    Collection(int maxLength = -1) {
        this->maxLength = maxLength;
        this->size = 0;
        if (maxLength != -1) {
            data = (int*)malloc(sizeof(int) * maxLength);
        }
    }

    ~Collection() {
        delete data;
    }

    void insertData(int d) {
        if (maxLength == -1 || size < maxLength) {
            data[size] = d;
            size++;
        }
        else {
            cout << "Maximum size reached, can't add more data." << endl;//reallocate instead
        }
    }

     void display()
    {
    int i;
    for (i = 0; i < size; ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    }
    
    int getSize() {
        return size;
    }

    int* getData() {
        return data;
    }
};

int power(int a, int b)
{
    int i, p = 1;
    for (i=0; i < b; i++)
    {
        p*=a;
    }
    return p;
}

int Max(Collection& arr) {
    int max = -32768;
    for (int i = 0; i < arr.getSize(); i++) {
        if (arr.getData()[i] > max) {
            max = arr.getData()[i];
        }
    }
    return max;
}

int countDigits(int x) {
    int count = 0;
    while (x != 0) {
        x = x / 10;
        count++;
    }
    return count;
}

void RadixSort(Collection& A) {
    int n = A.getSize();
    int max = Max(A);
    int nPass = countDigits(max);

    // Creating bins
    int** bins = (int**)malloc(sizeof(int)*10);
    for (int i = 0; i < 10; i++) {
        bins[i] = (int*)malloc(sizeof(int) * n);
    }

    // Initializing bins
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n; j++) {
            bins[i][j] = -1;
        }
    }

    // Updating bins and A for n passes
    for (int pass = 0; pass < nPass; pass++) {
        // Updating bins on A values
        for (int i = 0; i < n; i++) {
            int binIdx = (int)(A.getData()[i] / power(10, pass)) % 10;
            int j = 0;
            while (bins[binIdx][j] != -1) {
                j++;
            }
            bins[binIdx][j] = A.getData()[i];
        }

        // Updating original array with sorted elements from bin
        int i = 0;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < n; k++) {
                if (bins[j][k] != -1) {
                    A.getData()[i++] = bins[j][k];
                    bins[j][k] = -1;
                }
            }
        }
    }

    // Deallocating memory for bins
    for (int i = 0; i < 10; i++) {
        delete bins[i];
    }
    delete[] bins;
}

int main() {
    Collection A(10);
    A.insertData(237);
    A.insertData(146);
    A.insertData(259);
    A.insertData(348);
    A.insertData(152);
    A.insertData(163);
    A.insertData(235);
    A.insertData(48);
    A.insertData(36);
    A.insertData(62);

    cout<<"initial array: ";
    A.display();

    RadixSort(A);
    cout<<"Array after Radix Sort: ";
    A.display();

    return 0;
}
