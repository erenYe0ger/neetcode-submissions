class TrieNode {
public:
    bool endsHere = false;
    TrieNode* children[26] = {nullptr};
    ~TrieNode() {
        for(int i=0; i<26; ++i) delete children[i];
    }
};

class WordDictionary {
    TrieNode* dummy = new TrieNode();
    bool solve(string& word, int i, int n, TrieNode* cur) {
        if(i == n) return cur->endsHere;
        char ch = word[i];
        if(ch == '.') {
            for(int child=0; child<26; ++child) {
                if(cur->children[child] &&
                    solve(word, i+1, n, cur->children[child])) return true;
            }
            return false;
        } 
        else {
            if(!cur->children[ch-'a']) return false;
            return solve(word, i+1, n, cur->children[ch-'a']);
        }
    } 
public:
    ~WordDictionary() {
        delete dummy;
    }

    void addWord(string word) {
        TrieNode* cur = dummy;
        for(auto& ch: word) {
            if(!cur->children[ch-'a']) cur->children[ch-'a'] = new TrieNode();
            cur = cur->children[ch-'a'];
        }
        cur->endsHere = true;
    }
    
    bool search(string word) {
        int n = word.size();
        TrieNode* cur = dummy;
        return solve(word, 0, n, cur);
    }
};