class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int operations = 0;
        sort(nums.begin(), nums.end());

        int start = 0;
        int end = nums.size()-1;

        while(start < end){
            if(nums[start]+nums[end] == k){
                operations++;
                end--;
                start++;
            }else if((nums[start]+nums[end]) < k){
                start++;
            }else{
                end--;
            }
        }
        return operations;
        
        
    }
};