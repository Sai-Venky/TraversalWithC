// https://leetcode.com/problems/repeated-dna-sequences/

// https://leetcode.com/problems/repeated-dna-sequences/discuss/53877/I-did-it-in-10-lines-of-C%2B%2B

// Note the use of 2 bits and 0x3FFFFFFF or 0b111111111111111111111111111111
// https://leetcode.com/problems/repeated-dna-sequences/discuss/53952/20-ms-solution-(C%2B%2B)-with-explanation
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> m;
    vector<string> r;
    long t = 0, i = 0, ss = s.size();
    while (i < 9)
        t = t << 3 | s[i++] & 7;
    while (i < ss)
        if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
            r.push_back(s.substr(i - 10, 10));
    return r;
}

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
      vector<string> out;
      deque<char> d;
      unordered_map<string, int> m;
      
      for(int i=0;i<s.length();i++) {
        d.push_back(s[i]);
        if(d.size()==10) {
          string s = {d.begin(), d.end()};
          if(m[s]++==1) out.push_back(s);
          d.pop_front();
        }
      }
      
      return out;
    }
};