class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        function<bool(int, int, int)> dfs = [&](int r, int c, int index) -> bool {
            if (index == word.size()) return true;
            if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index]) return false;

            char temp = board[r][c];
            board[r][c] = '*'; // Mark as visited

            bool found = dfs(r + 1, c, index + 1) ||
                         dfs(r - 1, c, index + 1) ||
                         dfs(r, c + 1, index + 1) ||
                         dfs(r, c - 1, index + 1);

            board[r][c] = temp; // Restore the cell
            return found;
        };

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (dfs(r, c, 0)) return true;
            }
        }
        return false;
    }
};