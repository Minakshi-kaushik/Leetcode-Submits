class Solution {
public:
    int maxVowels(string s, int k) {
        int vow_count = 0;
        for(int i = 0; i < k; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'  ){
                vow_count++;
            }
        }
        int max_vow = vow_count;
        for(int i = k ; i < s.size(); i++){
            if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u'  ){
                vow_count--;
            }
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'  ){
                vow_count++;
            }
            max_vow = max(max_vow, vow_count);
        }

        return max_vow;
        
    }
};