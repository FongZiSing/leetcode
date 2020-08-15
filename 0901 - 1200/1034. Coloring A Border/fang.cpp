class Solution {
    bool isBound(const int& val, const int& floor, const int& ceil)
    {
        return val < floor || val >= ceil;
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color)
    {
        const int offset[2][4] = {{0, 1, 0, -1}, {1, 0, -1, 0}};
        const int width = grid[0].size();
        const int height = grid.size();
        deque<deque<bool>> visited(height, deque<bool>(width, false));
        vector<vector<int>> result(grid.begin(), grid.end());
        queue<pair<int, int>> s;
        int count;

        copy(grid.begin(), grid.end(), result.begin());
        s.push(make_pair(r0, c0));
        while (!s.empty()) {
            tie(r0, c0) = s.front();
            s.pop();
            visited[r0][c0] = true;
            count = 0;
            for (int i = 0; i < 4; ++i) {
                int y = r0 + offset[0][i];
                int x = c0 + offset[1][i];
                if (isBound(x, 0, width) || isBound(y, 0, height))
                    continue;
                if (grid[y][x] == grid[r0][c0]) {
                    count++;
                    if (visited[y][x])
                        continue;
                    s.push(make_pair(y, x));
                }
            }
            if (count != 4) {
                result[r0][c0] = color;
            }
        }
        return result;
    }
};