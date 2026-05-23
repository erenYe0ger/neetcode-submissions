class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n,0), suf(n,0);
        for(int i=1; i<n; ++i) pre[i] = max(pre[i-1], height[i-1]);
        for(int i=n-2; i>=0; --i) suf[i] = max(suf[i+1], height[i+1]);
        int res = 0;
        for(int i=1; i<n-1; ++i) {
            int x = min(pre[i], suf[i]);
            if(x > height[i]) res += x-height[i];
        }
        return res;
    }
};
