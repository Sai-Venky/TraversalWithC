// https://leetcode.com/problems/unique-binary-search-trees

class Solution {
public:
    int countUniqueTrees(int n, vector<int> &dp) {
        int noOfTrees=0;
        if(dp[n]!=0) {
            return dp[n];
        }
        for(int i=1; i<=n; i++) {
            noOfTrees+=(countUniqueTrees(i-1, dp) * countUniqueTrees(n-i, dp));
        }
        dp[n] = noOfTrees;
        return noOfTrees;
    }
    
    int numTrees(int n) {
        vector<int> dp(20, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        return countUniqueTrees(n, dp);
    }
};