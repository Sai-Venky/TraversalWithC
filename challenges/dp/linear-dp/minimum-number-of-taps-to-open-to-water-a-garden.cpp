// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden

/*
    https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/discuss/712660/DP-pattern-to-solve-3-similar-problems
     public int minTaps(int[] ranges) {
		int len = ranges.length;
		int[] dp = new int[len]; 
		Arrays.fill(dp, len + 1); 
		dp[0] = 0;

		for (int i = 0; i < len; i++) {
			int start = Math.max(i - ranges[i], 0);
			int end = Math.min(i + ranges[i], len - 1);
			for (int j = start; j <= end; j++) {
				dp[j] = Math.min(dp[j], dp[start] + 1);
			}
		}

		return dp[len - 1] == len + 1 ? -1 : dp[len - 1];
	}

*/
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
      vector<int> intervals(n+1);
      int out=0;
      
      for(int i=0;i<ranges.size();i++) {
        intervals[max(i-ranges[i], 0)]=max(intervals[max(i-ranges[i], 0)], min(n, i+ranges[i]));
      }
      
      int end=intervals[0], newend=end;
      for(int i=1;i<=n;i++) {
        if (i>newend) return -1;
            
        newend = max(newend,intervals[i]);

        if (i == end) {
            out++;
            end = newend;
        }
        
      }
      return newend>=end?out:-1;
    }
};