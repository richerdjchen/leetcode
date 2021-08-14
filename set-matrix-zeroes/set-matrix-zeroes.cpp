class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool top = false;
        bool left = false;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                    if (i == 0)
                        top = true;
                    if (j == 0)
                        left = true;
                }
            }
        }
        // iterate through the first columns
        for (int i = 1; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) {
                for (int k = 1; k < matrix.size(); k++) {
                    matrix[k][i] = 0;
                }
            }
        }
        //iterate through through all rows
        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < matrix[0].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (top) {
            for (int j = 1; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
        if (left) {
            for (int i = 1; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};