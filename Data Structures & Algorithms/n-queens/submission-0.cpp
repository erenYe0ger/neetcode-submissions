class Solution {
    vector<vector<string>> res;
    vector<string> board;
    void solve(int n, int r, int c) {
        if(r == n) return;
        if(c == n) {
            res.push_back(board);
            return;
        }
        // place
        if(safe(n, r, c)) {
            board[r][c] = 'Q';
            solve(n, 0, c+1);
            board[r][c] = '.';
        }
        // not place
        solve(n, r+1, c);
    }
    bool safe(int n, int r, int c) {
        for(int i=0; i<c; ++i) {
            if(board[r][i] == 'Q') return false;
        }
        for(int i=1; r-i >= 0 && c-i >= 0; ++i) {
            if(board[r-i][c-i] == 'Q') return false;
        }
        for(int i=1; r+i < n && c-i >= 0; ++i) {
            if(board[r+i][c-i] == 'Q') return false;
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        board.assign(n, string (n, '.'));
        solve(n, 0, 0);
        return res;
    }
};
