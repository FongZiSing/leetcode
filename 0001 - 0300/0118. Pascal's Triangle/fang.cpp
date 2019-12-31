class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for(int i=1; i<= numRows; ++i) {
            ret.push_back(vector<int>(i, 1));
        }
        for(int p=2; p < numRows; ++p)
            for(int q=1; q < p; ++q)
                ret[p][q] = ret[p-1][q] + ret[p-1][q-1];
        
        return ret;
    }
};