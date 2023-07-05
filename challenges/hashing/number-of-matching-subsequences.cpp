// https://leetcode.com/problems/number-of-matching-subsequences


/*
    O(N+S) where N is length of string and S is sum of length of all words.
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
// O(ablogc) where a is no of words, b is max length of each word and c is length of string s.
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