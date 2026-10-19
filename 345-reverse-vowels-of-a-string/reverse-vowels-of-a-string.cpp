class Solution {
public:
    string reverseVowels(string s) {
        int start = 0;
        int last = s.size()-1;

        unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'
        };
        while(start < last){
            if(vowels.contains(s[start])  && vowels.contains(s[last])){
                swap(s[start], s[last]);
                start++;
                last--;

            }
            
             if(!vowels.contains(s[start])){
                start++;
            }

            if(!vowels.contains(s[last])){
                last--;
            }
            
        }
        return s;
        
        
    }
};