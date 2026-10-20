class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = INT_MIN;
        int start = 0;
        int end = height.size()-1;
        
        while(start < end){
            int area = min(height[start], height[end])*(end-start);
            max_water = max(area, max_water);
           
           if(height[start] < height[end]){
            start++;
           }else{
            end--;
           }

        }
        return max_water;
        
    }
};