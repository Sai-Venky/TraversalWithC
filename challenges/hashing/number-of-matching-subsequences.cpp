// https://leetcode.com/problems/number-of-matching-subsequences


/*
    int numMatchingSubseq(string S, vector<string>& words) {
        int cnt=0;
        unordered_map<char,vector<string>> m;
        for (auto& word: words) m[word.back()].push_back(word);
        for (int i=(int)S.size()-1; i>=0; --i){
            char c=S[i];
            auto bucket=m[c];
            m[c].clear();
            for (auto& word: bucket){
                word.pop_back();
                if (word.empty())
                    ++cnt;
                else
                    m[word.back()].push_back(word);
            }
        }
        return cnt;
    }
*/

// Note the upper bound being calculated after storing the meta information
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
      int ct=0;
      unordered_map<char, vector<int>> m;
      
      
      for(int i=0;i<s.length();i++) {
        m[s[i]].push_back(i);
      }
      
      for(int i=0;i<words.size();i++) {
        int pos=-1;
        bool poss=true;
        for(int j=0;j<words[i].length();j++) {
          char c=words[i][j];
          auto it=upper_bound(m[c].begin(), m[c].end(), pos);
          if (it == m[c].end()) {
            poss=false;
            break;
          } else {
            pos=*it;
          }
        }
        if(poss) ct++;
      }
        
      
      return ct;
    }
};