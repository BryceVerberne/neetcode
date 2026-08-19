class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Sort columns using binary search: log(n)
        int r = static_cast<int>(matrix.size()) - 1;
        int l = 0;
        int m;

        while (l <= r) {
            m = l + (r-l) / 2; // Prevent overflow

            int head = matrix[m][0];
            int tail = matrix[m][static_cast<int>(matrix[m].size()) - 1];

            // Calculate new r and l
            if (head > target) {
                r = m - 1;
            }
            else if (tail < target) {
                l = m + 1;
            }
            else { 
                break;
            }
        }

        // Sort the target row using binary search: log(m)
        vector<int>& arr = matrix[m];
        r = static_cast<int>(arr.size()) - 1;
        l = 0;

        while (l <= r) {
            m = l + (r-l) / 2;

            if (arr[m] < target) {
                l = m + 1;
            }
            else if (arr[m] > target) {
                r = m - 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};
