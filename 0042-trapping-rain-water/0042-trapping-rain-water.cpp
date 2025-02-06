class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n, 0), post(n, 0);
        int ans = 0;
        pre[0] = height[0];
        post[n-1] = height[n-1];
        for (int i = 1; i < n; i++) {
            pre[i] = max(height[i], pre[i-1]);
            post[n-1-i] = max(height[n-i-1], post[n-i]);
        }
        for (int i = 1; i < n-1; i++) {
            if (min(pre[i-1], post[i+1]) > height[i]) {
                ans += min(pre[i-1], post[i+1]) - height[i];
            }
        }
        return ans;
    }
};