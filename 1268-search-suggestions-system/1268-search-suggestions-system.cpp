class Trie {
private:

    struct TrieNode{
        TrieNode* children[26];
        bool endOfWord;
        TrieNode(){
            for(int i = 0; i < 26; i++)
                this->children[i] = nullptr;
            this->endOfWord = false;
        }
    };

    void dfsWithPrefix(TrieNode* curr, string& word, vector<string>& result){
        if(result.size() == 3)
            return;
        if(curr->endOfWord)
            result.push_back(word);

        // run DFS on all possible paths
        for(char c = 'a'; c <= 'z'; c++){
            int i = c - 'a';
            if(curr->children[i]){
                word += c;
                dfsWithPrefix(curr->children[i], word, result);
                word.pop_back();
            }
        }
    }
public:
    TrieNode* root;

    Trie(){
        this->root = new TrieNode();
    }

    void insert(string word){
        TrieNode* curr = this->root;
        for(char c : word){
            int i = c - 'a';
            if(curr->children[i] == nullptr)
                curr->children[i] = new TrieNode();
            curr = curr->children[i];
        }
        curr->endOfWord = true;
    }

    vector<string> getWordsStartingWith(string prefix){
        TrieNode* curr = this->root;
        for(char c : prefix){
            int i = c - 'a';
            if(curr->children[i] == nullptr)
                return {};
            curr = curr->children[i];
        }
        vector<string> result;
        dfsWithPrefix(curr, prefix, result);
        return result;
    }

};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie t = Trie();
        vector<vector<string>> result;
        for(string product : products)
            t.insert(product);

        string prefix;
        for(char c : searchWord){
            prefix += c;
            result.push_back(t.getWordsStartingWith(prefix));
        }

        return result;
        
    }
};