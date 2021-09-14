// https://leetcode.com/problems/encode-and-decode-tinyurl

// Note the use of rand() here and count.

class Solution {
public:
    
    unordered_map<string, string> codesToUrls;
    unordered_map<string, int> count;

    string code = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
    string getCode() {
      string codeGenerated="";
      for(int i=0;i<8;i++) {
        codeGenerated.push_back(code[rand()%code.size()]);
      }
      return codeGenerated;
    }
  
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
      string codeGenerated = getCode();
      string shortUrl =  codeGenerated + to_string(count[codeGenerated]);
      codesToUrls[shortUrl] = longUrl;
      count[codeGenerated]++;
      return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
      return codesToUrls[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));