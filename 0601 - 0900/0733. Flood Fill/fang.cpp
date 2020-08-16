class Solution {
    bool IsWithin(int val, int min, int max)
    {
        return val >= min && val < max;
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        queue<pair<int, int>> q;
        int offset_r[] = {0, 1, 0, -1};
        int offset_c[] = {1, 0, -1, 0};
        int n = image.size();
        int m = image[0].size();
        int srcColor = image[sr][sc];
        deque<deque<bool>> visited(n, deque<bool>(m, false));
        int r, c, r1, c1;

        q.push(make_pair(sr, sc));
        while (!q.empty()) {
            tie(r, c) = q.front();
            q.pop();
            image[r][c] = newColor;
            visited[r][c] = true;
            for (int i = 0; i < 4; ++i) {
                r1 = r + offset_r[i];
                c1 = c + offset_c[i];
                if (IsWithin(r1, 0, n) && IsWithin(c1, 0, m) && image[r1][c1] == srcColor && !visited[r1][c1]) {
                    q.push(make_pair(r1, c1));
                }
            }
        }

        return image;
    }
};