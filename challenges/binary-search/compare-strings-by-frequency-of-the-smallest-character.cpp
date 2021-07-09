// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/

class Solution {
public:
    int count(string str) {
      map<char, int> m;
      int ma=0;
      for(char c:str) {
        m[c]++;
      }  
      for(auto v:m) {
        ma=v.second;break;
      }
      return ma;
    }
  
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
      vector<int> w;
      vector<int> q;
      for(string query:queries) {
        q.push_back(count(query));
      }
      vector<int> out(queries.size());
      for(string word:words) {
        w.push_back(count(word));
      }
      sort(w.begin(), w.end());
      for(int i = 0; i < q.size(); i++) {
        int l=0, h=w.size()-1, m;
        while(l<=h) {
          m=l+(h-l)/2;
          if(w[m]>q[i]) {
            h=m-1;
          } else {
            l=m+1;
          }
        }
        out[i] = w.size()-l;
      }
      
      return out;
    }
};