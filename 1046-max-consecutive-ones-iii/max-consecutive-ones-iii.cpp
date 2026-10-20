class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int start = 0;
        int zeros = 0;
        int max_len = 0;

        for(int end = 0; end < nums.size(); end++){
            if(nums[end] == 0){
                zeros++;
            }

            while(zeros > k){
                if(nums[start] == 0){
                    zeros--;
                }
                start++;
            }
            max_len = max(max_len, end - start + 1);
        }
        return max_len;
        
    }
};