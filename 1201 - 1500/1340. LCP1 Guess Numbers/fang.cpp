class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int equals=0;
        for(int i=0; i<guess.size(); ++i)
            equals+=guess[i]==answer[i];
        return equals;
    }
};