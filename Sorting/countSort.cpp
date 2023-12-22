#include <iostream>
#include <stdlib.h>
using namespace std;

//finding maximum of an array
int max(int Arr[], int size)
{
    int i;
    int max = Arr[0];

    for(i=1; i<size; i++)
    {
        if(max<Arr[i])
        {
            max = Arr[i];
        }
    }
    return max;
}

//count sort algorithm
void countSort(int *A, int size)
{
    int i,j;
    int m = max(A, size);

    //dynamic arrray
    int *count = (int*)malloc(sizeof(int)*(m+1));
    
    //inintializing elements to 0
    for(i = 0; i<size; i++)
    {
        count[i] = 0;
    }

    for(i=0; i<size; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }
    
    i=0;
    j=0;

    while(i<m+1)
    {
        if(count[i]>0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        else{
            i++;
        }
    }
}

//displaying array
void display(int A[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<"\t"<<endl;
}

int main()
{
    int A[] = {3,1,9,7,1,2,4};
    int size = sizeof(A)/sizeof(A[0]);

    display(A,size);
    countSort(A,size);
    display(A, size);

    return 0;      
}