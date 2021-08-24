// https://leetcode.com/problems/guess-the-word/

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

// https://leetcode.com/problems/guess-the-word/discuss/1179249/C++-Solution-or-with-intuition-and-some-optimization

/*

1. For choosing the candidate word, iterate all words and calculate a score which indicates the best word to choose.
The best word to choose is the one which has most common characters with other words. 
Reason is because the higher the common more chance of it overlapping.
2. In the next guess, limit the number of words going in the selection based on the matches.
*/

class Solution {
public:
    string fetchWord(vector<string>& wordlist) {
      string word=wordlist[0];
      int n=wordlist.size();
      int dp[6][26];
      memset(dp, 0, sizeof dp);
      for(int i=0;i<wordlist.size();i++) {
        for(int j=0;j<6;j++) {
          dp[j][(wordlist[i][j]-'a')]++;
        }
      }
      int best=0;
      for(int i=0;i<wordlist.size();i++) {
        int score=0;
        for(int j=0;j<6;j++) {
          score+=dp[j][(wordlist[i][j]-'a')];
        }
        if(score>best) {
          best=score;
          word=wordlist[i];
        }
      }
      
      return word;
    }
  
    void findSecretWord(vector<string>& wordlist, Master& master) {
            
      for(int i=0;i<10;i++) {
        vector<string> candidates; 
        string guess=fetchWord(wordlist);
        int matchno = master.guess(guess);
        if(matchno==6)  return;
        for(string w:wordlist) {
          if(match(w, guess) == matchno) {
            candidates.push_back(w);
          }
        }
        wordlist=candidates;
      }
    }
  
    int match(string a, string b) {
      int ct=0;
      for(int i=0;i<6;i++) {
        if(a[i]==b[i]) ct++;
      }
      return ct;
    }
};