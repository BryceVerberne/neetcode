class Solution {
private:
    unordered_map<int,int> m_parent;
    unordered_map<int,int> m_rank;

    int find(int n) {
        int node = n;

        while (m_parent[node] != node) {
            m_parent[node] = m_parent[m_parent[node]];
            node = m_parent[node];
        }

        return node;
    }

    bool find_union(int first, int second) {
        // Create new nodes if they don't exist
        if (!m_parent.contains(first)) {
            m_parent[first] = first;
            m_rank[first] = 0;
        }
        if (!m_parent.contains(second)) {
            m_parent[second] = second;
            m_rank[second] = 0;
        }

        // Find the node parents
        first = find(first);
        second = find(second);

        // Build the tree
        if (first == second) {
            return false;
        }
        if (m_rank[first] > m_rank[second]) {
            m_parent[second] = first;
        }
        else if (m_rank[first] < m_rank[second]) {
            m_parent[first] = second;
        }
        else {
            m_parent[second] = first;
            ++m_rank[first];
        }

        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (const auto& edge : edges) {
            if (!find_union(edge[0], edge[1])) {
                return edge;
            }
        }

        return vector<int>();
    }
};
