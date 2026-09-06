class Solution {
private:
    bool dfs(int index, unordered_map<int,vector<int>>& adjList, 
             unordered_map<int,pair<bool,bool>>& visited) {
        if (visited[index].second) {
            return false; // not acyclical!
        }
        if (visited[index].first) {
            return true; // Already been evaluated
        }

        // Update node metadata
        visited[index] = {true, true};

        // Traverse neighbors
        for (const int neighbor : adjList[index]) {
            if (!dfs(neighbor, adjList, visited)) {
                return false;
            }
        }

        visited[index].second = false;

        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,pair<bool,bool>> visited; // pair<visit,path>
        unordered_map<int,vector<int>> adjList;

        // Create the adjList
        for (int i = 0; i < numCourses; ++i) {
            adjList[i] = vector<int>();
        }
        for (const auto& prereq : prerequisites) {
            adjList[prereq[0]].emplace_back(prereq[1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, adjList, visited)) {
                return false;
            }
        }

        return true;
    }
};
