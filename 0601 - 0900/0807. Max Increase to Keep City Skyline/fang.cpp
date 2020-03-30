class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int width = grid[0].size(), height = grid.size(), value, result = 0;
        vector<int> horizontal(width, 0);
        vector<int> vertical(height, 0);
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                vertical[i] = max(vertical[i], grid[i][j]);
                horizontal[j] = max(horizontal[j], grid[i][j]);
            }
        }
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                value = min(vertical[i], horizontal[j]);
                result += -(value > grid[i][j]) & (value - grid[i][j]);
            }
        }

        return result;
    }
};