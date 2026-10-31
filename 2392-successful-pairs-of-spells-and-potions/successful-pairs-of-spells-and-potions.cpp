class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs(n);

        for(int i = 0; i < n; i++){
            int low = 0;
            int high = m-1;

            int ans = m;

            while(low <= high){
                int mid = low + (high-low)/2;

                if(1LL*spells[i]*potions[mid] >= success){
                    ans = mid;
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            pairs[i] = m-ans;
        }
        return pairs;
    }
};