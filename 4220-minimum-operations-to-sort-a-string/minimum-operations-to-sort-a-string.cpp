
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Case 1: Already sorted
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        // Case 2: Length 2 cannot be sorted
        if (n == 2) {
            return -1;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // Case 3: One operation is sufficient
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        // Case 4: Three operations are needed
        if (s[0] == mx && s[n - 1] == mn) {
            int cntMin = count(s.begin(), s.end(), mn);
            int cntMax = count(s.begin(), s.end(), mx);

            if (cntMin == 1 && cntMax == 1) {
                return 3;
            }
        }

        // Case 5: Otherwise, two operations
        return 2;
    }
};
