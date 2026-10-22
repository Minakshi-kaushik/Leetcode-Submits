class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;

        int zero = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }

        int inc = 0, dec = 0;

        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;

            if (nums[i] > nums[next]) inc++;
            if (nums[i] < nums[next]) dec++;
        }

        if (inc == 1)
            return min(zero, n - zero + 2);

        if (dec == 1)
            return min(zero + 2, n - zero);

        return -1;
    }
};