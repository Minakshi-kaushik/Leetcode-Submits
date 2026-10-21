class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        for(int num : arr){
            freq[num]++;
        }

        unordered_set<int> seen;
        for(auto it = freq.begin(); it != freq.end(); it++){
            if(seen.find(it->second) != seen.end()) return false;
            seen.insert(it->second);
        }
        return true;
    }
};