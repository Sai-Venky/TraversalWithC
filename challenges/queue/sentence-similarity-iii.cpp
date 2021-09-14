// https://leetcode.com/problems/sentence-similarity-iii/

// note the use of deque here for the processing

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {     
      deque<string> d1, d2;
      string word="";
      s1.push_back(' '); s2.push_back(' ');
      for(int i=0;i<s1.length();i++) {
        if(s1[i] == ' ') {
          d1.push_back(word);
          word="";
        }
        else word.push_back(s1[i]);
      }
      for(int i=0;i<s2.length();i++) {
        if(s2[i] == ' ') {
          d2.push_back(word);
          word="";
        }
        else word.push_back(s2[i]);
      }
      
      while(d1.size()>0 && d2.size()>0 && (d1.front() == d2.front())) {
        d1.pop_front(); d2.pop_front();
      }
      while(d1.size()>0 && d2.size()>0 && (d1.back() == d2.back())) {
        d1.pop_back(); d2.pop_back();
      }
      
      return d1.size()==0 || d2.size()==0;
    }
};