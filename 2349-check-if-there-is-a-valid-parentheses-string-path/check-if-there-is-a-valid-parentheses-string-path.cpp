class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // A valid parentheses string must have even length
        if ((m + n - 1) % 2 != 0)
            return false;

        // dp[i][j][balance] = can we reach (i,j)
        // with the given balance?
        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(n, vector<bool>(m + n, false))
        );

        // Starting cell must be '('
        if (grid[0][0] == ')')
            return false;

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Skip starting cell
                if (i == 0 && j == 0)
                    continue;

                for (int balance = 0; balance <= m + n - 1; balance++) {

                    int newBalance;

                    if (grid[i][j] == '(')
                        newBalance = balance - 1;
                    else
                        newBalance = balance + 1;

                    // If previous balance would be invalid
                    if (newBalance < 0 || newBalance >= m + n)
                        continue;

                    // We can come from above
                    if (i > 0 && dp[i - 1][j][newBalance])
                        dp[i][j][balance] = true;

                    // Or from left
                    if (j > 0 && dp[i][j - 1][newBalance])
                        dp[i][j][balance] = true;
                }
            }
        }

        // Valid string must finish with balance 0
        return dp[m - 1][n - 1][0];
    }
};