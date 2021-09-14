// https://leetcode.com/problems/allocate-mailboxes

// Note the costs computation with median, then the init part of 1 house and i is the median till there.

/*
    https://leetcode.com/problems/allocate-mailboxes/discuss/685620/JavaC%2B%2BPython-Top-down-DP-Prove-median-mailbox-O(n3)
    Top Down
    class Solution { // 22 ms, faster than 67.87%
        public:
            const int INF = 100 * 10000; // maximum distance = N * MAX_POS = 100 * 10^4 = 10^6
            int costs[100][100] = {};
            int memo[100][100] = {};
            int minDistance(vector<int>& houses, int k) {
                int n = houses.size();
                sort(houses.begin(), houses.end());
                memset(memo, -1, sizeof(memo));
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int medianPos = houses[(i + j) / 2];
                        for (int m = i; m <= j; m++)
                            costs[i][j] += abs(medianPos - houses[m]);
                    }
                }
                return dp(houses, n, k, 0);
            }
            int dp(vector<int>& houses, int n, int k, int i) {
                if (k == 0 && i == n) return 0;
                if (k == 0 || i == n) return INF;
                if (memo[k][i] != -1) return memo[k][i];
                int ans = INF;
                for (int j = i; j < n; j++)
                    ans = min(ans, costs[i][j] + dp(houses, n, k-1, j + 1));
                return memo[k][i] = ans;
            }
        };
*/

class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
      int n=houses.size();
      vector<vector<int>> costs(n, vector<int>(n, 0));
      vector<vector<int>> dp(k+1, vector<int>(n, 0));
      sort(houses.begin(), houses.end());
      
      for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
          int sum=0;
          for(int k=i;k<=j;k++) {
            sum+=abs(houses[k]-houses[(i+j)/2]);
          }
          costs[i][j] = sum;
        }
      }
      
      for(int i=0;i<n;i++) {
        dp[1][i] = costs[0][i];
      }
      
      
      for(int x=2;x<=k;x++) {
        for(int i=0;i<n;i++) {
          dp[x][i]= 1e9 + 10;
          for(int j=0;j<i;j++) {
            dp[x][i] = min(dp[x][i], dp[x-1][j] + costs[j+1][i]);
          }
        }
      }
      
      return dp[k][n-1];
    }
};