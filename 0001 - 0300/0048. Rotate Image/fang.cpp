class Solution {
public:
    // 两次镜像处理
    void rotate(vector<vector<int>>& matrix) {
        int num;
        int n =  matrix.size() - 1;
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j < n - i; ++j) {
                num = matrix[i][j];
                matrix[i][j] = matrix[n-j][n-i];
                matrix[n-j][n-i] = num;
            }
        }
        
        
        for(int i = 0, len = (matrix.size() + 1)/2; i < len; ++i) {
            auto row = matrix[i];
            matrix[i] = matrix[n - i];
            matrix[n - i] = row;
        }
        
    }
};