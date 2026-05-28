class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, hi = m*n - 1;
        while(low <= hi) {
            int mid = low + ((hi - low) >> 1);
            int r = mid / n, c = mid % n;
            int x = matrix[r][c];
            if(x == target) return true;
            if(x < target) low = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }
};
