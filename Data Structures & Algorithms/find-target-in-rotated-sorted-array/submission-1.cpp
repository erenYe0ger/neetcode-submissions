class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, hi = nums.size() - 1;
        while(low <= hi) {
            int mid = low + (hi - low) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[low] && 
                nums[mid] >= nums[hi]) {
                if(target > nums[mid]) low = mid + 1;
                else if(target >= nums[low]) hi = mid - 1;
                else low = mid + 1;
            }
            else {
                if(target < nums[mid]) hi = mid - 1;
                else if(target <= nums[hi]) low = mid + 1;
                else hi = mid - 1;
            }
        }
        return -1;
    }
};
