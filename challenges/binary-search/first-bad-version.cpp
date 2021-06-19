// https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    int binarySearch(unsigned startPos, unsigned endPos) {
        int midPos = (startPos + endPos) /2;
        bool mid = isBadVersion(midPos);
        bool start = isBadVersion(midPos-1);

        if(midPos <startPos || midPos >endPos) {
            return -1;
        }
        if(mid == true && start == false) {
            return midPos;
        } else if(mid == true && start == true){
            return binarySearch(startPos, midPos-1);
        } else{
            return binarySearch(midPos+1, endPos);
        }
    }
    
    int firstBadVersion(int n) {
        return binarySearch(0, n);
    }
};