class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        const int ROW = grid.size();
        const int COL = grid[0].size();

        if ((min(r, c) < 0) || (r >= ROW) || (c >= COL) || (grid[r][c] == '0')) {
            return;
        }

        grid[r][c] = '0';

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == '1') {
                    ++islands;
                    dfs(grid, r, c);
                }
            }
        }

        return islands;
    }
};
