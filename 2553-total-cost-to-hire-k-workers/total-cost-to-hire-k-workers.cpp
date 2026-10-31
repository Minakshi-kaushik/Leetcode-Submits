class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>left, right;

        int l = 0; int r = n-1;

        // fill left heap
        for(int i = 0; i < candidates && l <= r; i++){
            left.push({costs[l], l});
            l++;
        }

        for(int i = 0; i < candidates && l <= r ; i++){
            right.push({costs[r], r});
            r--;
        }
        long long ans = 0;

        for(int i = 0; i < k; i++){
            if(right.empty() || (!left.empty() && left.top() < right.top())){
                auto worker = left.top();

                left.pop();
                ans+=worker.first;

                if(l <= r){
                    left.push({costs[l],l});
                    l++;
                }
            }else{
                auto worker = right.top();
                right.pop();
                ans+= worker.first;

                if(l <= r){
                    right.push({costs[r], r});
                    r--;
                }
            }
        }
        return ans;
        
    }
};