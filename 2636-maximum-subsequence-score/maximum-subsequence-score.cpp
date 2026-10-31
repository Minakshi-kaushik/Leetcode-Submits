class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int  n = nums1.size();

        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({nums2[i], nums1[i]});
        }

        sort(v.rbegin(), v.rend());

        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum = 0;
        long long ans = 0;

        for(int i = 0; i < n; i++){
            int num2 = v[i].first;
            int num1 = v[i].second;

            pq.push(num1);
            sum+=num1;

            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k){
                long long score = sum*num2;
                ans = max(ans, score);
            }
        }
        return ans;
    }
};