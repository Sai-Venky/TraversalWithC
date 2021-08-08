// https://leetcode.com/problems/split-two-strings-to-make-palindrome

/*

    Approach is split string while matching start and end parts.
    Then try to check is the remaining parts are a palindrome alone.
    eg :- abcddfg
          asfacba
          here abc matches, then check if dd or fa is palindrome
    O(N), Space O(1)
*/

class Solution {
public:
    bool checkSubstringIsPalindrome(string a, int l, int h) {
      
      while(l<h) {
        if(a[l]!=a[h]) return false;
        l++; h--;
      }
      return true;
    }
  
    bool checkPalindrome(string a, string b) {
      
      int l=0, h=a.size()-1;
      
      while(l<h) {
        if(a[l]!=b[h]) break;
        l++; h--;
      }
      
      return checkSubstringIsPalindrome(a, l, h) || checkSubstringIsPalindrome(b, l, h);
    }
  
    bool checkPalindromeFormation(string a, string b) {
      return checkPalindrome(a, b) || checkPalindrome(b, a);
    }
};