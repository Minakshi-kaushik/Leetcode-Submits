class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        int i = 0;

        while(i < n){
            char current = chars[i];
            int count = 0;
            while(i < n && chars[i] == current){
                i++;
                count++;
            }
            chars[write++] = current;

            if(count > 1){
                string num = to_string(count);

                for(char digit : num){
                    chars[write++] = digit;
                }
            }
        }
        return write;
        
    }
};