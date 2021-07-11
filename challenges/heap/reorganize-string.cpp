// https://leetcode.com/problems/reorganize-string

/*
    string reorganizeString(string S) {
        vector<int> cnt(26);
        int mostFreq = 0, i = 0;

        for(char c : S)
            if(++cnt[c - 'a'] > cnt[mostFreq])
                mostFreq = (c - 'a');

        if(2 * cnt[mostFreq] - 1 > S.size()) return "";

        while(cnt[mostFreq]) {
            S[i] = ('a' + mostFreq);
            i += 2;
            cnt[mostFreq]--;
        }

        for(int j = 0; j < 26; j++) {
            while(cnt[j]) {
                if(i >= S.size()) i = 1;
                S[i] = ('a' + j);
                cnt[j]--;
                i += 2;
            }
        }

        return S;
    }
*/
class Solution {
public:
    string reorganizeString(string s) {
      vector<int> v(26, 0);
      priority_queue<pair<int, char>> q;
      string out="";
      
      for(char c:s) {
        v[c-'a']++;
      }
      for(int i=0;i<26;i++) if(v[i]>0) q.push({v[i], i +'a'});
      
      
      while(!q.empty()) {
        pair<int, char> p1=q.top(); q.pop();
        if(q.empty())  {
          if(p1.first>1) return "";
          else {
            out.push_back(p1.second); 
            break;
          }
        }
        pair<int, char> p2=q.top(); q.pop();
        
        out.push_back(p1.second);
        out.push_back(p2.second);
        p1.first--;
        p2.first--;
        if(p1.first>0) q.push(p1);
        if(p2.first>0) q.push(p2);
      }
      
      return out;
    }
};
