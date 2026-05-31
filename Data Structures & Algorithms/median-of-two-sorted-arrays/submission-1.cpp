class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2) {
            swap(n1, n2);
            swap(nums1, nums2);
        }
        
        int size = n1 + n2;
        int leftSize = (n1 + n2 + 1) / 2;
        int low = 0, hi = n1;

        while(low <= hi) {
            int mid = low + (hi - low) / 2;
            int l1 = (mid == 0) ? INT_MIN : nums1[mid-1];
            int l2 = (leftSize - mid == 0) ? INT_MIN : nums2[leftSize - mid -1];
            int r1 = (mid == n1) ? INT_MAX : nums1[mid];
            int r2 = (leftSize - mid == n2) ? INT_MAX : nums2[leftSize - mid];
            
            if(l1 <= r2 && l2 <= r1) {
                if(size & 1) return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            if(l1 > r2) hi = mid - 1;
            else low = mid + 1;
        }
        
        return -1;
    }
};
