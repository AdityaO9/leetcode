class Solution {
public:

// Function to check if placing a queen at (row, col) is safe
bool isSafe(int row, int col, vector<string>& temp, int n){
    int duprow = row;
    int dupcol = col;
    
    // Check upper diagonal (↖)
    while (row >= 0 && col >= 0) {
        if (temp[row][col] == 'Q') return false;
        row--; col--;
    }

    row = duprow;
    col = dupcol;
    
    // Check left side (←)
    while (col >= 0) {
        if (temp[row][col] == 'Q') return false;
        col--;
    }
    
    row = duprow;
    col = dupcol;
    
    // Check lower diagonal (↙)
    while (row < n && col >= 0) {
        if (temp[row][col] == 'Q') return false;
        row++; col--;
    }
    
    return true; // If no threats found, return true
}

// Recursive function to place queens column by column
void solve(int col, vector<vector<string>>& ans, vector<string>& temp, int n) {
    // Base case: If all columns are filled, add the board to solutions
    if (col == n) {
        ans.push_back(temp);
        return;
    }

    // Try placing a queen in each row of the current column
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, temp, n)) { // Check if placing a queen is safe
            temp[row][col] = 'Q'; // Place queen
            solve(col + 1, ans, temp, n); // Move to next column
            temp[row][col] = '.'; // Backtrack: Remove queen and try next possibility
        }
    }
}

// Main function to solve the N-Queens problem
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans; // Stores all valid board configurations
    vector<string> temp(n, string(n, '.')); // Initialize empty board
    
    solve(0, ans, temp, n); // Start placing queens from the first column
    
    return ans; // Return all valid solutions
}
};