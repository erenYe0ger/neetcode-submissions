class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, hi = n-1;
        while (low <= hi) {
            int mid = (low + hi) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) hi = mid-1;
            else low = mid+1;
        }
        return -1;
    }
};
