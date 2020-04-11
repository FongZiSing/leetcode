class Solution {
    using iter = vector<int>::iterator;
    iter my_upper_bound(iter first, iter last, int value) {
        int len = distance(first, last), half;
        iter middle;
        while (len > 0) {
            half = len >> 1;
            middle = first;
            advance(middle, half);
            if (value < *middle) {
                first = middle;
                ++first;
                len = len - half - 1;
            } else {
                len = half;
            }
        }
        return first;
    }

public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (auto& patch : grid)
            count += distance(my_upper_bound(patch.begin(), patch.end(), -1), patch.end());
        return count;
    }
};