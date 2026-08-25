class Solution {
private:
    void dfs(int i, int n, int k, vector<int>& combo, vector<vector<int>>& combos) {
        if (combo.size() >= k || i >= n) {
            if (combo.size() == k) combos.push_back(combo);
            return;
        }

        combo.push_back(i+1);
        dfs(i+1, n, k, combo, combos);

        combo.pop_back();
        dfs(i+1, n, k, combo, combos);
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combo;
        vector<vector<int>> combos;
        dfs(0, n, k, combo, combos);

        return combos;
    }
};