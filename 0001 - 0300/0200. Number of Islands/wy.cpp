#include <__msvc_all_public_headers.hpp>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num_of_islands = 0;
        vector<vector<bool>> visited(grid.size());

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                visited[i].push_back(false);
            }
        }

        int go[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (!visited[i][j])
                {
                    visited[i][j] = true;
                    stack<pair<int, int>> s;
                    if (grid[i][j] == '1')
                    {
                        s.push(make_pair(i, j));
                        num_of_islands++;
                    }

                    //dfs
                    while (!s.empty())
                    {
                        pair<int, int> p = s.top();
                        s.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            if (p.first + go[k][0] >= grid.size() || p.first + go[k][0] < 0
                                || p.second + go[k][1] < 0 || p.second + go[k][1] >= grid[0].size())
                                continue;

                            if (visited[p.first + go[k][0]][p.second + go[k][1]] == true) continue;
                            visited[p.first + go[k][0]][p.second + go[k][1]] = true;

                            if (grid[p.first + go[k][0]][p.second + go[k][1]] == '1') {
                                s.push(make_pair(p.first + go[k][0], p.second + go[k][1]));
                            }
                        }
                    }
                }
            }
        }

        return num_of_islands;
    }
};

int main() {
    vector<vector<char>> grid(4);
    grid[0] = { '1', '1', '1', '1', '0' };
    grid[1] = { '1', '1', '0', '1', '0' };
    grid[2] = { '1', '1', '0', '0', '0' };
    grid[3] = {'0', '0', '0', '1', '1' };

    Solution s;
    cout << s.numIslands(grid) << std::endl;
    return 0;

}
