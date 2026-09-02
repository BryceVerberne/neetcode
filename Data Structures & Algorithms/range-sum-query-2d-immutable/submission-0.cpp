class NumMatrix {
private:
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int sum = 0;

        // Create prefix sum matrix
        for (const auto& row : matrix) {
            vector<int> prefixRow;
            for (const int col : row) {
                sum += col;
                prefixRow.push_back(sum);
            }
            prefix.push_back(prefixRow);
            sum = 0;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;

        while (row1 <= row2) {
            int lPrefix = (col1 == 0) ? 0 : prefix[row1][col1-1];
            int rPrefix = prefix[row1][col2];
            sum += rPrefix - lPrefix;

            ++row1; // Move to the next row
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */