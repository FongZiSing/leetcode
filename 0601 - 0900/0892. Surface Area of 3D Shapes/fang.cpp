class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N = grid.size(), cubeNum = 0, cover = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] > 0) {
                    cubeNum += grid[i][j];
                    cover += grid[i][j] - 1;
                    i > 0 && (cover += min(grid[i][j], grid[i - 1][j]));
                    j > 0 && (cover += min(grid[i][j], grid[i][j - 1]));
                }
            }
        }

        return (cubeNum << 2) + (cubeNum << 1) - (cover << 1);
    }
};

// or
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int size = grid.size();
        int cubeNum = 0;
        int cover = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cubeNum += grid[i][j];
                grid[i][j] && (cover += grid[i][j] - 1);
            }
        }

        for (int i = 0; i < size; ++i)
            for (int j = 1; j < size; ++j)
                cover += min(grid[i][j], grid[i][j - 1]);

        for (int i = 1; i < size; ++i)
            for (int j = 0; j < size; ++j)
                cover += min(grid[i][j], grid[i - 1][j]);

        return (cubeNum << 2) + (cubeNum << 1) - (cover << 1);
    }
};