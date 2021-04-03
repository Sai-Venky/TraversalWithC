// https://leetcode.com/problems/di-string-match

class Solution {
public:
    vector<int> diStringMatch(string S) {
        
      int end = S.length(), start = 0;
      vector<int> permutation;
      int i=0;
      while(start<end) {
        if(S[i] == 'D') {
          permutation.push_back(end);
          end--;
        } else {
          permutation.push_back(start);
          start++;
        }
        i++;
      }
      permutation.push_back(end);
      
      return permutation;
    }
};