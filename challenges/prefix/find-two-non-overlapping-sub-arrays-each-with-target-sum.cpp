// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum


/*
    1. The l1, l2 combo where if l1 changes , then l2 changes ensures that we CONSIDER the outputs in sequential format 
    that is l2 is considered after l1.
    2. sum+target is another good addition to check
*/

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
      int n=arr.size(), sum=0, diff;
      unordered_map<int,int> m;
      m[0] = -1;
      for(int i=0;i<arr.size();i++) {
        sum+=arr[i];
        m[sum]=i;
      }
      int l1 = sum+1, l2 = sum+1, maxSum=sum+1;
      sum=0;
      
      for(int i=0;i<arr.size();i++) {
        sum+=arr[i];
        if( m.find(sum - target) !=m.end() ) {
          l1 = min(l1, i-m[sum - target]);
        }
        
        if( m.find(sum + target) !=m.end() && l1!=maxSum) {
          l2 = min(l2, l1 + m[sum + target]-i); 
        }
        
        
      }
      
      if(l2 == maxSum) return -1;
      return l2;
    }
};

// My code


class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> left(n, INT_MAX); vector<int> right(n, INT_MAX);

        int sum = 0, j=0;

        for(int i=0;i<n;i++) {
            sum+=arr[i];

            while(i>=j && sum>target) {
                sum-=arr[j++];
            }
            left[i] = i != 0 ? left[i-1]: left[i];
            if(sum == target) {
                left[i] = min(left[i], i-j+1);
            }
        }

        sum=0; j=n-1;
        for(int i=n-1; i>=0; i--) {
            sum+=arr[i];

            while(i<=j && sum>target) {
                sum-=arr[j--];
            }
            right[i] = i != n-1 ? right[i+1]: right[i];
            if(sum == target) {
                right[i] = min(right[i], abs(i-j-1));
            }
        }

        int mn=INT_MAX;
        for(int i=0;i<n;i++) {
            if(i!=0 && left[i-1]!=INT_MAX && right[i] != INT_MAX) {
                mn = min(mn, left[i-1] + right[i]);
            }
            if(i!=n-1 && left[i]!=INT_MAX && right[i+1] != INT_MAX) {
                mn = min(mn, left[i] + right[i+1]);
            }
        }

        return mn == INT_MAX?-1:mn;
    }
};