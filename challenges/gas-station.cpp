// https://leetcode.com/problems/gas-station

class Solution {
public:
    int index,ct;
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      index =-1;
      ct=-1;
      for(int i=0;i<gas.size(); i++) {
        // cout<<"iteration "<<i<<"\n";        
        canComplete(gas, cost, i, gas[i]);
      }
      return index;
    }
  
    void canComplete(vector<int>& gas, vector<int>& costs, int start, int cost) {
      ct++;
      start = start==gas.size()?0:start;
      int next = start+1==gas.size()?0:start+1;
      if(cost>0||ct==1) {
        if(ct==gas.size()) {
          index = start;
        } else {
          cost = cost - costs[start];
          if(cost>=0) {
            cost+=gas[next];
            canComplete(gas, costs, start+1, cost);     
          }

        } 
      }

      ct--;
    }
  
};