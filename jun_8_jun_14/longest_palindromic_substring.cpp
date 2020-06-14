// https://leetcode.com/problems/longest-palindromic-substring
// Longest Palindromic Substring

#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string str) {
        
        int length = str.length();
        string str1 = "";
        int dp[length+1][length+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i<length; i++) {
            dp[i][i] = 1;
        }
        
        for (int i =0; i<length-1; i++) {
          if(str[i] == str[i+1]) {
            dp[i][i+1] = 1;
          } else {
            dp[i][i+1] = 0;   
          }
        }
        for(int i =length-1; i>=0; i--) {
            for (int j=i+2; j<length; j++){
                bool charEqual = (str[i] == str[j]);
                bool subsEqual = dp[i+1][j-1];
                dp[i][j] = charEqual && subsEqual;
            }
        }
        int max = 0; 
        for(int i =0; i<length; i++) {
            for (int j=i; j<length; j++){
                if(dp[i][j] == 1 && (j-i+1 > max)) {
                    max = j-i;
                    str1 = str.substr(i,max+1); 
                }
            }
        }
        return str1;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line = "palinilop";
    string s = stringToString(line);
    
    string ret = Solution().longestPalindrome(s);

    string out = (ret);
    cout << out << endl;
    return 0;
}