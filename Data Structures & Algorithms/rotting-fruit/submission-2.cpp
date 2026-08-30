class Solution {
private:
    struct HashPair {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
        }
    };

    int bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q) {
        const int ROW = grid.size();
        const int COL = grid[0].size();

        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        unordered_set<pair<int,int>, HashPair> visited;

        // Make all the fruit rotten
        int time = 0;
        while (!q.empty()) {
            bool fresh = false;
            int size = q.size();
            
            for (int i = 0; i < size; ++i) {
                int r = q.front().first;
                int c = q.front().second;
                grid[r][c] = 2;
                q.pop();

                for (const auto& direction : directions) {
                    int dr = r + direction.first;
                    int dc = c + direction.second;

                    if ((min(dr,dc) < 0) || (dr >= ROW) || (dc >= COL) ||
                        (visited.contains({dr,dc})) || (grid[dr][dc] == 0) || 
                        (grid[dr][dc] == 2)) {
                        continue;
                    }

                    visited.insert({dr, dc});
                    q.push({dr,dc});
                    fresh = true;
                }
            }

            if (fresh) ++time;
        }

        return time;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int fresh = 0;
        queue<pair<int,int>> rotten;

        // Find all the rotten & fresh fruit in the matrix
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 2) {
                    rotten.push({r,c});
                }
                else if (grid[r][c] == 1) {
                    ++fresh;
                }
            }
        }

        // Track time if fresh fruit exist
        if (fresh > 0) {
            time = bfs(grid, rotten);
        }
        else {
            return 0;
        }

        // Check if fresh fruit remain
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 1) {
                    return -1;
                }
            }
        }

        return time;
    }
};
