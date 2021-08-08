// https://leetcode.com/problems/make-array-strictly-increasing/

/*
    Good Question 
    Lot of Intuition
    https://leetcode.com/problems/make-array-strictly-increasing/discuss/556465/C%2B%2B-DP-and-binary-search-with-explanation-or-O(n*m*logm)-runtime
    https://leetcode.com/problems/make-array-strictly-increasing/discuss/377402/C%2B%2B-DFS-%2B-memo-based-on-Longest-Increasing-subsequence-solution-with-explanation
    Notes
    Use of i to store array position and j to store the number of operations done.
    Use of array to store the minimum value,
    Final Loop to check and return.
*/

class Solution {
public:
    int dp[2001][2001] = {} , mx_val = 2001;
    int solve(vector<int>&a,vector<int>&b,int i,int j,int prev)
    {
        // base case
        // if i is out of a.length()
        if(i >= a.size())
            return 0;
         
        // take the index of element  array b whic is greater than prev
        j = upper_bound(b.begin() , b.end() , prev) - b.begin();
        
        // if my prev is greater than the last elemnt of a then we are unable to sort the array a
        if( prev >= a[i] && j >= b.size() )
            return mx_val;
        
        if(dp[i][j] == 0)
        dp[i][j] = j < b.size() ? 1 + solve(a,b,i+1,j,b[j]):mx_val ;
        // if prev elemnt of array a is smaller than next than o need of conversion 
        
        if(prev < a[i])
            dp[i][j] = min(dp[i][j] , solve(a,b,i+1,j,a[i]));
        
        return dp[i][j];
    }
    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        
        // sort the second aray in order to start with the smallest element
        sort(b.begin() , b.end());
        int p = solve(a,b,0,0,-1e9);
        return p >= mx_val ? -1 : p;
    }
};

class Solution {
public:  
    int makeArrayIncreasing(vector<int>& ar1, vector<int>& ar2) {
        int n = ar1.size(), m = ar2.size();
        sort(ar2.begin(), ar2.end());
        int dp[n][n+1];
        dp[0][0] = ar1[0];
        dp[0][1] = (ar2[0] < ar1[0]) ? ar2[0] : INT_MAX;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i+1; j++) {
                dp[i][j] = INT_MAX;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[i-1][j] < ar1[i]) {
                    dp[i][j] = min(dp[i][j], ar1[i]);
                }
                int index=upper_bound(ar2.begin(), ar2.end(), dp[i-1][j])-ar2.begin();
                int val=index==m?INT_MAX:ar2[index];
                dp[i][j+1] = min(dp[i][j+1], val);
            }
        }
        for (int i = 0; i <= n; i++) {
            if (dp[n-1][i] < INT_MAX) {
                return i;
            }
        }
        return -1;
    }
};

