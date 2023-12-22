#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void merge(int Arr[], int l, int m, int h) {
    int i,j,k,B[100],e;
    i=k=l;j=m+1;

    while(i <=m && j <= h) {
        if(Arr[i] < Arr[j]) {
            B[k++] = Arr[i++];
        } else {
            B[k++] = Arr[j++];
        }
    }

    for(; i<=m; i++) {
        B[k++] = Arr[i];
    }

    for(; j<=h; j++) {
        B[k++] = Arr[j];
    }

    for(e=l; e<=h; e++) {
        Arr[e] = B[e];
    }
}

void mergeSort(int A[], int n) {
    int p,l,h,m,i;

    for(p=2; p<=n; p*=2) {
        for(i=0; i+p-1<n; i+=p) {
            l=i;
            h=i+p-1;
            m = (l+h)/2;

            merge(A,l,m,h);
        }
    }

    if(p/2 < n) {
        merge(A,0,p/2-1,n);
    }
}

int main() {
    int Arr[] = {3,1,13,6,7,2,9,4,23,56,12,49}, n = 12, i;

    mergeSort(Arr, n);

    for(i=0; i <n; i++) {
        cout<<Arr[i]<<" ";
    }

    return 0;
}
