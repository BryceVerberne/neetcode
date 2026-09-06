class Solution {
private:
    bool dfs(int index, const std::unordered_map<int,std::vector<int>>& adjList,
             std::unordered_map<int,std::pair<bool,bool>>& visited,
             std::vector<int>& topSort) {
        
        if (visited[index].second) {
            return false; // Cycle detected!
        }
        if (visited[index].first) {
            return true; // Already evaluated
        }

        visited[index] = {true, true};
        for (const int neighbor : adjList.at(index)) {
            if (!dfs(neighbor, adjList, visited, topSort)) {
                return false;
            }
        }
        visited[index].second = false;
        topSort.emplace_back(index);

        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int,std::pair<bool,bool>> visited; // pair<visit,path>
        std::unordered_map<int,std::vector<int>> adjList;
        std::vector<int> topSort;

        // Get the adjList
        for (int i = 0; i < numCourses; ++i) {
            adjList[i] = std::vector<int>();
        }
        for (const auto& prereq : prerequisites) {
            adjList[prereq[0]].emplace_back(prereq[1]);
        }

        // List the classes and ensure no cycles
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, adjList, visited, topSort)) {
                return std::vector<int>();
            }
        }

        // Prepare and deliver final outcome
        return topSort;
    }
};
