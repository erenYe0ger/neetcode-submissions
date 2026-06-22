class TrieNode {
public:
    bool endsHere = false;
    TrieNode* children[26] = {nullptr};
    ~TrieNode() {
        for(int i=0; i<26; ++i) delete children[i];
    }
};


class PrefixTree {
    TrieNode* dummy = new TrieNode();
public:
    PrefixTree() {}
    
    ~PrefixTree() {
        delete dummy;
    }

    void insert(string word) {
        TrieNode* cur = dummy;
        for(auto& ch: word) {
            if(!cur->children[ch-'a']) cur->children[ch-'a'] = new TrieNode();
            cur = cur->children[ch-'a'];
        }
        cur->endsHere = true;
    }
    
    bool search(string word) {
        TrieNode* cur = dummy;
        for(auto& ch: word) {
            if(!cur->children[ch-'a']) return false;
            cur = cur->children[ch-'a'];
        }
        return cur->endsHere;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = dummy;
        for(auto& ch: prefix) {
            if(!cur->children[ch-'a']) return false;
            cur = cur->children[ch-'a'];
        }
        return true;
    }
};
