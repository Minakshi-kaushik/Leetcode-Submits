class Solution {
public:
    bool isRotation(vector<int>& nums, vector<int>& sortedNums,
                    int start, int k) {
        vector<int> lps(k, 0);

        // Build the KMP prefix array for the target block.
        for (int i = 1, len = 0; i < k;) {
            if (sortedNums[start + i] == sortedNums[start + len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        // Search the target block in the circular source block.
        int j = 0;

        for (int i = 0; i < 2 * k - 1; i++) {
            int value = nums[start + (i % k)];

            while (j > 0 && value != sortedNums[start + j]) {
                j = lps[j - 1];
            }

            if (value == sortedNums[start + j]) {
                j++;
            }

            if (j == k) {
                return true;
            }
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) {
                continue;
            }

            bool possible = true;

            for (int start = 0; start < n; start += k) {
                if (!isRotation(nums, sortedNums, start, k)) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                ans += k;
            }
        }

        return ans;
    }
};