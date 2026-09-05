class Solution {
private:
    vector<vector<int>> solution;

    void dfs(int index, int n, int k, vector<int>& combo) {
        if (combo.size() == k) {
            solution.emplace_back(combo);
            return;
        }

        for (int i = index; i <= n; ++i) {
            combo.emplace_back(i);
            dfs(i+1,n,k,combo);
            combo.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combo;
        dfs(1,n,k,combo);
        return solution;
    }
};