class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        auto find = [&](int i, int x) {
            int j = n-1;
            while(i < j) {
                if(x == nums[i] + nums[j]) {
                    res.push_back({-x, nums[i], nums[j]});
                    ++i, --j;
                    while(i<n && nums[i] == nums[i-1]) ++i;
                    while(j>=0 && nums[j] == nums[j+1]) --j;
                }
                else if (x > nums[i] + nums[j]) {
                    ++i;
                    while(i<n && nums[i] == nums[i-1]) ++i;
                }
                else {
                    --j;
                    while(j>=0 && nums[j] == nums[j+1]) --j;
                }
            }
        };
        for(int i=0; i<n; ++i) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            int a = nums[i];
            find(i+1, -a);
        }
        return res;
    }
};
