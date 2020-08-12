// https://leetcode.com/problems/word-break

class Solution {
public:
    
    bool segmented = false;
    struct trie {
        char value;
        bool isEndOfWord;
        trie *chars[26];
    };
    
    trie * newTrie(char c) {
        trie * root = new trie;
        root->value = c;
        root->isEndOfWord = false;
        for(int i=0; i<26; i++){
          root->chars[i] = NULL;  
        }
        return root;
    }
    
    void traverse(string s, trie * root, int i, vector<int>& dp) {
        trie * trav = root;
        if(i==s.length())  {
            segmented = true;
            return;
        }
        int start = i;
        if(dp[i] == 0) {
            return;
        }        
        while(i<s.length()) {
            trav = trav->chars[s[i] - 'a'];
            if(trav == NULL) {
                dp[start] = 0;
                return;
            };
            if(trav->isEndOfWord == true) {
                traverse(s, root, i+1, dp);
            }

            i++;
        }
        
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length(), 1);

        trie * root = new trie;
        root->isEndOfWord = false;
        for(int i=0; i<26; i++){
          root->chars[i] = NULL;  
        }
        for(auto word : wordDict){
            trie * temp=root;
            for(int i=0; i<word.length(); i++) {
                if(temp->chars[word[i] - 'a'] == NULL)
                    temp->chars[word[i] - 'a'] = newTrie(word[i]);
                temp = temp->chars[word[i] - 'a'];
            } 
            temp->isEndOfWord = true;
        }
        
        
        traverse(s, root, 0, dp);
        
        return segmented;
        
    }
};