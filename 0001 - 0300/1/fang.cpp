// 并查集
class UFSet {
    vector<int> parent;

public:
    UFSet(const int& n)
    {
        parent.reserve(n);
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int Find(int p)
    {
        while (p != -1 && p != parent[p])
            p = parent[p];
        return p;
    }

    void Union(int p, int q)
    {
        p = Find(p);
        q = Find(q);
        if (p == q || p == -1)
            return;
        parent[p] = q;
    }

    void Remove(int p)
    {
        p = Find(p);
        if (p != -1)
            parent[p] = -1;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        int width, height = board.size();
        if (!height || !(width = board[0].size()))
            return;
        int size = width * height;
        UFSet ufset(size);

        for (int i = 1; i < height; ++i)
            for (int j = 0; j < width; ++j)
                if (board[i][j] == board[i - 1][j])
                    ufset.Union(i * width + j, (i - 1) * width + j);

        for (int i = 1; i < width; ++i)
            for (int j = 0; j < height; ++j)
                if (board[j][i] == board[j][i - 1])
                    ufset.Union(j * width + i, j * width + i - 1);

        for (int i = 0; i < height; ++i) {
            if (board[i][0] == 'O')
                ufset.Remove(i * width);
            if (board[i][width - 1] == 'O')
                ufset.Remove(i * width + width - 1);
        }

        for (int i = 1; i < width - 1; ++i) {
            if (board[0][i] == 'O')
                ufset.Remove(i);
            if (board[height - 1][i] == 'O')
                ufset.Remove(size - width + i);
        }

        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j) {
                int finder = ufset.Find(i * width + j);
                if (board[i][j] == 'O' && finder != -1) {
                    board[i][j] = 'X';
                }
            }
    }
};