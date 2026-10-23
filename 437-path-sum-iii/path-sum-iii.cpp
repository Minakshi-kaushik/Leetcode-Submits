
class Solution {
public:
    int dfs(TreeNode* root, long long currentSum,
            int targetSum, unordered_map<long long, int>& prefix) {

        if (root == nullptr) {
            return 0;
        }

        currentSum += root->val;

        int count = prefix[currentSum - targetSum];

        prefix[currentSum]++;

        count += dfs(root->left, currentSum, targetSum, prefix);
        count += dfs(root->right, currentSum, targetSum, prefix);

        // Remove this prefix when returning to the parent.
        prefix[currentSum]--;

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix;

        // An empty prefix has sum 0.
        prefix[0] = 1;

        return dfs(root, 0, targetSum, prefix);
    }
};
