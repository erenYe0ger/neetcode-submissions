class TrieNode {
public:
    bool endsHere = false;
    TrieNode* children[26] = {nullptr};
};


class PrefixTree {
    TrieNode* dummy = new TrieNode();
public:
    PrefixTree() {}
    
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
