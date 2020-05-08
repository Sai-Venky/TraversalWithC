#include<iostream>
using namespace std;

int balancedParantesis = 0;

struct ParanthesisTracker {
    int paranthesisValue;
    string paranthesisString;
    int start;
};

int countTracker(char paranthesis) {
    if(paranthesis == '(') return 1;
    if(paranthesis == '{') return 2;
    if(paranthesis == '[') return 3;
    if(paranthesis == ')') return -1;
    if(paranthesis == '}') return -2;
    if(paranthesis == ']') return -3;
    return 1000;
}

void noOfBalSubstrings(string str, int n, int i, ParanthesisTracker paranthesisTracker, int dp[100][100]) {
    if(i==n+1) {
        return;
    }

    if(paranthesisTracker.paranthesisValue == 0) {
        int start = paranthesisTracker.start;
        if(dp[start][i-1] == 0) {
            cout<<"\n"<<paranthesisTracker.paranthesisString;
            dp[start][i-1] = 1;
            balancedParantesis++;
        }
    }
    int currentParanthesisValue = countTracker(str[i]);

    paranthesisTracker.paranthesisString.push_back(str[i]);
    paranthesisTracker.paranthesisValue += currentParanthesisValue;
    if(paranthesisTracker.paranthesisValue >= 0) {
        noOfBalSubstrings(str, n, i+1, paranthesisTracker, dp);
    }

    if(currentParanthesisValue < 0) {
        return;
    }
    paranthesisTracker.paranthesisString = str[i];
    paranthesisTracker.paranthesisValue = currentParanthesisValue;
    paranthesisTracker.start = i;
    noOfBalSubstrings(str, n, i+1, paranthesisTracker, dp);



}

int main(){
    string str = "(())()"; 
    ParanthesisTracker paranthesisTracker;
    paranthesisTracker.paranthesisString = str[0];
    paranthesisTracker.paranthesisValue = countTracker(str[0]);
    paranthesisTracker.start = 0;
    int n = str.size(); 
    int dp[100][100];
    noOfBalSubstrings(str, n, 1, paranthesisTracker, dp);
    cout << "\n"<<balancedParantesis; 

    return 0;
}