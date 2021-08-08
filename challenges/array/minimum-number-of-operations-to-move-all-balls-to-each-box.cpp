// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

/*
    Logic - Perform 2 passes of the array left and right while calculating movement
    Code - Store prefix array
*/

/*
class Solution {
public:
    vector<int> minOperations(string boxes) {
      vector<int> out(boxes.size(), 0);
      
      unordered_set<int> m;
      
      for(int i=0;i<boxes.size();i++) {
        if(boxes[i]=='1') m.insert(i);
      }
      
      for(int i=0;i<boxes.size();i++) {
        for(auto v:m) {
          out[i]+=(abs(v-i));
        }
      }
      
      return out;
    }
};
o(n^2)
*/

class Solution {
public:
    vector<int> minOperations(string boxes) {
      vector<int> out(boxes.size(), 0);
      
      int sum=0;  
      int ct=0;
      for(int i=0;i<boxes.size();i++) {
        out[i]=sum;
        if(boxes[i]=='1') ct+=1;
        sum+=ct;
      }
      
      sum=0;  
      ct=0;
      for(int i=boxes.size()-1;i>=0;i--) {
        out[i]+=sum;
        if(boxes[i]=='1') ct+=1;
        sum+=ct;
      }
      
      return out;
    }
};