class Solution {
private:
    void dfs(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& solution) {
        if (i >= nums.size()) {
            solution.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(i+1, nums, subset, solution);

        subset.pop_back();
        dfs(i+1, nums, subset, solution);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> solution;

        dfs(0, nums, subset, solution);
        return solution;
    }
};
