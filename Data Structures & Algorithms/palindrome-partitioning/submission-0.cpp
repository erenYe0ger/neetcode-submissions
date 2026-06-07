class Solution {
    vector<vector<string>> res;
    vector<string> v;
    string s;
    void solve(int i) {
        if(i == s.size()) {
            if(isP(v)) res.push_back(v);
            return; 
        }
        if(v.size()) {
            v.back() += s[i];
            solve(i+1);
            v.back().pop_back();
        }
        v.push_back(string (1, s[i]));
        solve(i+1);
        v.pop_back();
    }
    bool isP(vector<string>& v) {
        for(auto& s: v) {
            int n = s.size();
            for(int i=0; i<n/2; ++i) {
                if(s[i] != s[n-1-i]) return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        this->s = s;
        solve(0);
        return res;
    }
};
