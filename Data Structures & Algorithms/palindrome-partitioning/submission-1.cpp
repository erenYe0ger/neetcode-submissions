class Solution {
    vector<vector<string>> res;
    vector<string> split;
    void solve(string& s, int n, int i) {
        if(i == n) {
            res.push_back(split);
            return;
        }
        for(int j=i; j<n; ++j) {
            if(isP(s, i, j)) {
                split.push_back(s.substr(i, j-i+1));
                solve(s, n, j+1);
                split.pop_back();
            }
        }
    }
    bool isP(string& s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            ++i, --j;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        solve(s, n, 0);
        return res;
    }
};
