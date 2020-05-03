#include<iostream>
#include<string>
using namespace std;
# define alphabet_size 26
#define M 3 
#define N 3 

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

bool checkIfPartOfWord(trie * root, char boggle[M][N], char words[][100], string curWord) {
    for (int i =0; i<itra; i++) {
        root = insert(root, words[i]);
    }
}

void boggleCheck(trie * root, char boggle[M][N], char words[][100], string curWord) {

    bool present = false;
    for(int i =0;i<M; i++) {
        for(int j =0; j<N; j++) {
            present = checkIfPartOfWord(root, boggle, words, strcat(curWord, boggle[i][j]));
            present= checkIfPartOfWord(root, boggle, words, curWord);
            boggleCheck(root, boggle, words, )
        }
    }
    
}

int main() {
    char words [][100] = {
        "GEEKS",
        "FOR",
        "QUIZ",
        "GO"
    };

    char boggle[M][N] = {{'G','I','Z'}, 
        {'U','E','K'}, 
        {'Q','S','E'} 
    }; 

    trie * root= getNode();

    for (int i =0; i<4; i++) {
        root = insert(root, words[i]);
    }

    boggleCheck(root, boggle, words , NULL , 0);
    return 0;
}