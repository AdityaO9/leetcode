class Solution {
public:
    void solve(vector<int>& cand, vector<int>& current,
               vector<vector<int>>& res, int sum, int target, int idx) {
        if (sum > target)
            return;
        if (sum == target) {
            res.push_back(current);
            return;
        }//
        for (int i = idx; i < cand.size(); i++) {
            if (i > idx && cand[i] == cand[i - 1])
                continue;
            current.push_back(cand[i]);
            solve(cand, current, res, sum + cand[i], target, i + 1);
            current.pop_back();
        }
    }//fun
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        vector<vector<int>> res;
        vector<int> current;
        sort(cand.begin(), cand.end());
        solve(cand, current, res, 0, target, 0);
        return res;
    }
};