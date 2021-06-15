// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int n=temperatures.size();
      vector<int> output(n, 0);
      stack<int> s;
      
      for(int i=0;i<n;i++) {
        while(!s.empty() && temperatures[s.top()]<temperatures[i]) {
          output[s.top()] = i-s.top();
          s.pop();
        }
        s.push(i);

      }
      
      return output;
    }
};