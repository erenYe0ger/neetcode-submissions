class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        if(sum & 1) return false;
        vector<int> nxt(sum/2+1, false);
        nxt[0] = true;
        for(int i=n-1; i>=0; --i) {
            vector<int> cur(sum/2+1, false);
            cur[0] = true;
            for(int target=1; target<=sum/2; ++target) {
                cur[target] = nxt[target];
                if(target >= nums[i]) cur[target] |= nxt[target-nums[i]];
            }
            nxt = cur;
        }
        return nxt[sum/2];
    }
};
