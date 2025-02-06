class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res(2, -1);
        int low = 0, high = n - 1;

        // Finding the first occurrence
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target) res[0] = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        low = 0, high = n - 1;

        // Finding the last occurrence
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] <= target) {
                if (nums[mid] == target) res[1] = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }
};