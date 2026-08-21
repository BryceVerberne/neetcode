class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int size = nums.size();

        for (int i = 0; i < size; ++i) {
            int diff = target - nums[i];
            if (map.contains(diff)) {
                return {map[diff], i};
            }
            map[nums[i]] = i;
        }

        return {};
    }
};
