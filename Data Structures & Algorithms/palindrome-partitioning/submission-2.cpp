class Solution {
    vector<vector<string>> res;
    vector<string> split;
    vector<vector<bool>> isP;
    void solve(string& s, int n, int i) {
        if(i == n) {
            res.push_back(split);
            return;
        }
        for(int j=i; j<n; ++j) {
            if(isP[i][j]) {
                split.push_back(s.substr(i, j-i+1));
                solve(s, n, j+1);
                split.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        isP.assign(n, vector<bool> (n, false));
        for(int i=n-1; i>=0; --i) {
            for(int j=i; j<n; ++j) {
                isP[i][j] = (s[i] == s[j]) && 
                            (i+1 >= j-1 || isP[i+1][j-1]);
            }
        }
        solve(s, n, 0);
        return res;
    }
};
