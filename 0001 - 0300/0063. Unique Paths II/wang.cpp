// uint64_t; [int] leads overflow 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<uint64_t>> dp(obstacleGrid.size());
        int cnt = 1;
        for(int i = 0; i < dp.size(); i++)
        {
            dp[i].assign(obstacleGrid[i].size(), 0);

            if(obstacleGrid[i][0])
            {
                cnt = 0;
            }
            dp[i][0] = cnt;

        }

        cnt = 1;
        for(int i = 0; i < dp[0].size(); i++)
        {
            if(obstacleGrid[0][i]) cnt = 0;
            dp[0][i] = cnt; 
        }

        for(int i = 1; i < dp.size(); i++)
        {
            for(int j = 1; j < dp[i].size(); j++)
            {
                if(obstacleGrid[i][j]) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};
