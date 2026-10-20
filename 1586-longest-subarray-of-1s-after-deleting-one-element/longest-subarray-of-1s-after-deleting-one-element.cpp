class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0;
        int zeros = 0;
        int maxi = 0;

        for(int end = 0; end < nums.size(); end++){
            if(nums[end] == 0) zeros++;

            while(zeros > 1){
                if(nums[start] == 0) zeros--;

                start++;
            }
            maxi = max(maxi, end - start + 1);
        }
        return maxi-1;
    }
};