class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int temp = 0;
        int remnent = 0;
        auto max = max_element(height.begin(), height.end());
        for(auto p=height.begin(), q = height.begin()+1; q < max+1; ++q) {
            if(*p <= *q) {
                p = q;
                remnent += temp;
                temp = 0;
            } else {
                temp += *p - *q;
            }
        }
        for(auto p=height.end()-1, q = height.end()-2; q > max-1; --q) {
            if(*p <= *q) {
                p = q;
                remnent += temp;
                temp = 0;
            } else {
                temp += *p - *q;
            }
        }

        return remnent;
    }
};