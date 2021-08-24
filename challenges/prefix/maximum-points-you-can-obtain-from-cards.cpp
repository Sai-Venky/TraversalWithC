// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

// Note the use of back and front sums

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int n=cardPoints.size();
      vector<int> accu(n, 0);
      accu[0]=cardPoints[0];
      for(int i=1;i<n;i++) {
        accu[i] += cardPoints[i] + accu[i-1];
      }
      if(k>=n) {
        return accu[n-1];
      }
      int m=0;
      for(int i=0;i<=k;i++) {
        int left =  i>0 ? accu[i-1]: 0;
        int right = accu[n-1] - accu[n-1-(k-i)];
        m=max(m, left+right);
      }
      return m;
    }
};