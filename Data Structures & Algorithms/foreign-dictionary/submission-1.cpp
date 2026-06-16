class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indeg;
        for(auto& word: words) {
            for(auto& c: word) indeg[c] = 0;
        }
        for(int i=1; i<n; ++i) {
            string w1 = words[i-1], w2 = words[i];
            if(w2.size() < w1.size() &&
                 w2 == w1.substr(0,w2.size())) return "";
            for(int j=0; j<w1.size(); ++j) {
                if(w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    ++indeg[w2[j]];
                    break;
                }
            } 
        }
        queue<char> q;
        for(auto& [c, d]: indeg) {
            if(d == 0) q.push(c);
        }
        string res = "";
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            res += u;
            for(auto v: adj[u]) {
                --indeg[v];
                if(indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        if(res.size() != indeg.size()) return "";
        return res;
    }
};
