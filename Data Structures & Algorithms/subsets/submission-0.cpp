class Solution {
private:
    vector<vector<int>> result;
    vector<int> subset;

    void dfs(const vector<int>& nums, int i) {
        if (i >= nums.size()) {
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, i + 1);

        subset.pop_back();
        dfs(nums, i + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return result;
    }
};
