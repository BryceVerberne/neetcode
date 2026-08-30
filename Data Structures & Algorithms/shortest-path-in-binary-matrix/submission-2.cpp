class Solution {
private: 
    struct HashPair {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
        }
    };

    int bfs(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }

        const int ROW = grid.size();
        const int COL = grid[0].size();
        int r = 0;
        int c = 0;

        vector<pair<int,int>> directions = {{0,1},{0,-1},
                                            {1,0},{-1,0},
                                            {1,1},{1,-1},
                                            {-1,1},{-1,-1}};

        unordered_set<pair<int,int>, HashPair> visited;
        queue<pair<int,int>> q;

        visited.insert({r,c});
        q.push({r,c});
        
        int length = 1;
        while (!q.empty()) {

            int size = q.size();
            for (int i = 0; i < size; ++i) {
                r = q.front().first;
                c = q.front().second;
                q.pop();

                // Check if we're at the destination
                if ((r == (ROW - 1)) && (c == (COL - 1))) {
                    return length;
                }

                for (const auto& direction : directions) {
                    int dr = r + direction.first;
                    int dc = c + direction.second;

                    // Establish bounds
                    if ((min(dr, dc) < 0) || (dr >= ROW) || (dc >= COL) ||
                        (grid[dr][dc] == 1) || visited.contains({dr, dc})) {
                        continue;
                    }

                    visited.insert({dr,dc});
                    q.push({dr,dc});
                }
            }

            ++length;
        }

        return -1;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};