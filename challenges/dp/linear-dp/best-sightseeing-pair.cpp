// https://leetcode.com/problems/best-sightseeing-pair

/*
    Logic - 
    Note the use of score which keeps track of the net difference contribution here.
    [8,1,5,2,6]
    eg :- for 1, the contribution of 8 is 8-1=7
    for 5 its the above 7-1 (since decreasing) or 1-1.
*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
      
      int score=values[0]-1;
      int maxScore=0;
      for(int i=1;i<values.size();i++) {
        score=max(score-1, values[i-1]-1);
        maxScore=max(maxScore, score+values[i]);
      }
      
      return maxScore;
    }
};
