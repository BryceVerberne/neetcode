class Solution {
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int target, int color) {
        const int ROW = image.size();
        const int COL = image[0].size(); 

        if ((min(sr, sc) < 0) || (sr >= ROW) || (sc >= COL) || 
            (image[sr][sc] == color) || (image[sr][sc] != target)) {
            return;
        }

        if (image[sr][sc] == target) {
            image[sr][sc] = color; // Set the pixel to color
        }

        dfs(image, sr + 1, sc, target, color);
        dfs(image, sr - 1, sc, target, color);
        dfs(image, sr, sc + 1, target, color);
        dfs(image, sr, sc - 1, target, color);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};