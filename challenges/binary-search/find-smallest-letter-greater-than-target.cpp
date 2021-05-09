// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
      int low=0, high=letters.size()-1;
      char res = letters[0];
      while(low<=high) {
        
        int mid = low + (high-low)/2;
        if(letters[mid] > target) {
          res = letters[mid];
          high=mid-1;
        } else {
          low=mid+1;
        }
        
      }
      return res;
    }
};