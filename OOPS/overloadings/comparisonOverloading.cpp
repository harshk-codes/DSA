#include <iostream>
using namespace std;

class Coverload {
public:
    int data1;
    int data2;

    Coverload()
    {
        data1 = 3;
        data2 = 4;
    }

    int operator>(const Coverload& O)
    {
        return O.data1 + O.data2;
    }

    
};

int main()
{
    Coverload a;
    int sum = a.data1+a.data2;
    cout << "The sum is: "<<sum<<endl;

    return 0;
}