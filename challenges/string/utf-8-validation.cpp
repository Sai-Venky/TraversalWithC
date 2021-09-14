// https://leetcode.com/problems/utf-8-validation

// Note the ob part and count==0 check for single numbers 
/*
  Just a summary:
  0b: binary number
  0: octonary number
  0x: hexadecimal number
*/

class Solution {
public:
    bool validUtf8(vector<int>& data) {
      int count=0;
      for(int v:data) {
        if(count==0) {
            if((v>>5) == 0b110) count=1;
            else if((v>>4) == 0b1110) count=2;
            else if((v>>3) == 0b11110) count=3;
            else if((v>>7) != 0b0) return false;
        } else {
          if((v>>6)!=0b10) return false;
          count--;
        }
      }
      
      return count==0;
    }
};