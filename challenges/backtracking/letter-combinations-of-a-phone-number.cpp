// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

/*
    class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            if (digits.empty()) {
                return vector<string>();
            }
            vector<string> words{ " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
            deque<string> q;
            q.push_back("");

            for (char digit : digits) {
                int d = digit - '0';
                for (int i = q.size(); i > 0; i--) {
                    string token = q.front();
                    q.pop_front();
                    for (char ch : words[d]) {
                        q.push_back(token + ch);
                    }
                }
            }

            return vector<string>(q.begin(), q.end());
        }
    };
*/
class Solution {
public:
    unordered_map<char, string> m;
    vector<string> letterCombinations(string digits) {
      vector<string> out;
      if(digits.size()==0) return out;
      string comb="";
      m['2'] = "abc";
      m['3'] = "def";
      m['4'] = "ghi";
      m['5'] = "jkl";
      m['6'] = "mno";
      m['7'] = "pqrs";
      m['8'] = "tuv";
      m['9'] = "wxyz";
      findCombinations(digits, out, 0, comb);
      return out;
    }
  
    void findCombinations(string &digits, vector<string>& out, int s, string &comb) {
      
      if(s==digits.size()) {
        out.push_back(comb);
        return;
      }
      
      for(int i=0;i<m[digits[s]].length();i++) {
        comb.push_back(m[digits[s]][i]);
        findCombinations(digits, out, s+1, comb);
        comb.pop_back();
      }
      
    }
};