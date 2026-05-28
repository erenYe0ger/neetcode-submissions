class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, hi = m-1;
        while(low <= hi) {
            int mid = (low + hi) >> 1;
            if(matrix[mid][0] <= target) low = mid + 1;
            else hi = mid - 1;
        }
        int row = hi;
        if(row < 0) return false;
        low = 0, hi = n-1;
        while(low <= hi) {
            int mid = (low + hi) >> 1;
            if(target == matrix[row][mid]) return true;
            if(matrix[row][mid] > target) hi = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};
