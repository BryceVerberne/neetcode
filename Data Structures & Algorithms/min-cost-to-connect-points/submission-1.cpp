class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>, 
                       greater<pair<int,int>>> minHeap;
        unordered_set<int> visited;
        int cost = 0;
        
        // Create the MST
        minHeap.emplace(0,0);
        while ((visited.size() < points.size()) && !minHeap.empty()) {
            auto data = minHeap.top();
            minHeap.pop();

            int weight = data.first;
            int dest = data.second;

            // Ensure this node hasn't already been connected
            if (visited.contains(dest)) {
                continue;
            }

            visited.insert(dest);
            cost += weight;

            // Map out the distances from the destination node
            for (int i = 0; i < points.size(); ++i) {
                if (!visited.contains(i)) {
                    int w = abs(points[dest][0] - points[i][0]) + 
                            abs(points[dest][1] - points[i][1]);
                    minHeap.emplace(w,i);
                }
            }
        }

        return cost;
    }
};
