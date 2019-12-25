// 使用并查集
class Solution {
public:
    void init(vector<int> &set) {
        for(int i=0; i<set.size(); ++i) set[i]=i;
    }
    int find(vector<int> &set, int x) {
        while(x!=set[x])x=set[x];
        return x;
    }
    
    void unite(vector<int> &set, int &cnt, int p, int q) {
        p=find(set, p);
        q=find(set, q);
        if(p!=q) {
            set[p]=q;
            cnt--;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        int count = row * col;
        int idx, i, j;
        vector<int> set(count);
        
        init(set);
        for(i=0,idx=0; i<row; ++i) {
            for(j=0; j<col-1; ++j, ++idx) {
                if(grid[i][j]=='1'&& grid[i][j+1]=='1') unite(set, count, idx, idx+1);
            }
            ++idx;
        }
        for(i=0,idx=0; i<row-1; ++i) {
            for(j=0; j<col; ++j,++idx) {
            if(grid[i][j]=='1' && grid[i+1][j]=='1') unite(set, count, idx, idx+col);
            }
        }
        
        for(auto &patch : grid)
            for(auto &c : patch)
                if(c=='0') count--;
        
        return count;
    }
};