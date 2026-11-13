
class Solution {
public:
    vector<vector<int>> ans;

    void solve(int start, int k, int sum, int n,
               vector<int>& current) {

        // Base case
        if (k == 0) {
            if (sum == n) {
                ans.push_back(current);
            }
            return;
        }

        // Pruning: sum already exceeds target
        if (sum > n) return;

        // Try available numbers
        for (int i = start; i <= 9 - k + 1; i++) {

            current.push_back(i);

            solve(i + 1, k - 1, sum + i, n, current);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        ans.clear();

        vector<int> current;

        solve(1, k, 0, n, current);

        return ans;
    }
};
