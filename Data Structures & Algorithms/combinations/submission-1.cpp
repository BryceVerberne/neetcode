class Solution {
private:
    void dfs(int i, int size, vector<int>& nums, vector<int>& combo, vector<vector<int>>& combos) {
        if (combo.size() >= size || i >= nums.size()) {
            if (combo.size() == size) combos.push_back(combo);
            return;
        }

        combo.push_back(nums[i]);
        dfs(i+1, size, nums, combo, combos);

        combo.pop_back();
        dfs(i+1, size, nums, combo, combos);
    }

public:
    vector<vector<int>> combine(int n, int k) {
        // Create list
        vector<int> nums;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }

        vector<int> combo;
        vector<vector<int>> combos;
        dfs(0, k, nums, combo, combos);

        return combos;
    }
};