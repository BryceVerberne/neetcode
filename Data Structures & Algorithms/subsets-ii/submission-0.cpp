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

        // Reach a non-repeating value
        while (((i + 1) < nums.size()) && (nums[i] == nums[i+1])) {
            ++i;
        }
        dfs(i+1, nums, subset, solution);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> solution;
        vector<int> subset;
        
        sort(nums.begin(), nums.end());
        dfs(0, nums, subset, solution);
        
        return solution;
    }
};
