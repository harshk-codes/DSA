/*
You are given all numbers between 1,2,...,n except one.
Your task is to find the missing number .

Input
The first input line contains an integer n.

The second line contains n-1 numbers. Each number is distinct and between 1 and n(inclusive).

Output
Print the missing number.

Constraints
 * 2 <= n <= 2.10^5

 Example 
 
 input:
 5
 2 3 1 5

 Output:
 4
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int missingNumber(int arr[], int n);
int main()
{
    int n;
    cout<<"ENter n: ";
    cin>>n;
    int nArr[n-1];

    for (int i = 0; i<n-1; i++)
    {
        cout<<"Enter value: ";
        cin>>nArr[i];
    }

    //checking missing number
    int mn = missingNumber(nArr, n);
    cout<<"Missing number is: "<<mn;

    return 0;
}

int missingNumber(int arr[], int n)
{
        for (int i = n; i<=1; --i)
    {
        for (int j = 0; j<n; j++)
        {
            if (arr[j] != i)
            {
                return i;
            }
        }
    }
}