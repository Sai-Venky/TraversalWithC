// https://www.geeksforgeeks.org/count-of-subarrays-of-an-array-having-all-unique-digits/

#include<iostream>
#include <vector> 

using namespace std;
#define totalElements 7

struct uniqueSubarrays {
    int uniqueSubarraysCount;
    vector<int> uniqueSubarrays[2^totalElements-1];
};
uniqueSubarrays uniqueSubarraysTracker;

struct subArray {
    int subarrayDigits[10];
    vector<int> subarray;
};

// Checks if sub array already present or a new sub array has to be created
void isSubsetsTrackerEligible( subArray subArrayTracker) {
    bool createNew = true;
    if(subArrayTracker.subarray.size() != 0) {
        for(int i =0; i<uniqueSubarraysTracker.uniqueSubarraysCount; i++) {
            if(uniqueSubarraysTracker.uniqueSubarrays[i] == subArrayTracker.subarray) {
                createNew = false;
                break;
            }
        }
    } else {
        createNew = false;
    }
    if(createNew) {
        uniqueSubarraysTracker.uniqueSubarrays[uniqueSubarraysTracker.uniqueSubarraysCount] = subArrayTracker.subarray;
        uniqueSubarraysTracker.uniqueSubarraysCount++;
    }
}

// Checks if current element is unique and eligible to be formed as part of the subarray
bool checkIfElementIsEligibleForTheSubset(int *array, subArray subArrayTracker, int elementPos) {
    int element = array[elementPos];
    while(element != 0) {
        int unitsPos = element % 10;
        if(subArrayTracker.subarrayDigits[unitsPos] == 1) {
            return false;
        }
        element = element / 10;
    }
    return true;
}

// if element is unique and eligible then its added as part of the subarray
subArray updateElementInSubsetTracker(int *array, subArray subArrayTracker, int elementPos) {
    int element = array[elementPos];
    while(element != 0) {
        int unitsPos = element % 10;
        subArrayTracker.subarrayDigits[unitsPos] = 1;
        element = element / 10;
    }

    subArrayTracker.subarray.push_back(array[elementPos]);
    return subArrayTracker;
}

// Sub Arrays are explored to find possible unique subarrays. 
// Each Sub Array is stopped from proceeding if its not eligible
void findUniqueDigitsSubarrays(int *array, subArray subArrayTracker, int elementPos, bool considerElement) {
    if(elementPos > totalElements-1) {
        isSubsetsTrackerEligible(subArrayTracker);
        return;
    }
    if(considerElement) {
        bool eligible = checkIfElementIsEligibleForTheSubset(array, subArrayTracker, elementPos);
        if(eligible) {
            subArrayTracker = updateElementInSubsetTracker(array, subArrayTracker, elementPos);
        } else {
            return;
        }
    }
    findUniqueDigitsSubarrays(array, subArrayTracker, elementPos+1, true);
    findUniqueDigitsSubarrays(array, subArrayTracker, elementPos+1, false);
}

int main() {
    int array[totalElements] = {5, 12, 2, 1, 165, 2323, 7};
    uniqueSubarraysTracker.uniqueSubarraysCount = 0;

    subArray subArrayTracker;
    memset(subArrayTracker.subarrayDigits, 0, sizeof(subArrayTracker.subarrayDigits)); 

    findUniqueDigitsSubarrays(array, subArrayTracker, -1, false);


    cout<<"\nThe Unique Sub Arrays Count is "<<uniqueSubarraysTracker.uniqueSubarraysCount;
    cout<<"\nThe Unique Sub Arrays are";
    for(int i=0; i<uniqueSubarraysTracker.uniqueSubarraysCount; i++){
        cout<<"\n";
        for (int j = 0; j < uniqueSubarraysTracker.uniqueSubarrays[i].size(); j++) 
            cout<<uniqueSubarraysTracker.uniqueSubarrays[i][j]<<" ";
        }
    return 0;
}