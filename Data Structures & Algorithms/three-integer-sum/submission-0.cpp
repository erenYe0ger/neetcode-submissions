class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> res;
        auto find = [&](int i, int x) {
            int j = n-1;
            while(i < j) {
                if(x == nums[i] + nums[j]) {
                    res.insert({-x, nums[i], nums[j]});
                    ++i, --j;
                }
                else if (x > nums[i] + nums[j]) ++i;
                else --j;
            }
        };
        for(int i=0; i<n; ++i) {
            int a = nums[i];
            find(i+1, -a);
        }
        return vector<vector<int>> (res.begin(), res.end());
    }
};
