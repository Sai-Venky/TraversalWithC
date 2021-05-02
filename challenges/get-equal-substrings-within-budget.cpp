// 


class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
      int j=0;
      int ct =0;
      for(int i=0;i<s.length();i++) {
        if(s[i]!=t[i]) maxCost = maxCost - (abs(s[i]-t[i]));
        
        if(maxCost>=0) {
          ct = max(ct,i-j+1);
        }
        
        while(maxCost <0 && j<=i) {
          if(s[j] != t[j]) {
            maxCost = maxCost + (abs(s[j]-t[j]));
          }
          j++;
        }  
      }
      return ct;
    }
};