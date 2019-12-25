class Solution {
public:
    string removeDuplicates(string S) {
        string order;
        for(auto & letter : S) {
            if(order.back() == letter) {
                order.pop_back();
            } else {
                order.push_back(letter);
            }
        }
        
        return order;
    }
};