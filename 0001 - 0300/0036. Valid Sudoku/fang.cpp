class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int boxLookupTable[9][9]{0};
        int rowLookupTable[9][9]{0};
        int colLookupTable[9][9]{0};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                // 忽略空位
                if ('.' == board[i][j])
                    continue;
                // 查表检查
                int number = board[i][j] - '1';
                int boxIndex = i / 3 * 3 + j / 3;
                if (boxLookupTable[boxIndex][number] == 1 || rowLookupTable[i][number] == 1 || colLookupTable[j][number] == 1)
                    return false;
                else
                    boxLookupTable[boxIndex][number] = rowLookupTable[i][number] = colLookupTable[j][number] = 1;
            }
        }

        return true;
    }
};