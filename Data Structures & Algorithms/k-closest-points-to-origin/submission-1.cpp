class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> sorted = sort(points, 0, points.size() - 1);
        vector<vector<int>> closest(sorted.begin(), sorted.begin() + k);

        return closest;
    }

private:
    // Calculate the distance
    double distance(vector<int>& point) {
        return sqrt(pow(point[0],2) + pow(point[1],2));
    }

    // Sort the array
    vector<vector<int>> sort(vector<vector<int>>& points, int s, int e) {
        if ((e - s + 1) <= 1) return points;

        int left = s;
        vector<int> pivot = points[e];
        double pivotVal = distance(pivot);

        // Sort around the pivot
        for (int i = s; i < e; ++i) {
            if (distance(points[i]) < pivotVal) {
                // Swap with left
                vector<int> tmp = points[left];
                points[left] = points[i];
                points[i] = tmp;
                ++left;
            }
        }

        // Make final swap
        points[e] = points[left];
        points[left] = pivot;

        // Recursive case
        sort(points, s, left - 1);
        sort(points, left + 1, e);

        return points;
    }
};
