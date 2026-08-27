class Solution {
void helper(int i, int sum, int target, vector<int>& nums, vector<int>& combo, vector<vector<int>>& combos) {
    if (sum == target) {
        combos.push_back(combo);
        return;
    }

    if (sum > target) {
        return;
    }

    for (int j = i; j < nums.size(); ++j) {
        sum += nums[j];
        combo.push_back(nums[j]);
        helper(j, sum, target, nums, combo, combos);
        sum -= nums[j];
        combo.pop_back();
    }
}

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> combos;
        vector<int> combo;
        helper(0, 0, target, nums, combo, combos);

        return combos;
    }
};
