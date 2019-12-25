// 利用异或运算
class Solution {
public:
    char findTheDifference(string s, string t) {
        char diff = '\0';
        for(char letter: s) {
            diff ^= letter;
        }      
        for(char letter: t) {
            diff ^= letter;
        }
        
        return diff;
    }
};