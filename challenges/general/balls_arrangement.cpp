// https://www.geeksforgeeks.org/ways-to-arrange-balls-such-that-adjacent-balls-are-of-different-types/

#include<iostream>
#include<string>

using namespace std;

int arrangementCount = 0;
string arrangements[100];

struct stringTraversal {
    char key;
    stringTraversal * next;
};

bool checkIfAdjancent(string str) {
    for(int i=0; i<str.length()-1; i++) {
        if(str[i] == str[i+1]) {
            return true;
        }
    }
    return false;
}

bool duplicateArrangement(string arrangement) {
    for(int i=0; i<arrangementCount; i++) {
        if(arrangement.compare(arrangements[i]) == 0) {
            return true;
        }
    }
    return false;
}

string getArrangementString(stringTraversal *curArrangement) {
    stringTraversal * temp = curArrangement;
    int current = 0;
    char str[100];
    while(temp!=NULL) {
        if(temp->key) {
            str[current++] = temp->key;
        } else {
            str[current] = '\0';
        }
        temp = temp->next;
    }
    return str;
}

void arrangeString(stringTraversal *curArrangement, int noP, int noQ, int noR, int i, int j, int k, char selectedChar) {
    int totalLength = noP + noQ + noR;

    string curString = getArrangementString(curArrangement);
    if(curString.length() == totalLength) {
        if(!checkIfAdjancent(curString) && !duplicateArrangement(curString)) {
            arrangements[arrangementCount] = curString;
            arrangementCount++;
        }
    } else {
        bool proceed = false;
        if(selectedChar == 'p' && i < noP) {
            proceed = true;
            i++;
        }
        if(selectedChar == 'q' && j < noQ) {     
            proceed = true;   
            j++;
        }
        if(selectedChar == 'r' && k < noR) {   
            proceed = true;
            k++;
        }    

        if(proceed) {
            stringTraversal *nextArrangement = (stringTraversal *)malloc(sizeof(stringTraversal));
            nextArrangement->next = NULL;
            nextArrangement->key = selectedChar;
            nextArrangement->next = curArrangement;
            curArrangement = nextArrangement;    
        }

        if(proceed || selectedChar == 's') {
            arrangeString(curArrangement, noP, noQ, noR, i, j, k, 'p');
            arrangeString(curArrangement, noP, noQ, noR, i, j, k, 'q');
            arrangeString(curArrangement, noP, noQ, noR, i, j, k, 'r');
        }

    }
}

void noOfArrangement(int noP, int noQ, int noR) {
    stringTraversal *arrangement = (stringTraversal *)malloc(sizeof(stringTraversal));
    arrangement->next = NULL;
    arrangeString(arrangement, noP, noQ, noR, 0, 0, 0, 's');
}

int main() {
    int noP = 2, noQ = 1, noR = 1;

    // cout<<"Enter the number of P, Q, R";
    // cin>>noP>>noQ>>noR;

    noOfArrangement(noP, noQ, noR);

    cout<<"\nThe Number of Possible Arrangements are "<< arrangementCount;
    for(int i=0; i<arrangementCount; i++) {
        cout<<"\nArrangement "<<i+1<<" "<<arrangements[i];
    }
    return 0;
}