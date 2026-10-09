class Solution {
public:
    int minInsertions(string s) {

        int open = 0;
        int insertions = 0;
        int closeNeeded = 0;

        for(char ch : s){
            if(ch == '('){
                if(closeNeeded % 2 == 1){
                    insertions++;
                    closeNeeded--;
                }

                open++;
                closeNeeded += 2;
            }else{
                closeNeeded--;

                if(closeNeeded < 0){
                    insertions++;
                    open--;
                    closeNeeded = 1;
                }
            }
        }
        return insertions + closeNeeded;
        
    }
};