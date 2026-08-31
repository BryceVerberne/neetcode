/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        unordered_map<int, Node*> newGraph; // New graph
        unordered_set<int> visited;         // Old graph
        queue<Node*> q;

        // Initialize the queue with known values
        newGraph[1] = new Node(1);
        visited.insert(1);
        q.push(node);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                Node* current = q.front();
                q.pop();

                for (const auto& neighbor : current->neighbors) {
                    int val = neighbor->val;

                    if (!visited.contains(val)) {
                        visited.insert(val);
                        q.push(neighbor);

                        newGraph[val] = new Node(val);
                    }

                    newGraph[current->val]->neighbors.push_back(newGraph[neighbor->val]);
                }
            }
        }

        return newGraph[1];
    }
};
