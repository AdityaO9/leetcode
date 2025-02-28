class Solution {
public:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(string sub) {
        int i = 0;
        int j = sub.size() - 1;
        while (i < j) {
            if (sub[i] != sub[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    // Recursive function to explore all palindrome partitions
    void solve(string &s, vector<vector<string>> &ans, vector<string> &path, int i) {
        if (i == s.size()) {  // Base case: Reached the end of the string
            ans.push_back(path);
            return;
        }

        // Try all possible substrings starting at index i
        for (int j = i + 1; j <= s.size(); j++) {
            string sub = s.substr(i, j - i);
            if (isPalindrome(sub)) {  // Check if the substring is a palindrome
                path.push_back(sub);  // Include the substring in the path
                solve(s, ans, path, j);  // Recursively explore the next part of the string
                path.pop_back();  // Backtrack to explore other possibilities
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(s, ans, path, 0);
        return ans;
    }
};