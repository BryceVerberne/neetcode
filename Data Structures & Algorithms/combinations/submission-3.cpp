class Solution {
private:
    void dfs(int i, int n, int k, vector<int>& combo, vector<vector<int>>& combos) {
        if (combo.size() == k) {
            combos.push_back(combo);
            return;
        }
        if (i > n) {
            return;
        }

        for (int j = i; j <= n; ++j) {
            combo.push_back(j);
            dfs(j+1, n, k, combo, combos);
            combo.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combo;
        vector<vector<int>> combos;
        dfs(1, n, k, combo, combos);

        return combos;
    }
};