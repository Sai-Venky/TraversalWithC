// https://leetcode.com/problems/add-and-search-word-data-structure-design

class WordDictionary {
public:
    struct trie {
        trie *children[26];
        bool isEndOfWord;     
    };
    trie *root;
    WordDictionary() {
        root = (trie *)malloc(sizeof(trie));
        for(int i=0; i<26; i++) {
            root->children[i] = NULL;
        }
        root->isEndOfWord= false;
    }
    
    trie * getNode() {
        trie * node = (trie *)malloc(sizeof(trie));
        for(int i=0; i<26; i++) {
            node->children[i] = NULL;
        }
        node->isEndOfWord= false;
        return node;       
    }
    
    void addWord(string word) {
       trie * crawl = root;
        for(int key=0 ; key<word.length(); key++) {
            int keyWord = word[key] - 'a';
            if(!crawl->children[keyWord]) {
                crawl->children[keyWord] = getNode();
            }
            crawl = crawl->children[keyWord];
        }
        crawl->isEndOfWord = true;
    }
    
    bool recursiveSearch(string word, trie * root, int pos) {
        bool found = false;
        if(pos == word.length()) {
            if(!root->isEndOfWord) return false;
            return true;
        }
        
        if(word[pos]!='.') {
            int keyWord = word[pos] - 'a';
            if(root->children[keyWord]) {
                found = recursiveSearch(word, root->children[keyWord], pos+1);
            } else {
                found = false;
            }                  
        } else {
            for(int i=0; i<26; i++) {
                if(root->children[i]) {
                    found = recursiveSearch(word, root->children[i], pos+1);                 
                }
                if(found) break;
            }
        }
         
        return found;
    }
    
    bool search(string word) {
     auto found = recursiveSearch(word, root, 0);
        return found;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */