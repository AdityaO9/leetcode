class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // Rearrange the array so that each number x is at index x-1
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // Identify the first missing positive number
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        // If all numbers are in place, the missing number is n+1
        return n + 1;
    }
};