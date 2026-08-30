class Solution {
private:
    int islandSearch(vector<vector<int>>& grid, int r, int c) {
        const int ROW = grid.size();
        const int COL = grid[0].size();

        if ((min(r,c) < 0) || (r >= ROW) || (c >= COL) || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;
        int count = 1;

        count += islandSearch(grid, r + 1, c);
        count += islandSearch(grid, r - 1, c);
        count += islandSearch(grid, r, c + 1);
        count += islandSearch(grid, r, c - 1);

        return count;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 1) {
                    int area = islandSearch(grid, r, c);
                    maxArea = (area > maxArea) ? area : maxArea;
                }
            }
        }

        return maxArea;
    }
};
