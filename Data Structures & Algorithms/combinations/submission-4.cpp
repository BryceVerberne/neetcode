class Solution {
private:
    vector<vector<int>> solution;

    void dfs(int index, int n, int k, vector<int>& combo) {
        if (combo.size() == k) {
            solution.emplace_back(combo);
            return;
        }
        if (index > n) {
            return;
        }

        combo.emplace_back(index);
        dfs(index+1,n,k,combo);
        combo.pop_back();

        dfs(index+1,n,k,combo);
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combo;
        dfs(1,n,k,combo);
        return solution;
    }
};