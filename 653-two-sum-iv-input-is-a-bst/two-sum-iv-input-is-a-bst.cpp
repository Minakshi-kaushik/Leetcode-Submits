class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;

        function<bool(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == nullptr) return false;

            int complement = k - node->val;

            if (seen.count(complement)) {
                return true;
            }

            seen.insert(node->val);

            return dfs(node->left) || dfs(node->right);
        };

        return dfs(root);
    }
};