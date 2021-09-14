// https://leetcode.com/problems/stream-of-characters

class trie {

  public:
    trie() {
      this->isLeaf=false;
      for(int i=0;i<26;i++) {
        this->child[i]=NULL;
      }
    }
  
    void insertWord(string word) {
      trie* root=this;

      for(int i=word.length()-1;i>=0;i--) {

        char c=word[i]-'a';
        if(!root->child[c]) root->child[c] = new trie();
        root=root->child[c];
      }
      root->isLeaf=true;
    }
  trie* child[26];
  bool isLeaf;
};

class StreamChecker {
public:
    list<char> l;
    int size=0;
    trie* root;
    StreamChecker(vector<string>& words) {
      root=new trie();
      for(string word:words) {
        root->insertWord(word);
        if(word.length()>size) size=word.length();
      }
    }
    
    bool query(char letter) {
      l.push_front(letter);
      trie* trav=root;
      if(l.size()>size) l.pop_back();
      
      for(auto c:l) {
        if(trav->isLeaf==true) return true;
        if(trav->child[c-'a'] == NULL) return false;
        trav=trav->child[c-'a'];
      }
      
      return trav->isLeaf;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */