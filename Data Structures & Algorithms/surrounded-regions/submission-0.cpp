class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis (m , vector<bool> (n, false));
        typedef pair<int,int> P;
        queue<P> q;
        for(int i=0; i<m; ++i) {
            if(board[i][0] == 'O') q.push(make_pair(i,0));
            if(board[i][n-1] == 'O') q.push(make_pair(i,n-1));
        }
        for(int j=0; j<n; ++j) {
            if(board[0][j] == 'O') q.push(make_pair(0,j));
            if(board[m-1][j] == 'O') q.push(make_pair(m-1,j));
        }
        while(!q.empty()) {
            auto [i,j] = q.front(); q.pop();
            vis[i][j] = true;
            for(int t=0; t<4; ++t) {
                int x = i+dx[t], y = j+dy[t];
                if(x >= m || x < 0 ||
                    y >= n || y < 0 ||
                    board[x][y] == 'X' ||
                    vis[x][y]) continue;
                vis[x][y] = true;
                q.push(make_pair(x,y));
            }
        }
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(!vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};
