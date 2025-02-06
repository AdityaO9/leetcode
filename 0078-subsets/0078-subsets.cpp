class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result; // To store all subsets
        vector<int> path;           // To store the current subset

        // Define the backtrack function as a lambda
        auto backtrack = [&](int start, auto&& backtrack) -> void {
            // Add the current subset to the result
            result.push_back(path);

            // Explore all possible subsets
            for (int i = start; i < nums.size(); i++) {
                path.push_back(nums[i]);  // Include nums[i] in the subset
                backtrack(i + 1, backtrack); // Move to the next element
                path.pop_back();  // Exclude nums[i] (backtrack)
            }
        };

        // Start the backtracking process
        backtrack(0, backtrack);
        return result;
    }
};