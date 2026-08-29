class Solution {
private:

    struct Compare {
        bool operator()(vector<int>& x, vector<int>& y) const {
            return (pow(x[0], 2) + pow(x[1], 2) > (pow(y[0], 2) + pow(y[1], 2)));
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq(points.begin(), points.end());
        vector<vector<int>> result(k);
        
        for (int i = 0; i < k && !pq.empty(); ++i) {
            result[i] = pq.top();
            pq.pop();
        }

        return result;
    }
};
