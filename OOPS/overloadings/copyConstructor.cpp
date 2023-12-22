#include <iostream>
using namespace std;

class student {
private:
    int english;
    int math;

public:
    student(int e, int m)
    {
        english = e;
        math = m;
    }

    //operator overloading 
    void operator=(const student& s)
    {
        english = s.english;
        math = s.math;
    }

    void marks()
    {
        cout<<"ENGLISH: "<<english<<", MATH: "<<math<<endl;
    }
};

int main()
{
    student s1(23, 45), s2(30, 50);

    cout<<"Student 1 marks are: ";
    s1.marks();

    cout<<"Student 2 marks: ";
    s2.marks();

    s1 = s2;

    cout<<"Now s1 marks: ";
    s1.marks();

    cout<<"Now s2 marks: ";
    s2.marks();
    
    return 0;
}