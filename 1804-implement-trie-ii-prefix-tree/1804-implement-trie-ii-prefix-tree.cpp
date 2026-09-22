class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        int wordsEndingHere;
        int wordsStartingHere;

        TrieNode() {
            for(int i = 0; i < 26; i++)
                this->children[i] = nullptr;
            this->wordsEndingHere = 0;
            this->wordsStartingHere = 0;
        }
    };

public:

    TrieNode* root;

    Trie() {
        this->root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = this->root;
        for(char c : word){
            int i = c - 'a';
            if(!curr->children[i])
                curr->children[i] = new TrieNode();
            curr = curr->children[i];
            curr->wordsStartingHere += 1;
        }
        curr->wordsEndingHere += 1;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* curr = this->root;
        for(char c : word){
            int i = c - 'a';
            if(!curr->children[i])
                return 0;
            curr = curr->children[i];
        }
        return curr->wordsEndingHere;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* curr = this->root;
        for(char c : prefix){
            int i = c - 'a';
            if(!curr->children[i])
                return 0;
            curr = curr->children[i];
        }
        return curr->wordsStartingHere;
    }
    
    void erase(string word) {
        TrieNode* curr = this->root;
        for(char c : word){
            int i = c - 'a';
            curr = curr->children[i];
            curr->wordsStartingHere -= 1;
        }
        curr->wordsEndingHere -= 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */