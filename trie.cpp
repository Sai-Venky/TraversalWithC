#include<iostream>
#include<string>
using namespace std;
# define alphabet_size 26

struct trie {
    trie *children[alphabet_size];
    bool isEndOfWord;
};

trie * getNode() {
    trie * node = (trie *)malloc(sizeof(trie));
    for(int i=0; i<alphabet_size; i++) {
        node->children[i] = NULL;
    }
    node->isEndOfWord= false;
    return node;
}

trie * insert (trie * root, string word) {
    trie * crawl = root;
    for(int key =0 ; key<word.length(); key++) {
        int keyWord = word[key] - 'a';
        if(!crawl->children[keyWord]) {
            crawl->children[keyWord] = getNode();
        }
        crawl = crawl->children[keyWord];
    }
    crawl->isEndOfWord = true;
    return root;
}

bool search (trie * root, string word) {
    trie * crawl = root;
    bool found = true;
    for(int key =0 ; key<word.length(); key++) {
        int keyWord = word[key] - 'a';
        if(crawl->children[keyWord]) {
            crawl = crawl->children[keyWord];
        } else {
            found = false;
            break;
        }
    }

    if(found && (crawl->isEndOfWord == true)) {
        found = true;
    }
    return found;

}

bool isFreeNode(trie * root) {
    for (int i=0; i<alphabet_size; i++) {
        if(root->children[i] != NULL) {
            return false;
        }
    }
    return true;
}

trie * deleteWord (trie * root, string word, int depth) {
    trie * crawl = root;

    if (!root) {
        return NULL;
    }
    if(depth ==word.length()) {
        if(crawl->isEndOfWord) {
            crawl->isEndOfWord = false;
        }
        if(isFreeNode(crawl)) {
            free(crawl);
            return NULL;
        }
    }


    int keyWord = word[depth] - 'a';

    crawl->children[keyWord] = deleteWord(crawl->children[keyWord], word, depth +1);
    if(isFreeNode(crawl) && !crawl->isEndOfWord) {
        free(crawl);
        root =  NULL;
    }

    return root;
}


int main() {
    char words [][100] = {
        "hello",
        "world",
        "i",
        "am",
        "siraj"
    };

    trie * root= getNode();

    for (int i =0; i<5; i++) {
        root = insert(root, words[i]);
    }

    cout<<search(root, "siraj")<<"\n";
    cout<<search(root, "venky")<<"\n";
    root = deleteWord(root, "siraj", 0);
    cout<<search(root, "siraj")<<"\n";
    return 0;
}