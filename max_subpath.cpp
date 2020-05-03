#include<iostream>
#define N 4
#define M 6
using namespace std;

int globMax = 0;

int maxi(int a, int b, int c) {
    int max =0;
    if(a>b && a>c) {
        return a;
    } else if (b>a && b>c) {
        return b;
    } else {
        return c;
    }
}

int findMaxPath(int arr[][M], int l, int sum, int level){
    int max;
    sum = sum +  arr[level][l];
    if(level == N-1) {
        cout<<sum<<"The column is "<<l<<" and level is "<<level<<endl;
        return sum;
    }
    if (l == 0) {
    max = maxi(findMaxPath(arr, 0, sum, level+1), findMaxPath(arr, 1, sum, level+1), 0);
    } else if (l == M-1) {
    max = maxi(findMaxPath(arr, M-1, sum, level+1), findMaxPath(arr, M-2, sum, level+1), 0);
    } else {
    max = maxi(findMaxPath(arr, l, sum, level+1), findMaxPath(arr, l-1, sum, level+1), findMaxPath(arr, l+1, sum, level+1));
    }
    if (max>globMax) {
        globMax = max;
    }
    return globMax;
}

int main() 
{   int k;
      
    int mat1[N][M]={{1, 2, 3}, 
    {9, 8,7 }, {4, 5,6}}; 
              
    for (int i =0;i<M;i++) {
        k = findMaxPath(mat1, i, 0, 0);
    }
    cout << k << endl; 
    return 0; 
} 