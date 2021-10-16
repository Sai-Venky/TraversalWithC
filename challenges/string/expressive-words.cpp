// https://leetcode.com/problems/expressive-words

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
      int ct=0;
      for(string word:words) if(check(s, word)) ct++; 
      return ct;
    }
  
  bool check(string s, string word) {
    int m=s.length(), n=word.length();
    int i=0, j=0;
    while(i<m && j<n) {
      int x=1, y=1;
      while(i+1<m && s[i] == s[i+1]) i++, x++;
      while(j+1<n && word[j] == word[j+1]) j++, y++;
      
      if(s[i]==word[j] && ( (x>=3 && x>y) || x==y)) i++, j++;
      else return false;
      
    }
    
    return i==m && j==n;
  }
};