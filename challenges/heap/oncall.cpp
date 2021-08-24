/*
A  1, 10
B  5, 7
C  6, 12
D  15, 17
// timestamps

// Output:

[1, 5] A
[5, 6] A, B
[6, 7] A, B, C
[7, 10] A, C
[10, 12] C
[15, 17] D
Intervals + Labels

-----------------------------

1, S, A - 10, E, A
5, S, B -  7, E, B
6, S, C - 12, E, C

Another variable - Track of all the current on-time
*/

Solution

pair<vector<vector<int>>, vector<unordered_set<char>>> onCallTracking(vector<vector<int>> intervals, vector<char> labels) {
  vector<vector<int>> outputintervals;
  vector<unordered_set<char>> labels;
  priority_queue<pair<int, pair<bool, char>>, vector<pair<int, pair<bool, char>>, greater<pair<int, pair<bool, char>>> q;
  if(labels.size()==0) return {outputintervals, labels};
  
  for(int i=0;i<intervals.size();i++) {
    q.push({intervals[i][0], {true, labels[i]}});
    q.push({intervals[i][1], {false, labels[i]}});
  }
  
  int prev=-1, cur=-1;
  unordered_set<char> oncall;
  
  while(!q.empty()) {
    pair<int, pair<bool, char>> p = q.top(); q.pop();
    
    if(prev==-1) {
      prev = p.first;
    } else {
      prev = cur;
      cur= p.first;
    }
    
    
    if(prev!=cur && oncall.size()>0) {
      outputintervals.push_back(vector<int>{prev, cur});
      labels.push_back(oncall);
    }

    if(p.second.first==true) {
      oncall.insert((p.second.second);
    } else if (p.second.first==false) {
      oncall.erase((p.second.second);
    }
    
  }

  return {outputintervals, labels};
}