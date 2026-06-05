class Solution {
    typedef pair<int,int> P;
    int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
    int m, n;
    // void dfs(vector<vector<char>>& grid, int i, int j) {
    //     grid[i][j] = '0';
    //     for(int t=0; t<4; ++t) {
    //         int x = i+dx[t], y = j+dy[t];
    //         if(x >= m || x < 0 ||
    //             y >= n || y < 0 || 
    //             grid[x][y] == '0') continue;
    //         dfs(grid, x, y);
    //     }
    // }
    // void bfs(vector<vector<char>>& grid, int i, int j) {
    //     queue<P> q;
    //     q.push(make_pair(i, j));
    //     grid[i][j] = '0';
    //     while(!q.empty()) {
    //         auto [r,c] = q.front(); q.pop();
    //         for(int t=0; t<4; ++t) {
    //             int x = r+dx[t], y = c+dy[t];
    //             if(x >= m || x < 0 ||
    //                 y >= n || y < 0 || 
    //                 grid[x][y] == '0') continue;
    //             grid[x][y] = '0';
    //             q.push(make_pair(x, y));
    //         }
    //     }
    // }
    class DSU {
        vector<int> size, par;
    public:
        int components;
        DSU(int n) {
            components = 0;
            size.assign(n,1);
            par.resize(n);
            for(int i=0; i<n; ++i) par[i] = i;
        }
        int find(int i) {
            if(par[i] == i) return i;
            return par[i] = find(par[i]);
        }
        void unite(int u, int v) {
            u = find(u), v = find(v);
            if(u == v) return;
            if(size[u] < size[v]) swap(u,v);
            size[u] += size[v];
            par[v] = u;
            --components;
        }
    };
public:
    int numIslands(vector<vector<char>>& grid) {
        // int cnt = 0;
        m = grid.size(), n = grid[0].size();
        // for(int i=0; i<m; ++i) {
        //     for(int j=0; j<n; ++j) {
        //         if(grid[i][j] == '1') {
        //             ++cnt;
        //             // dfs(grid, i, j);
        //             bfs(grid, i, j);
        //         }
        //     }
        // }
        DSU dsu(m*n);
        auto index = [&](int i, int j) {
            return i*n + j;
        };
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == '1') {
                    ++dsu.components;
                    for(int t=0; t<4; ++t) {
                        int x = i+dx[t], y = j+dy[t];
                        if(x >= m || x < 0 ||
                            y >= n || y < 0 ||
                            grid[x][y] == '0') continue;
                        dsu.unite(index(i,j), index(x,y));
                    }
                }
            }
        }
        return dsu.components;
    }
};
