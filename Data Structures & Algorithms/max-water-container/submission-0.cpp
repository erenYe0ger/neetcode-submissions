class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        for(int i=0; i<n; ++i) {
            int sum = 0;
            for(int j=i+1; j<n; ++j) {
                sum = (j-i) * min(heights[i], heights[j]);
                res = max(res, sum);
            }
        }   
        return res;
    }
};
