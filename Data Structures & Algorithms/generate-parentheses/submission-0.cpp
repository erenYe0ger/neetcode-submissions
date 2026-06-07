class Solution {
    vector<string> res;
    string str;
    void solve(int open, int close, int n) {
        if(open == n && close == n) {
            res.push_back(str);
            return;
        }
        if(open < n) {
            str += '(';
            solve(open+1, close, n);
            str.pop_back();
        }
        if(close < open) {
            str += ')';
            solve(open, close+1, n);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        solve(0,0,n);
        return res;
    }
};
