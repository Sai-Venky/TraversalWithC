// https://www.geeksforgeeks.org/maximize-binary-matrix-filpping-submatrix/

#include<iostream>

using namespace std;
#define ROW 3
#define COL 3
#define totalElements ROW * COL
int maximumMatrixSum = 0;
int countNO = 0;
int sumOfMatrixElements(int matrix[][COL]) {
    int sum = 0;
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            sum +=  matrix[i][j];
        }
    }
    return sum;
}

int flipValue(int i) {
    if(i == 1) {
        return 0;
    } else {
        return 1;
    }
}

int obtainFliipedMatrixSum(int matrix[][COL], int startRow, int startCol, int endRow, int endCol) {
    int sum = 0;
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            if(i>=startRow && i<=endRow && j>=startCol && j<=endCol) {
                sum = sum + flipValue(matrix[i][j]);
            } else {
                sum = sum + matrix[i][j];
            }
        }
    }
    return sum;

}

int computeFlippedMatrixSum(int flippedSumMatrix[totalElements][totalElements], int matrix[][COL], int i, int j) {
    int startRow = i/COL;
    int startCol = i%COL;
    int endRow = j/COL;
    int endCol = j%COL;
    if(flippedSumMatrix[j][i]) {
        countNO++;
        flippedSumMatrix[i][j] = flippedSumMatrix[j][i];
    }
    return obtainFliipedMatrixSum(matrix, startRow, startCol, endRow, endCol);
}

void flipAndMaximizeMatrix(int matrix[][COL]) {
    int flippedSumMatrix[totalElements][totalElements] = {0};
    for(int i=0; i<totalElements; i++) {
        for(int j=0; j<totalElements; j++) {
            flippedSumMatrix[i][j] = computeFlippedMatrixSum(flippedSumMatrix, matrix, i, j);
            if(flippedSumMatrix[i][j] > maximumMatrixSum) {
                maximumMatrixSum = flippedSumMatrix[i][j];
            }
        }
    }

    // for(int i=0; i<totalElements; i++) {
    //     cout<<"\n";
    //     for(int j=0; j<totalElements; j++) {
    //         cout<<flippedSumMatrix[i][j]<<" ";
    //     }
    // }
}

int main() {

    int matrix [ROW][COL] = {
        {0, 0, 1},
        {0, 0, 1},
        {1, 0, 1}
    };
    maximumMatrixSum = sumOfMatrixElements(matrix);
    flipAndMaximizeMatrix(matrix);
    cout<<countNO<<"\n The Maximum Sum of the Matrix is "<<maximumMatrixSum;
    return 0;
}