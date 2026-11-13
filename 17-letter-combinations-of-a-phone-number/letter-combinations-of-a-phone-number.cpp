class Solution {
public:

    vector<string>ans;

    vector<string>mapping = {
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };
    

    void solve(int index, string& digits, string& current){
        if(index == digits.size()){
            ans.push_back(current);
            return;
        }

        string letters = mapping[digits[index]-'0'];

        for(char ch : letters){
            current.push_back(ch);
            solve(index+1, digits, current);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        ans.clear();
        string current = "";
        solve(0, digits, current);
        return ans;
    }
};