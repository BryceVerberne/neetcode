class Solution {
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int target, int color, const int rsize, const int csize) { 
        if ((min(sr, sc) < 0) || (sr >= rsize) || (sc >= csize) || 
            (image[sr][sc] == color) || (image[sr][sc] != target)) {
            return;
        }

        image[sr][sc] = color;

        dfs(image, sr + 1, sc, target, color, rsize, csize);
        dfs(image, sr - 1, sc, target, color, rsize, csize);
        dfs(image, sr, sc + 1, target, color, rsize, csize);
        dfs(image, sr, sc - 1, target, color, rsize, csize);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target = image[sr][sc];
        if (target == color) {
            return image;
        }

        dfs(image, sr, sc, target, color, image.size(), image[0].size());
        return image;
    }
};