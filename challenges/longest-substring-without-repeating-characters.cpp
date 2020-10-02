#include<iostream>
#include <assert.h> 
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        
        int length = str.length();
        int **dp = (int **)malloc(length * sizeof(int *)); 
        for (int i=0; i<length; i++) 
            dp[i] = (int *)malloc(length * sizeof(int)); 
        
        for(int i=0; i<length; i++) {
                dp[i][i] = 1;            
        }
 
        int counter = 1;
        while(counter < length) {
            for(int i=0; i<length-1; i++) {
                if(i+counter < length) {
                    dp[i][i+counter] =   (dp[i][i+counter - 1] && dp[i+1][i+counter])  && (str[i] != str[i+counter]);    
                }
                
            }
            
            counter++;
        }
        int max = 0;
        for(int i=0; i<length; i++) {
            for(int j = 0; j<length; j++) {
                if(dp[i][j] == 1 && j-i+1>max) {
                    max = j-i + 1;
                }
            }
        }
        return max;
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
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}