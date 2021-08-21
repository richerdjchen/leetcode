class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.')
                    continue;
                int idx = board[r][c] - '0' - 1;
                if (row[r][idx])
                    return false;
                else
                    row[r][idx] = true;
                if (col[c][idx])
                    return false;
                else
                    col[c][idx] = true;
                int b = ((r / 3) * 3) + (c / 3);
                if (box[b][idx])
                    return false;
                else
                    box[b][idx] = true;
            }
        }
        return true;
    }
};