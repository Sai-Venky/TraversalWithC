#include<iostream>
using namespace std;

int maxSum = 0;

void maxSubArraySum(int *a, int n, int k) {
    int curSum = 0;
    for(int i =k ;i<n; i++) {
        curSum += a[i];
        if (curSum>maxSum) {
            maxSum = curSum;
        }
    }
}

int main() 
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    int n = sizeof(a)/sizeof(a[0]); 
    for(int i =0 ;i<n; i++) {
        maxSubArraySum(a, n , i);
    }
    cout<<maxSum;
    return 0;
}
