// 方法一，二分查找，效率低O(N*logN)
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); ++i){
            if (binary_search(matrix[i].begin(), matrix[i].end(), target)) return true;
        }
        return false;
    }
};

// 方法二
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        if (m) {
            int n = matrix[0].size();
            int i = m - 1;
            int j = 0;
            while (i > -1 && j < n)
            {
                if (matrix[i][j] == target) return true;
                if (matrix[i][j] > target) --i;
                else ++j;
            }
        }
        return false;
    }
};