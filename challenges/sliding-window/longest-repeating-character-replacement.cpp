// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
      int j=0, ct=0, mostFreqLetter=0;
      vector<int> freq(26,0);
      for(int i=0;i<s.length();i++) {
        freq[s[i]-'A']++;
        mostFreqLetter = max(mostFreqLetter, freq[s[i]-'A']);
        
        int lettersToChange = (i - j + 1) - mostFreqLetter;
        if(lettersToChange > k){
          freq[s[j] - 'A']--;
          j++;
        }
        ct = max(ct, i-j+1);
      }
      return ct;
    }
};