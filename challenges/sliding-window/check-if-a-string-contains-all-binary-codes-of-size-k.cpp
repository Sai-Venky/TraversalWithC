// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

/*
    https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/discuss/1106013/Short-Fast-and-Easy-w-explanation-or-Multiple-Approaches-or-beats-100
    
    bool hasAllCodes(string s, int k) {
        int n = s.size(), size = 1 << k, count = 0, hash = 0, allOnes = ~size; 
        bool set[size]; memset(set, false, sizeof(set));
        for(int i = 0; i < n; i++){                    	    
            // below line combines all above-metioned steps for rolling hash calculation
            hash = ((hash << 1) & allOnes) | (s[i] - '0');            
            if(i >= k - 1 && !set[hash])   // first k - 1 iteration are to calculate hash of first substring of length k
                set[hash] = true, count++;
        }
        return count == size;
    }
*/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
      unordered_set<string> col;
      deque<char> code;
      
      for(int i=0; i<s.length();i++) {
        code.push_back(s[i]);        
        
        if(code.size()==k) {
          col.insert({ code.begin(), code.end() });
          code.pop_front(); 
        }
        
      }
      // Use pow for power not ^ which is xor or bit rep of power like 1<<k
      return col.size() == 1 << k;
    }
};