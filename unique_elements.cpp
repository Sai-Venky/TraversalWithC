#include<iostream>
using namespace std;
# define N 3
# define M 4


void uniqueElements(int A[M][N]) {
    int uniq[M*N], k=0, l=0;
    int numbers[M*N];
    for(int i =0; i<M ;i++) {
        for(int j= 0;j<N;j++) {
            numbers[k++] = A[i][j];
        }
    }

    for(int i =0; i<k ;i++) {
        int isUnique = 1;
        for(int j=0;j<k;j++) {
            if(i!=j && numbers[i] == numbers[j])
                isUnique = 0;
        }
        if(isUnique) {
            uniq[l++] = numbers[i];
        }
    }

    for(int i=0;i<l;i++) {
        cout<<" "<<uniq[i];
    }
}

int main(){

    int A[][3] = {
        {1, 22, 3},
        {5, 6, 2},
        {1, 3, 5}, 
        {6, 2, 2}
    };

    uniqueElements(A);

    return 0;
}