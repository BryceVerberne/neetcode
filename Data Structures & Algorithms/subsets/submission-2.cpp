class Solution {
private:
    vector<vector<int>> solution;

    void dfs(const vector<int>& nums, vector<int>& arr, int index) {
        if (index >= nums.size()) {
            solution.emplace_back(arr);
            return;
        }

        arr.emplace_back(nums[index]);
        dfs(nums, arr, index+1);
        arr.pop_back();

        dfs(nums, arr, index+1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        dfs(nums,arr,0);
        return solution;
    }
};
