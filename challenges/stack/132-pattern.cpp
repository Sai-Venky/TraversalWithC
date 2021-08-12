// https://leetcode.com/problems/132-pattern

/*
  Logic - Note the use of stack. Maintain the monotonic decreasing stack and the largest and second largest values.
  Code - Stack
  RUNTIME: Each item is pushed and popped once at most, the time complexity is therefore O(n).
*/

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

