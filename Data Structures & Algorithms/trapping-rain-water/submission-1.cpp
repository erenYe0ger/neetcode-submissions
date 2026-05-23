class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i = 1, j = n-2;
        int lMax = height[0], rMax = height[n-1];
        int res = 0;
        while(i <= j) {
            if(lMax < rMax) {
                if(height[i] < lMax) res += lMax - height[i];
                lMax = max(lMax, height[i]);
                ++i;
            } else {
                if(height[j] < rMax)res += rMax - height[j];
                rMax = max(rMax, height[j]);
                --j;
            }
        }
        return res;
    }
};
