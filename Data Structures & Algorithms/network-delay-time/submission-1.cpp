class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        unordered_map<int,vector<pair<int,int>>> adjList;
        unordered_map<int,int> shortest;
        int minimum = 0;
        int received = n;

        // Create adjacency list
        for (int i = 1; i <= n; ++i) {
            adjList[i] = vector<pair<int,int>>();
        }

        // Add neighbors to the adjacency list
        for (const auto& time : times) {
            adjList[time[0]].emplace_back(time[2],time[1]);
        }

        // Find the shortest path for each node
        minHeap.emplace(0,k);
        while (!minHeap.empty()) {
            pair<int,int> n = minHeap.top();
            minHeap.pop();

            int weight = n.first;
            int node = n.second;

            if (shortest.contains(node)) {
                continue;
            }
            shortest[node] = weight;

            // Track the time & that the message was received
            minimum = max(minimum,weight);
            --received;

            // Add neighbors
            for (const auto& edge : adjList[node]) {
                if (!shortest.contains(edge.second)) {
                    minHeap.emplace(weight + edge.first,edge.second);
                }
            }
        }

        return (received == 0) ? minimum : -1;
    }
};
