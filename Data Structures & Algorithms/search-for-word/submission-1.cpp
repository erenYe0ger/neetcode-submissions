class Solution {
    vector<vector<bool>> vis;
    int m, n;
    vector<vector<char>> board; string word;
    int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
    bool solve(int i, int j, int k) {
        if(k == word.size()-1) return board[i][j] == word[k];
        vis[i][j] = true;
        bool res = false;
        for(int t=0; t<4; ++t) {
            int x = i+dx[t], y = j+dy[t];
            if(x >= m || x < 0 || y >= n || y < 0) continue;
            if(vis[x][y]) continue;
            if(board[i][j] == word[k]) res |= solve(x,y,k+1);
        }
        vis[i][j] = false;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        vis = vector<vector<bool>> (m, vector<bool> (n, false));
        this->board = board; this->word = word;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(solve(i,j,0)) return true;
            }
        } 
        return false;
    }
};
