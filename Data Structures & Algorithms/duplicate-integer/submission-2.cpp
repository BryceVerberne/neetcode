class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> numsMap;

        for (const auto& num : nums) {
            if (numsMap.contains(num)) {
                return true;
            }
            else {
                numsMap[num] = 1;
            }
        }

        return false;
    }
};