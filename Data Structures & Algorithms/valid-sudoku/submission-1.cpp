class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; ++i) {
            unordered_set<char> st;
            for(int j=0; j<9; ++j) {
                if(board[i][j] == '.') continue;
                if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }
        for(int j=0; j<9; ++j) {
            unordered_set<char> st;
            for(int i=0; i<9; ++i) {
                if(board[i][j] == '.') continue;
                if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }

        auto check = [&](int x) {
            int r = 3 * (x/3), c = 3 * (x % 3);
            unordered_set<char> st;
            for(int i=r; i<r+3; ++i) {
                for(int j=c; j<c+3; ++j) {
                    if(board[i][j] == '.') continue;
                    if(st.count(board[i][j])) return false;
                    st.insert(board[i][j]);
                }
            }
            return true;
        };

        for(int x=0; x<9; ++x) {
            if(check(x) == false) return false;
        }
        return true;
    }
};
