class Solution {
public:
    set<string> ans;

    void dfs(string &s, int i, int leftRemove, int rightRemove,
             int balance, string curr) {

        if (i == s.size()) {
            if (leftRemove == 0 &&
                rightRemove == 0 &&
                balance == 0) {
                ans.insert(curr);
            }
            return;
        }

        // Remove current character
        if (s[i] == '(' && leftRemove > 0) {
            dfs(s, i + 1, leftRemove - 1, rightRemove,
                balance, curr);
        }

        if (s[i] == ')' && rightRemove > 0) {
            dfs(s, i + 1, leftRemove, rightRemove - 1,
                balance, curr);
        }

        // Keep current character
        if (s[i] == '(') {
            dfs(s, i + 1, leftRemove, rightRemove,
                balance + 1, curr + s[i]);
        }
        else if (s[i] == ')') {
            if (balance > 0) {
                dfs(s, i + 1, leftRemove, rightRemove,
                    balance - 1, curr + s[i]);
            }
        }
        else {
            // Letter
            dfs(s, i + 1, leftRemove, rightRemove,
                balance, curr + s[i]);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum removals
        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {
                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        dfs(s, 0, leftRemove, rightRemove, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};
