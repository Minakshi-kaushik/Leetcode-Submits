class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alti = 0;
        int maxi = 0;
        for(int i = 0; i < gain.size(); i++){
            alti += gain[i];
            maxi = max(maxi, alti);
        }
        return maxi;
        
    }
};