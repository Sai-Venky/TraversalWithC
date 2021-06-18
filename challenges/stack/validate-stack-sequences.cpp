// https://leetcode.com/problems/validate-stack-sequences


/*
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        int i = 0;
        for (int x : pushed) {
            stack.push(x);
            while (stack.size() && stack.top() == popped[i]) {
                stack.pop();
                i++;
            }
        }
        return stack.size() == 0;
    }
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      stack<int> s;
      int n=pushed.size(), i=0, j=0;
      
      for(int i=0,j=0;i<n;i++) {
        
        if(s.empty() || s.top() != popped[i]) {
          while(j<n && pushed[j] !=popped[i]) {
            s.push(pushed[j]);
            j++;
          }
          if(j>=n) return false;
          j++;
         } else if (!s.empty() && s.top() == popped[i]) {
          s.pop();
        } 
        
      }
      return true;
    }
};