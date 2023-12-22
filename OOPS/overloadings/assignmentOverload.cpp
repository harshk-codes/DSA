#include <iostream>
#include <stdlib.h>

using namespace std;

class Overload {
public:
    int data1;
    int data2;

    Overload()
    {
        data1 = 3;
        data2 = 4;
    }

    int operator+(const Overload& O)
    {
        return O.data1 + O.data2;
    }

    
};

int main()
{
    Overload a;
    int sum = a.data1+a.data2;
    cout << "The sum is: "<<sum<<endl;

    return 0;
}