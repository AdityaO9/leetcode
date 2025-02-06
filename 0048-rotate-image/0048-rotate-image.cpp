class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n = arr.size();
        int tmp[30][30];

        for (int i = n - 1, x = 0; i >= 0; i--, x++) {
            for (int j = n - 1, y = 0; j >= 0; j--, y++) {
                tmp[x][y] = arr[j][n - i - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = tmp[i][j];
            }
        }
    }
};