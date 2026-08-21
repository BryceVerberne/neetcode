class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;

        for (const auto& num : nums) {
            if (map.contains(num)) {
                return true;
            }
            else {
                map[num] = 1;
            }
        }

        return false;
    }
};