// https://leetcode.com/problems/count-submatrices-with-all-ones/

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
      int m=mat.size(), n=mat[0].size(), ct=0;
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          if(j!=0) mat[i][j] = mat[i][j] == 1? mat[i][j-1] + 1:mat[i][j];
        }
      }
      
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          int res = INT_MAX;
          for(int k=i;k<m;k++) {
            
            res = min(res, mat[k][j]);
            ct+=res;
          }
        }
      }
      return ct;
    }
};

/*
https://leetcode.com/problems/count-submatrices-with-all-ones/solutions/2025876/c-monotonic-stack/
class Solution {
public:
	// we just make changes on the input matrix, making it vertically accumulated
    int numSubmat(vector<vector<int>>& ver) {
        int n = ver.size(), m = ver[0].size();
		
        // accumulate vertically
        for(int j = 0; j < m; ++j) 
            for(int i = 1; i < n; ++i) {
                if(ver[i][j]) ver[i][j] = ver[i - 1][j] + 1;
            }
        
        int ret = 0;
        // for each row
        for(auto &v: ver) {
            int tmpret = 0;
			      // make an ending point. make sure the stack will be empty
            v.push_back(0);
            // increasing mono stack
            vector<pair<int, int>> st;  // index, count
            for(int i = 0; i < v.size(); ++i) {
                int cur = v[i];
                // pop the number less than self
                int cnt = 1;  // itself
                while(!st.empty() && cur < v[st.back().first]) {
					          //        the length             the height         number of starting point this entry hold
                    tmpret += (i - st.back().first) * v[st.back().first] * st.back().second;
                    cout<<"index: "<<st.back().first<<" length: "<<i - st.back().first<<" height: "<<v[st.back().first]<<" breadth: "<<st.back().second<<endl;
					          // holding point forwarding
                    cnt += st.back().second;
                    st.pop_back();
                }
                st.emplace_back(i, cnt);
            }
            ret += tmpret;
        }
        return ret;
    }
};

*/

/*
  
  [1,1,1]
  [1,1,0]
  [1,1,0]
  [1,1,0]

  1, 2, 3
  1, 2, 0
  1, 2, 0
  1, 2, 0

  [[0,1,0],[1,1,1],[1,1,1]]

  0 1 0
  1 2 1
  2 3 2

  index: 1 length: 1 height: 1 breadth: 1
  index: 1 length: 1 height: 2 breadth: 1
  index: 2 length: 1 height: 1 breadth: 2
  index: 0 length: 3 height: 1 breadth: 1
  index: 1 length: 1 height: 3 breadth: 1
  index: 2 length: 1 height: 2 breadth: 2
  index: 0 length: 3 height: 2 breadth: 1
  
*/