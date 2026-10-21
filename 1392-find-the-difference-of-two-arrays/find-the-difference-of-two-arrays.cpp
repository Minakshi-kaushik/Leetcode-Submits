class Solution {
public:

    vector<int> existsIn(vector<int> & nums1, vector<int> & nums2){
        unordered_set<int> existsin2 ;
        unordered_set<int> result;

        for(int num : nums2){
            existsin2.insert(num);
        }

        for(int num : nums1){
            if(existsin2.find(num) == existsin2.end()){
                result.insert(num);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {existsIn(nums1, nums2),existsIn(nums2, nums1)};
    }
};