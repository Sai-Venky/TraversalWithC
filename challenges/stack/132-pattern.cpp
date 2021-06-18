// https://leetcode.com/problems/132-pattern

class Solution {
public:
    bool find132pattern(vector<int>& A) {
      
      stack<int> s;
      int sec=INT_MIN;
      
      for(int i=A.size()-1;i>=0;i--) {
        
        if(A[i] < sec) {
          return true;
        }
        while(!s.empty() && A[i] > s.top()) {
          sec = s.top();
          s.pop();
        }
        s.push(A[i]);  
      }
      
      
      return false;
    }
};

