// https://leetcode.com/problems/integer-replacement

class Solution {
public:
    unordered_map<int, int> m;
    int integerReplacement(int n) {
      if (n == 1) return 0;
      else if(m.find(n)!=m.end()) return m[n];
      if (n % 2 == 0) 
          return m[n]=(1 + integerReplacement(n / 2));
      else 
          return m[n]=(2 + min(integerReplacement(n/2), integerReplacement(n/2 + 1)));
    }

};
