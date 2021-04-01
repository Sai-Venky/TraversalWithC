// https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
      unordered_map<char, int> umap;
      int count = 0;
      bool add = false;
      for(int i=0;i<s.length();i++) {
        umap[s[i]] ++;
      }
      
      for(char c = 'a'; c<='z'; c++) {
        if(umap[c] -1 >=0) {
          if(umap[c]%2 ==0) {
            count += umap[c];
          } else if((umap[c]-1)%2 ==0) {
            count += umap[c]-1;
            add = true;
          }
        }
      }
      for(char c = 'A'; c<='Z'; c++) {
        if(umap[c] -1 >=0) {
          if(umap[c]%2 ==0) {
            count += umap[c];
          } else if((umap[c]-1)%2 ==0) {
            count += umap[c]-1;
            add = true;
          }
        }
      }
      return add? count+1: count;
    }
};