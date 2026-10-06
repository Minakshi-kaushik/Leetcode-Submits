class Solution {
public:
    int minAddToMakeValid(string s) {
       
        int close = 0;

        stack<char> st;
        for(char ch : s){
            if(ch == '(') {
                st.push(ch);
                }

            else if(ch == ')' && st.empty()){
                close++;
            }
            else if(!st.empty() && ch == ')'){
                st.pop();
            }
  
    }
    return st.size() + close;
    }
};