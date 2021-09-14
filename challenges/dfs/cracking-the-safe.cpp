// https://leetcode.com/problems/cracking-the-safe/

// Note the use of DFS here to perform the traversals

class Solution {
public:
    bool dfs(string &str, unordered_set<string>& s, int k, int goal, int n) {
      
      if(s.size() == goal) return true;
      
      for(int i=0;i<k;i++) {
        
        string next = str + to_string(i);
        if(s.count(next.substr(next.length()-n, n)) == 0) {
          s.insert(next.substr(next.length()-n, n));
          if(dfs(next, s, k, goal, n)) {
            str=next;
            return true;
          } else {
            s.erase(next.substr(next.length()-n, n));
          }
          
        }
          
      }
      return false;
    }
  
    string crackSafe(int n, int k) {
      
      unordered_set<string> s;
      int goal = pow(k, n);
      string pass = "";
      for(int i=0;i<n; i++) pass.push_back('0');
      s.insert(pass.substr(0, n));

      dfs(pass, s, k, goal, n);
      
      return pass;
    }
};

// 

string crackSafe(int n, int k) {
        string ans = string(n, '0');
        unordered_set<string> visited;
        visited.insert(ans);
        
        for(int i = 0;i<pow(k,n);i++){
            string prev = ans.substr(ans.size()-n+1,n-1);
            for(int j = k-1;j>=0;j--){
                string now = prev + to_string(j);
                if(!visited.count(now)){
                    visited.insert(now);
                    ans += to_string(j);
                    break;
                }
            }
        }
        return ans;
    }