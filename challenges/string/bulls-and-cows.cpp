// https://leetcode.com/problems/bulls-and-cows

// SF

class Solution {
public:
    string getHint(string secret, string guess) {
      vector<int> m(26, 0);
      int b=0, c=0;
      
      for(char c:secret) m[c-'0']++;
      
      for(int i=0;i<secret.size();i++) if(secret[i]==guess[i]) {
        m[secret[i]-'0']--;
        b++;
      } 

      for(int i=0;i<secret.size();i++) 
        if(secret[i]!=guess[i] && m[guess[i]-'0']>0) {
          m[guess[i]-'0']--; c++;
        }
      
      string out = to_string(b) + 'A' + to_string(c) + 'B';
      return out;
    }
};