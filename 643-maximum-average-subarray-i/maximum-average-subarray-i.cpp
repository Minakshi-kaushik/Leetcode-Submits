class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum+=nums[i];
        }
        int max_sum = sum;
        

        for(int j = k; j < nums.size(); j++){
            sum = sum-nums[j-k]+nums[j];
            max_sum = max(max_sum , sum);
            
        }
        return double(max_sum)/k;
        
    }
};