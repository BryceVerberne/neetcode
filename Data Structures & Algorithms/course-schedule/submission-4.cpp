class Solution {
private:
    void createList(
        vector<vector<int>>& prerequisites,
        unordered_map<int, vector<int>>& adjList) {
        for (const auto& prereq : prerequisites) {
            adjList[prereq[1]].push_back(prereq[0]);
        }
    }

    bool dfs(unordered_set<int>& visited, unordered_map<int, vector<int>>& adjList, int node) {
        if (visited.contains(node)) {
            return false;
        }
        if (adjList[node].empty()) {
            return true;
        }

        visited.insert(node);
        for (const int neighbor : adjList[node]) {
            if (!dfs(visited, adjList, neighbor)) {
                return false;
            }
        }
        visited.erase(node);
        adjList[node].clear();

        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        createList(prerequisites, adjList);

        unordered_set<int> visited;

        for (int course = 0; course < numCourses; ++course) {
            if (!dfs(visited, adjList, course)) {
                return false;
            }
        }

        return true;
    }
};
