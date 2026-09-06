class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        unordered_map<int,vector<pair<int,int>>> adjList;
        unordered_map<int,int> shortest;

        int received = 0;
        int time = 0;

        // Build the adjList
        for (int i = 1; i <= n; ++i) {
            adjList[i] = vector<pair<int,int>>();
        }

        // Populate our adjList
        for (const auto& time : times) {
            adjList[time[0]].emplace_back(time[2],time[1]);
        }

        // Get the distances to our nodes
        minHeap.emplace(0,k);
        while (!minHeap.empty()) { 
            pair<int,int> top = minHeap.top();
            minHeap.pop();

            int weight = top.first;
            int node = top.second;

            if (shortest.contains(node)) {
                continue;
            }

            shortest[node] = weight;
            time = max(time,weight);
            received++;

            // Get the neighbors
            for (const auto& neighbor : adjList[node]) {
                if (!shortest.contains(neighbor.second)) {
                    minHeap.emplace(weight + neighbor.first,neighbor.second);
                }
            }
        }

        return (received == n) ? time : -1;
    }
};
