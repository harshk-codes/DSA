#include <iostream>
using namespace std;

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partitionA(int A[], int low, int high){
    int pivot = A[low];
    int i = low;
    int j = high;
 
    do {
        // Increment i as long as elements are smaller/equal to pivot
        do {i++;} while (A[i] <= pivot);
 
        // Decrement j as long as elements are larger than pivot
        do {j--;} while (A[j] > pivot);
 
        if (i < j){
            swap(&A[i], &A[j]);
        }
    } while (i < j);
 
    swap(&A[low], &A[j]);
    return j;
}
 
void QuickSortA(int A[], int low, int high){
    if (low < high){
        int j = partitionA(A, low, high);
        QuickSortA(A, low, j);
        QuickSortA(A, j+1, high);
    }
}

void Display(int A[], int n)
{
    int i;
    for (i=0; i <n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, 32767};
    int n = sizeof(A)/sizeof(A[0]);
    Display(A, n);
 
    QuickSortA(A, 0, n-1);
    cout<<"After quick sort: ";
    Display(A, n);
    cout << endl;
    
    return 0;
}