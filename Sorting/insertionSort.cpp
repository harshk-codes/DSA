#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b; 
    *b = temp;
}

void insertionSort(int Arr[], int n) {
    int i,j;

    for(i=0; i <= n-2; i++) {
        for(j=i+1; j>0; j--) {
            if(Arr[j] < Arr[j-1]) {
                swap(&Arr[j], &Arr[j-1]);
            } else {
                break;
            }
        }
    }  
}

int main() {
    int Arr[] = {3,1,13,6,7,2,9,4,23,56,12,49}, n=12,i;

    insertionSort(Arr,n);

    for(i=0; i <n; i++) {
        cout<<Arr[i]<<" ";
    }

    return 0;
}