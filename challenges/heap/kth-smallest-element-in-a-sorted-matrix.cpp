// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix


/*
class Solution {
private:
    int countGreater(vector<vector<int>>& a, int k){
        int n = a.size();
        int count = 0;
        int i = 0, j = n - 1;
        while(i < n && j >= 0){
            if(a[i][j] > k) j --;
            else{
                count += j + 1;  // +1 because it's zero based indexing
                i++;
            }
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        if(a.size() == 0) return -1;
        int result = -1;
        int low = a[0][0], high = a[a.size()-1][a.size()-1];
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(countGreater(a, mid) >= k){
                result = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return result;
    }
};


*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      
      priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;      
      pair<int, pair<int, int>> p;
      int val;
      int n=matrix.size();
      
      for(int i=0;i<n;i++) {
        q.push({matrix[i][0], {i, 0} });
      }
      
      while(!q.empty() && k) {
        p = q.top();
        q.pop();
        val=p.first;
        int i=p.second.first;
        int j=p.second.second;
        if(j+1<n)
          q.push({matrix[i][j+1], {i, j+1} });
        k--;
      }
      
      return val;
      
    }
};