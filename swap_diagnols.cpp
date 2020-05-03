#include<iostream>
#define N 3
using namespace std;

void swap (int *a , int *b ) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapDiagnols(int arr[N][N]) {

    for (int i =0 , k =0; i <N ;i ++,k++) {
        swap(arr[i][k], arr[i][N-k-1]);
    }
}

int main() 
{   
    int matrix[N][N] = {{0, 1, 2},  
                      {3, 4, 5},  
                      {6, 7, 8}}; 
    
    swapDiagnols(matrix);

    for ( int i = 0;i<N;i++) {
        cout<<endl;
        for (int j =0 ;j<N; j++ ) {
            cout<<matrix[i][j]<<" ";
        }
    }
    return 0; 
} 