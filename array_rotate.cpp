#include<iostream>
using namespace std;

#define N 8


void swap (int *a , int *b ) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rotateArray(int *a, int k) {

    for(int i=0; i<k; i++) {
        int temp = a[N-1];
        for(int j=N-1; j>0; j--) {
            a[j] = a[j-1];
        }
        a[0] = temp;
    }

     for (int j =0 ;j<N; j++ ) {
            cout<<a[j]<<" ";
        }
}

int main(){

    int k = 4, a[]= {1, 2, 3, 4, 5, 6, 7, 8};

    rotateArray(a, k);
    return 0;
}